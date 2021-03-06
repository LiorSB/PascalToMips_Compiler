%{
	#include "cpm.c"
%}

%union 
{
	struct 
	{
		char	type;
		char*	id;

		union
		{
			float	floatValue;
			int	intValue;
			char*	stringValue;
		} value;
	} variable;

	enum { EQ, NE, LT, GT, GE, LE, ADD, SUB, MUL, DIV, ASSIGN, OR, AND } operation;

	char type;
}

%token <operation> _relop
%token <operation> _addop
%token <operation> _mulop
%token <operation> _assignop
%token <operation> _orop
%token <operation> _andop
%token <operation> _andorop

%token <variable> _number
%token <variable> _id
%token <variable> _sentence

%token _bgn
%token _break
%token _case
%token _final
%token _default
%token _do
%token _else
%token _end
%token _foreach
%token _if
%token _int
%token _let
%token _out
%token _program
%token _real
%token _read
%token _string
%token _switch
%token _till
%token _var
%token _while
%token _with

%start PROGRAM

%type <type> TYPE

%type <variable> EXPRESSION
%type <variable> TERM
%type <variable> FACTOR

%left _addop
%left _mulop
%left _orop
%left _andop
%left _andorop
%left _relop
%right _assignop

%% 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
PROGRAM:		_program _id _bgn DECLARATIONS STMTLIST _end
			{
				addExitToMips();
			}

			| error '\n'
			{
				yyerrok;  
				yyclearin;
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DECLARATIONS:		 _let DECLARLIST CDECL

			|
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DECLARLIST:		DECLARLIST DECL

			| DECL
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DECL:			TYPE
			{
				g_type = $1;
			}
			':' LIST
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LIST:			_id',' LIST
			{	
				if (doesIdExist($1.id))
				{	
					addError_redeclaration($1.id);
				}
				else
				{
				
					switch (g_type)
					{
						case 'i':
							insertIntToList($1.id, 0, FALSE, FALSE);
							insertIntVariableToMips($1.id, 0);
							break;

						case 'f':
							insertFloatToList($1.id, 0.0, FALSE, FALSE);
							insertFloatVariableToMips($1.id, 0.0);
							break;

						case 's':
							insertStringToList($1.id, NULL, FALSE, FALSE);
							insertStringVariableToMips($1.id, NULL);
							break;
					}
				}
			}

			| _id';'
			{	
				if (doesIdExist($1.id))
				{	
					addError_redeclaration($1.id);
				}
				else
				{
					switch (g_type)
					{
						case 'i':
							insertIntToList($1.id, 0, FALSE, FALSE);
							insertIntVariableToMips($1.id, 0);
							break;

						case 'f':
							insertFloatToList($1.id, 0.0, FALSE, FALSE);
							insertFloatVariableToMips($1.id, 0.0);
							break;

						case 's':
							insertStringToList($1.id, NULL, FALSE, FALSE);
							insertStringVariableToMips($1.id, NULL);
							break;
					}
				}
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TYPE:			_int
			{
				$$ = 'i';
			}

			| _real
			{
				$$ = 'f';
			}

			| _string
			{
				$$ = 's';
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CDECL:			_final TYPE _id _assignop _number';' CDECL
			{
				if (doesIdExist($3.id))
				{	
					addError_redeclaration($3.id);
				}
				else
				{
					if ($2 == 'i')
					{
						if ($5.type == 'i')
						{
							insertIntVariableToMips($3.id, $5.value.intValue);
							insertIntToList($3.id, $5.value.intValue, TRUE, TRUE);
						}
						else // ($5.type == 'f')
						{
							int intValue = (int)$5.value.floatValue;

							insertIntVariableToMips($3.id, intValue);
							insertIntToList($3.id, intValue, TRUE, TRUE);
						}
					}
					else // $2 == 'f'
					{
						if ($5.type == 'i')
						{	
							float floatValue = (float)$5.value.intValue;

							insertFloatVariableToMips($3.id, floatValue);
							insertFloatToList($3.id, floatValue, TRUE, TRUE);
						}
						else // ($5.type == 'f')
						{
							insertFloatVariableToMips($3.id, $5.value.floatValue);
							insertFloatToList($3.id, $5.value.floatValue, TRUE, TRUE);
						}
					}
				}
			}

			| _final TYPE _id _assignop _sentence';' CDECL
			{
				if (doesIdExist($3.id))
				{	
					addError_redeclaration($3.id);
				}
				else
				{
					insertStringToList($3.id, $5.value.stringValue, TRUE, TRUE);
					insertStringVariableToMips($3.id, $5.value.stringValue);
				}
			}

			|
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STMTLIST:		STMTLIST STMT
			|
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STMT:			ASSIGNMENT_STMT

			| _id _assignop _sentence';'
			{
				symbolNode* node = getNodeById($1.id);

				if (node == NULL)
				{
					addError_undeclared($1.id);
				}
				else if (node->type != 's')
				{
					addError_assighmentWrongType(node->id, node->type);
				}
				else if (node->isConst)
				{
					addError_const($1.id);
				}
				else
				{
					assignStringValue($1.id, $3.value.stringValue);
					assignToStringMips($1.id, $3.value.stringValue);
				}
			}

			| CONTROL_STMT

			| READ_STMT

			| OUT_STMT

			| STMT_BLOCK
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
OUT_STMT:		_out'('EXPRESSION')'';'
			{
				symbolNode* node = getNodeById($3.id);
				
				if ($3.id != NULL && !node->isInitialized)
				{
					addError_undeclared($3.id);
				}
				else
				{
					if ($3.id == NULL)
					{
						switch ($3.type)
						{	
							case 'i':
								addOutToMips(NULL, 'i', $3.value.intValue, $3.value.floatValue);
								break;

							case 'f':
								addOutToMips(NULL, 'f', $3.value.intValue, $3.value.floatValue);
								break;

							case 's':
								addOutToMips(NULL, 's', $3.value.intValue, $3.value.floatValue);
								break;
						}
					}
					else
					{
						switch (node->type)
						{	
							case 'i':
								addOutToMips(node->id, 'i', 0, 0.0);
								break;

							case 'f':
								addOutToMips(node->id, 'f', 0, 0.0);
								break;

							case 's':
								addOutToMips(node->id, 's', 0, 0.0);
								break;
						}
					}
				}
			}

			| _out'('_sentence')'';'
			{
				addOutToMips($3.value.stringValue, 'e', 0, 0.0);
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
READ_STMT:		_read'('_id')'';'
			{
				symbolNode* node = getNodeById($3.id);
				
				if (node == NULL)
				{
					addError_undeclared($3.id);
				}
				else
				{
					switch (node->type)
					{
						case 'i':
							addReadToMips(node->id, 'i');
							node->isInitialized = TRUE;
							break;

						case 'f':
							addReadToMips(node->id, 'f');
							node->isInitialized = TRUE;
							break;

						case 's':
							addReadToMips(node->id, 's');
							node->isInitialized = TRUE;
							break;
					}
				}
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ASSIGNMENT_STMT:	_id _assignop EXPRESSION';'
			{
				symbolNode* node = getNodeById($1.id);

				if (node == NULL)
				{
					addError_undeclared($1.id);
				}
				else if (node->type == 's')
				{
					addError_assighmentWrongType(node->id, node->type);
				}
				else if (node->isConst)
				{
					addError_const(node->id);
				}
				else
				{
					symbolNode* nodeExpression = getNodeById($3.id);
				

					if ($3.id != NULL && nodeExpression == NULL)
					{
						addError_undeclared($3.id);
					}
					else if ($3.id != NULL && nodeExpression->type == 's')
					{
						addError_assighmentWrongType(nodeExpression->id, nodeExpression->type);
					}
					else
					{
						if (g_continueOperation)
						{
							addEndAssignmentToMips(node->id, node->type);
						}
						else
						{
							addPreperationForAssignmentToMips(node->id, node->type, $3.id, $3.value.intValue, $3.value.floatValue, $3.type);
						}

						
						if (node->type == 'i')
						{
							assignIntValue($1.id, $3.value.intValue);
						}
						else
						{
							assignFloatValue($1.id, $3.value.floatValue);
						}
					}
				}
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CONTROL_STMT:		_if '('BOOLEXPRESSION')'
			{
				addComparisonValidationStatementToMips();
			}
			STMT _else
			{
				addElseStatementToMips();
			}
			STMT
			{
				addEndIfStatementToMips();
			}

			| _while
			{
				addStartWhileStatementToMips();
			}
			'('BOOLEXPRESSION')'
			{
				addWhileValidationStatementToMips();
			}
			STMT_BLOCK
			{
				addEndOfWhileStatementToMips();
			}

			| _foreach _id _assignop _number':'_number
			{
				insertIntToList($2.id, $4.value.intValue, FALSE, TRUE);
				insertIntVariableToMips($2.id, $4.value.intValue);

				addStartForeachStatementToMips();
				addComparisonToMips("ne", $2.id, NULL, $2.value.intValue, $6.value.intValue, $2.value.floatValue, $6.value.floatValue, 'i', $6.type);
				addForeachValidationStatementToMips();
			}
			_with STEP STMT
			{
				addEndOfForeachStatementToMips();
			}

			| _foreach _id _assignop _number':'_id
			{
				insertIntToList($2.id, $4.value.intValue, FALSE, TRUE);
				insertIntVariableToMips($2.id, $4.value.intValue);

				addStartForeachStatementToMips();
				addComparisonToMips("ne", $2.id, $6.id, $2.value.intValue, $6.value.intValue, $2.value.floatValue, $6.value.floatValue, 'i', $6.type);
				addForeachValidationStatementToMips();
			}
			_with STEP STMT
			{
				addEndOfForeachStatementToMips();
				removeFromList($2.id);
			}

			| _do
			{
				addStartDoStatementToMips();
			}
			STMT_BLOCK _till '('BOOLEXPRESSION')'
			{
				addDoValidationStatementToMips();
				addEndOfDoStatementToMips();
			}

			| SWITCH
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STMT_BLOCK:		'{' STMTLIST '}'
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SWITCH:			_switch '('CHOICE')' '{' CASES '}'
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CHOICE:			_id
			{
				addSwitchChoiceToMips($1.id, 0, 0.0, $1.type);
			}

			| _number
			{
				addSwitchChoiceToMips(NULL, $1.value.intValue, $1.value.floatValue, $1.type);
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
CASES:			_case _number':'
			{
				addSwitchCaseToMips($2.value.intValue, $2.value.floatValue, $2.type);
			}
			STMTLIST _break';'
			{
				addSwitchBreakToMips();
			}
			CASES

			| _default':'
			{
				addSwitchDefaultToMips();
			}
			STMTLIST
			{
				addSwitchEndToMips();
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
STEP:			_id _assignop _id _addop _number
			{
				if ($4 = ADD)
				{
					addArithmeticOperationToMips("add", $3.id, NULL, $3.value.intValue, $5.value.intValue, $3.value.floatValue, $5.value.floatValue, 'i', $5.type);
					addEndAssignmentToMips($1.id, 'i');
				}
				else //($4 == SUB)
				{
					addArithmeticOperationToMips("sub", $3.id, NULL, $3.value.intValue, $5.value.intValue, $3.value.floatValue, $5.value.floatValue, 'i', $5.type);
					addEndAssignmentToMips($1.id, 'i');
				}
			}

			| _id _assignop _id _mulop _number
			{
				if ($4 = MUL)
				{
					addArithmeticOperationToMips("mul", $3.id, NULL, $3.value.intValue, $5.value.intValue, $3.value.floatValue, $5.value.floatValue, 'i', $5.type);
					addEndAssignmentToMips($1.id, 'i');
				}
				else //($4 == DIV)
				{
					addArithmeticOperationToMips("div", $3.id, NULL, $3.value.intValue, $5.value.intValue, $3.value.floatValue, $5.value.floatValue, 'i', $5.type);
					addEndAssignmentToMips($1.id, 'i');
				}
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOLEXPRESSION:		BOOLEXPRESSION _andorop BOOLFACTOR
			{
				if ($2 == AND)
				{
					addAndOrStatementToMips("and");
				}
				else // ($2 == OR)
				{
					addAndOrStatementToMips("or");
				}
			}

			| BOOLFACTOR _andorop BOOLFACTOR
			{
				if ($2 == AND)
				{
					addAndOrStatementToMips("and");
				}
				else // ($2 == OR)
				{
					addAndOrStatementToMips("or");
				}
			}

			| BOOLFACTOR
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOLFACTOR:		'!'
			{
				g_NotFlag = TRUE;
			}
			'('BOOLFACTOR')'
			{
				g_NotFlag = FALSE;	
			}

			| EXPRESSION _relop EXPRESSION
			{
				if ($1.type == 's' || $3.type == 's')
				{
					addError_stringOperation();
				}
				else
				{
					switch ($2)
					{
						case EQ:	// ==
							addComparisonToMips("eq", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);
							break;
	
						case NE:	// !=
							addComparisonToMips("ne", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);	
							break;
		
						case LT:	// <
							addComparisonToMips("lt", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);	
							break;
	
						case GT:	// >
							addComparisonToMips("gt", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);	
							break;
	
						case GE:	// >=
							addComparisonToMips("ge", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);
							break;
		
						case LE:	// <=
							addComparisonToMips("le", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);	
							break;
					}
				}
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EXPRESSION:		EXPRESSION _addop TERM
			{
				symbolNode* node1 = getNodeById($1.id);
				symbolNode* node2 = getNodeById($3.id);


				if ($1.type == 's' || $3. type == 's')
				{
					addError_stringOperation();
				}
				else if ($1.id != NULL && !node1->isInitialized)
				{
					addError_undeclared($1.id);
				}
				else if ($3.id != NULL && !node2->isInitialized)
				{
					addError_undeclared($3.id);
				}
				else
				{
					if ($2 == ADD)
					{
						if (g_continueOperation)
						{
							addArithmeticOperationContinuationToMips("add", $3.id, $3.value.intValue, $3.value.floatValue, $3.type);
						}
						else
						{
							addArithmeticOperationToMips("add", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);
						}

						if ($1.type == 'i' && $3.type == 'i')
						{
							$$.type = 'i';
							$$.value.intValue = $1.value.intValue + $3.value.intValue;
						}
						else
						{
							$$.type = 'f';
							$$.value.floatValue = ($1.type == 'i' ? $1.value.intValue : $1.value.floatValue) + ($3.type == 'i' ? $3.value.intValue : $3.value.floatValue);
						}
					}
					else // ($2 == SUB)
					{
						if (g_continueOperation)
						{
							addArithmeticOperationContinuationToMips("sub", $1.id, $1.value.intValue, $1.value.floatValue, $1.type);
						}
						else
						{
							addArithmeticOperationToMips("sub", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);
						}

						if ($1.type == 'i' && $3.type == 'i')
						{
							$$.type = 'i';
							$$.value.intValue = $1.value.intValue - $3.value.intValue;
						}
						else
						{
							$$.type = 'f';
							$$.value.floatValue = ($1.type == 'i' ? $1.value.intValue : $1.value.floatValue) - ($3.type == 'i' ? $3.value.intValue : $3.value.floatValue);
						}
					}
				}
			}

			| TERM
			{
				$$ = $1;
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TERM:			TERM _mulop FACTOR
			{
				symbolNode* node1 = getNodeById($1.id);
				symbolNode* node2 = getNodeById($3.id);


				if ($1.type == 's' || $3. type == 's')
				{
					addError_stringOperation();
				}
				else if ($1.id != NULL && !node1->isInitialized)
				{
					addError_undeclared($1.id);
				}
				else if ($3.id != NULL && !node2->isInitialized)
				{
					addError_undeclared($3.id);
				}
				else
				{
					if ($2 == MUL)
					{
						if (g_continueOperation)
						{
							addArithmeticOperationContinuationToMips("mul", $1.id, $1.value.intValue, $1.value.floatValue, $1.type);
						}
						else
						{
							addArithmeticOperationToMips("mul", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);
						}

						if ($1.type == 'i' && $3.type == 'i')
						{
							$$.type = 'i';
							$$.value.intValue = $1.value.intValue * $3.value.intValue;
						}
						else
						{
							$$.type = 'f';
							$$.value.floatValue = ($1.type == 'i' ? $1.value.intValue : $1.value.floatValue) * ($3.type == 'i' ? $3.value.intValue : $3.value.floatValue);
						}
					}
					else // ($2 == DIV)
					{
						if (g_continueOperation)
						{
							addArithmeticOperationContinuationToMips("div", $1.id, $1.value.intValue, $1.value.floatValue, $1.type);
						}
						else
						{
							addArithmeticOperationToMips("div", $1.id, $3.id, $1.value.intValue, $3.value.intValue, $1.value.floatValue, $3.value.floatValue, $1.type, $3.type);
						}

						if ($1.type == 'i' && $3.type == 'i')
						{
							$$.type = 'i';
							$$.value.intValue = $1.value.intValue * $3.value.intValue;
						}
						else
						{
							$$.type = 'f';
							$$.value.floatValue = ($1.type == 'i' ? $1.value.intValue : $1.value.floatValue) * ($3.type == 'i' ? $3.value.intValue : $3.value.floatValue);
						}
					}
				}
			}

			| FACTOR
			{
				$$ = $1;
			}
;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FACTOR:			'(' EXPRESSION ')'
			{
				$$ = $2;
			}

			| _id
			{
				symbolNode* node = getNodeById($1.id);

				if (node == NULL)
				{
					addError_undeclared($1.id);
				}
				else
				{
					$$.id = $1.id;

					switch (node->type)
					{
						case 'i':
							$$.type = 'i';
							$$.value.intValue = $1.value.intValue;
							break;

						case 'f':
							$$.type = 'f';
							$$.value.floatValue = $1.value.floatValue;
							break;

						case 's':
							$$.type = 's';
							$$.value.stringValue = $1.value.stringValue;
							break;
					}
				}
			}

			| _number
			{
				$$.id = NULL;

				if ($1.type == 'i')
				{
					$$.type = 'i';
					$$.value.intValue = $1.value.intValue;
				}
				else
				{
					$$.type = 'f';
					$$.value.floatValue = $1.value.floatValue;
				}
			}
;			
%%