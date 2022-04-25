#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

/**************************************** Symbol List ****************************************/
typedef struct node
{
	struct node* next;

	union
	{
		int intValue;
		float floatValue;
		char* stringValue;
	} value;

	char type;
	char* id;
	int isConst;
	int isInitialized;
} symbolNode;

typedef struct
{
	symbolNode* head;
	symbolNode* tail;
} symbolList;

symbolList* g_symbolList;

FILE* g_errorFile;
FILE* g_mipsFile;
FILE* g_mipsFileData;
FILE* g_mipsFileText;

extern FILE* yyin;
extern FILE* yyout;

extern int g_line;

char	g_type;
int		g_errorCounter = 0;
int		g_stringCounter = 0;
int		g_jumpCounter = 0;
int		g_dataCounter = 0;
int		g_s_registerNumber = 0;
int		g_hasOrAnd = 0;
int		g_NotFlag = 0;
int		g_continueOperation = 0;
int		g_caseNumber = 0;
int		g_breakCounter = 0;

extern int yylex(void);
extern void yyerror(const char* errorMessage);

/**************************************** File handling functions ****************************************/
void mergeMipsFiles(const char* mipsFileName, const char* mipsDataFileName, const char* mipsTextFileName);
void deleteMipsFiles(const char* mipsFileName, const char* mipsDataFileName, const char* mipsTextFileName);
void mergeErrorAndListingFiles(const char* errorFileName, const char* outputFileName);
void deleteErrorFile(const char* errorFileName);

/**************************************** Symbol list handling functions ****************************************/
void insertIntToList(char* id, int intValue, int isConst, int isInitialized);
void insertFloatToList(char* id, float floatValue, int isConst, int isInitialized);
void insertStringToList(char* id, char* stringValue, int isConst, int isInitialized);

void removeFromList(char* id);
void deleteSymbolList();

symbolNode* getNodeById(char* id);
int doesIdExist(char* id);

void assignIntValue(char* id, int intValue);
void assignFloatValue(char* id, float floatValue);
void assignStringValue(char* id, char* stringValue);

/**************************************** Mips handling function ****************************************/
void insertIntVariableToMips(char* id, int intValue);
void insertFloatVariableToMips(char* id, float floatValue);
void insertStringVariableToMips(char* id, char* stringValue);

void assignToStringMips(char* id, char* stringValue);

void addReadToMips(char* id, char type);
void addOutToMips(char* id, char type, int intValue, float floatValue);

// If and Else functions.
void addComparisonToMips(char* operation, char* id1, char* id2, int intValue1, int intValue2,
	float floatValue1, float floatValue2, char type1, char type2);
void addComparisonValidationStatementToMips();
void addElseStatementToMips();
void addEndIfStatementToMips();
void addAndOrStatementToMips(char* operation);

// While functions.
void addStartWhileStatementToMips();
void addWhileValidationStatementToMips();
void addEndOfWhileStatementToMips();

// Do While functions.
void addStartDoStatementToMips();
void addDoValidationStatementToMips();
void addEndOfDoStatementToMips();

// For Each functions.
void addStartForeachStatementToMips();
void addForeachValidationStatementToMips();
void addEndOfForeachStatementToMips();

// Switch Case functions.
void addSwitchChoiceToMips(char* id, int intValue, float floatValue, char type);
void addSwitchCaseToMips(int intValue, float floatValue, char type);
void addSwitchBreakToMips();
void addSwitchDefaultToMips();
void addSwitchEndToMips();

void addArithmeticOperationToMips(char* operation, char* id1, char* id2, int intValue1, int intValue2,
	float floatValue1, float floatValue2, char type1, char type2);
void addArithmeticOperationContinuationToMips(char* operation, char* id, int intValue, float floatValue, char type);

void addPreperationForAssignmentToMips(char* idToAssign, char typeToAssign, char* id, int intValue, float floatValue, char type);
void addEndAssignmentToMips(char* idToAssign, char typeToAssign);

void addExitToMips();

/**************************************** Error handling functions ****************************************/
void addError_redeclaration(char* id);
void addError_undeclared(char* id);
void addError_assighmentWrongType(char* id, char type);
void addError_const(char* id);
void addError_stringOperation();
void addError_idTooLong();
void addError_unrecognizableCharacters();

int main(int argc, char** argv)
{
	fprintf(stderr, "Lior Sabri, Omri Kellner.\n\n");

	// Argument validation
	if (argc != 2)
	{
		fprintf(stderr, "Error, enter in the following format: 'cpm.exe file.cpl'!\n");
		return 1;
	}

	const char* inputFileName = argv[1];
	const int inputFileLength = strlen(inputFileName);

	// Input file validation.
	if (strcmp(&(inputFileName[inputFileLength - 4]), ".cpl\n") != 0 &&
		strcmp(&(inputFileName[inputFileLength - 4]), ".CPL\n") != 0 &&
		inputFileLength <= 4)
	{
		fprintf(stderr, "Error, input file must be *.cpl or *.CPL!\n");
		return 1;
	}

	// Opening input file for reading.
	fprintf(stderr, "Opening %s for reading...\n", inputFileName);
	yyin = fopen(inputFileName, "r");

	if (yyin == NULL)
	{
		fprintf(stderr, "Error: failed to open %s for reading!\n", inputFileName);
		return 1;
	}

	// Opening output file for writing.
	const char* outputFileName = "listing.lst";

	fprintf(stderr, "Opening %s for writing...\n", outputFileName);
	yyout = fopen(outputFileName, "w");

	if (yyout == NULL)
	{
		fprintf(stderr, "Error: failed to open %s for writing!\n", outputFileName);
		return 1;
	}

	// Opening Error file for writing
	const char* errorFileName = "error.lst";
	g_errorFile = fopen(errorFileName, "w");

	// Creating Mips file.
	const char* mipsFileName = "mips.s";
	const char* mipsDataFileName = "mipsData.s";
	const char* mipsTextFileName = "mipsText.s";

	fprintf(stderr, "Opening %s for writing...\n", mipsFileName);

	g_mipsFile = fopen(mipsFileName, "w");
	g_mipsFileData = fopen(mipsDataFileName, "w");
	g_mipsFileText = fopen(mipsTextFileName, "w");
	
	// Initializing symbol list.
	g_symbolList = (symbolList*)malloc(sizeof(symbolList));
	g_symbolList->head = NULL;
	g_symbolList->tail = NULL;

	// Parsing files.
	fprintf(stderr, "Start parsing %s...\n", inputFileName);

	fprintf(yyout, "Lior Sabri, Omri Kellner.\n\n");
	fprintf(yyout, "%d.\t", g_line++);

	yyparse();

	fprintf(stderr, "Done parsing %s...\n", inputFileName);

	// Checking if any errors exists, if so delete mips file.
	if (g_errorCounter == 0)
	{
		mergeMipsFiles(mipsFileName, mipsDataFileName, mipsTextFileName);
		deleteErrorFile(errorFileName);
	}
	else
	{
		deleteMipsFiles(mipsFileName, mipsDataFileName, mipsTextFileName);
		mergeErrorAndListingFiles(errorFileName, outputFileName);
	}

	// Closing files.
	fprintf(stderr, "Closing files: %s, %s...\n", inputFileName, outputFileName);

	fclose(yyin);
	fclose(yyout);

	deleteSymbolList();
	
	return 0;
}

void mergeMipsFiles(const char* mipsFileName, const char* mipsDataFileName, const char* mipsTextFileName)
{
	fprintf(stderr, "Merging %s and %s into %s...\n", mipsDataFileName, mipsTextFileName, mipsFileName);

	fclose(g_mipsFileData);
	fclose(g_mipsFileText);

	g_mipsFileData = fopen(mipsDataFileName, "r");
	g_mipsFileText = fopen(mipsTextFileName, "r");	

	fprintf(g_mipsFile, "# Lior Sabri, Omri Kellner.\n\n");
	fprintf(g_mipsFile, ".data\n");

	char c;

	while ((c = fgetc(g_mipsFileData)) != EOF)
	{
		fputc(c, g_mipsFile);
	}

	fprintf(g_mipsFile, "\n.text\n");

	while ((c = fgetc(g_mipsFileText)) != EOF)
	{
		fputc(c, g_mipsFile);
	}

	fclose(g_mipsFileData);
	fclose(g_mipsFileText);
	fclose(g_mipsFile);

	remove(mipsDataFileName);
	remove(mipsTextFileName);

	fprintf(stderr, "Done merging files!\n");
}

void deleteMipsFiles(const char* mipsFileName, const char* mipsDataFileName, const char* mipsTextFileName)
{
	fprintf(stderr, "%d errors were found, deleting mips files...\n", g_errorCounter);

	fclose(g_mipsFileData);
	fclose(g_mipsFileText);
	fclose(g_mipsFile);

	remove(mipsDataFileName);
	remove(mipsTextFileName);
	remove(mipsFileName);

	fprintf(stderr, "%s deleted!\n", mipsFileName);
}

void mergeErrorAndListingFiles(const char* errorFileName, const char* outputFileName)
{
	fclose(g_errorFile);
	g_errorFile = fopen(errorFileName, "r");

	fprintf(yyout, "\n%d Errors were found:\n", g_errorCounter);

	char c;

	while ((c = fgetc(g_errorFile)) != EOF)
	{
		fputc(c, yyout);
	}

	fclose(g_errorFile);
	remove(errorFileName);
}

void deleteErrorFile(const char* errorFileName)
{
	fclose(g_errorFile);
	remove(errorFileName);
}

void yyerror(const char* errorMessage)
{
	fprintf(stderr, "%s\n", errorMessage);
	fprintf(g_errorFile, "Line %d.\tError: syntax error!\n", g_line - 1);
	g_errorCounter++;
}

void insertIntToList(char* id, int intValue, int isConst, int isInitialized)
{
	symbolNode* newNode = (symbolNode*)malloc(sizeof(symbolNode));

	newNode->next = NULL;
	newNode->type = 'i';
	newNode->value.intValue = intValue;
	newNode->id = id;
	newNode->isConst = isConst;
	newNode->isInitialized = isInitialized;

	if (g_symbolList->head == NULL)
	{
		g_symbolList->head = newNode;
		g_symbolList->tail = newNode;
	}
	else
	{
		g_symbolList->tail->next = newNode;
		g_symbolList->tail = newNode;
	}
}

void insertFloatToList(char* id, float floatValue, int isConst, int isInitialized)
{
	symbolNode* newNode = (symbolNode*)malloc(sizeof(symbolNode));

	newNode->next = NULL;
	newNode->type = 'f';
	newNode->value.floatValue = floatValue;
	newNode->id = id;
	newNode->isConst = isConst;
	newNode->isInitialized = isInitialized;

	if (g_symbolList->head == NULL)
	{
		g_symbolList->head = newNode;
		g_symbolList->tail = newNode;
	}
	else
	{
		g_symbolList->tail->next = newNode;
		g_symbolList->tail = newNode;
	}
}

void insertStringToList(char* id, char* stringValue, int isConst, int isInitialized)
{
	symbolNode* newNode = (symbolNode*)malloc(sizeof(symbolNode));

	newNode->next = NULL;
	newNode->type = 's';
	newNode->value.stringValue = stringValue;
	newNode->id = id;
	newNode->isConst = isConst;
	newNode->isInitialized = isInitialized;

	if (g_symbolList->head == NULL)
	{
		g_symbolList->head = newNode;
		g_symbolList->tail = newNode;
	}
	else
	{
		g_symbolList->tail->next = newNode;
		g_symbolList->tail = newNode;
	}
}

void removeFromList(char* id)
{
	symbolNode* temporary = g_symbolList->head;

	if (temporary != NULL && strcmp(temporary->id, id) == 0)
	{
		g_symbolList->head = temporary->next;
		free(temporary);

		return;
	}

	symbolNode* previous = NULL;

	while (temporary != NULL && strcmp(temporary->id, id) != 0)
	{
		previous = temporary;
		temporary = temporary->next;
	}

	if (temporary == NULL)
	{
		return;
	}

	previous->next = temporary->next;
	free(temporary);
}

void deleteSymbolList()
{
	symbolNode* nodeToDelete;

	while (g_symbolList->head != NULL)
	{
		nodeToDelete = g_symbolList->head;
		g_symbolList->head = g_symbolList->head->next;

		free(nodeToDelete);
	}

	free(g_symbolList);
}

symbolNode* getNodeById(char* id)
{
	symbolNode* iteratorNode = g_symbolList->head;

	if (id == NULL || iteratorNode == NULL)
	{
		return NULL;
	}

	while (iteratorNode != NULL)
	{
		if (strcmp(iteratorNode->id, id) == 0)
		{
			return iteratorNode;
		}
		else
		{
			iteratorNode = iteratorNode->next;
		}
	}

	return NULL;
}

int doesIdExist(char* id)
{
	if (getNodeById(id) == NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void assignIntValue(char* id, int intValue) 
{
	symbolNode* nodeToAssign = getNodeById(id);

	if (nodeToAssign->isConst)
	{
		addError_const(id);
		return;
	}

	nodeToAssign->value.intValue = intValue;
	nodeToAssign->isInitialized = TRUE;
}

void assignFloatValue(char* id, float floatValue)
{
	symbolNode* nodeToAssign = getNodeById(id);

	if (nodeToAssign->isConst)
	{
		addError_const(id);
		return;
	}

	nodeToAssign->value.floatValue = floatValue;
	nodeToAssign->isInitialized = TRUE;
}

void assignStringValue(char* id, char* stringValue)
{
	symbolNode* nodeToAssign = getNodeById(id);

	if (nodeToAssign->isConst)
	{
		addError_const(id);
		return;
	}

	nodeToAssign->value.stringValue = stringValue;
	nodeToAssign->isInitialized = TRUE;
}

void insertIntVariableToMips(char* id, int intValue)
{
	fprintf(g_mipsFileData, "\t%s:\t.word %d\n", id, intValue);
}

void insertFloatVariableToMips(char* id, float floatValue)
{
	fprintf(g_mipsFileData, "\t%s:\t.float %f\n", id, floatValue);
}

void insertStringVariableToMips(char* id, char* stringValue)
{
	fprintf(g_mipsFileData, "\t%s:\t.space 1000\n", id);

	if (stringValue != NULL)
	{
		assignToStringMips(id, stringValue);
	}
}

void assignToStringMips(char* id, char* stringValue)
{
	fprintf(g_mipsFileData, "\t%s_string:\t.asciiz %s\n", id, stringValue);

	// Load address of first character in string
	fprintf(g_mipsFileText, "\tla\t$t0, %s_string\n", id);
	// Load the address string variable
	fprintf(g_mipsFileText, "\tla\t$t1, %s\n\n", id);

	// Start loop
	fprintf(g_mipsFileText, "\tloop_%s:\n", id);

	// Load the first byte of $t0(id_string) into $t2
	fprintf(g_mipsFileText, "\t\tlbu\t$t2, 0($t0)\n");
	// Save the value in $t2 at the same byte in $t1(id)
	fprintf(g_mipsFileText, "\t\tsb\t$t2, 0($t1)\n");

	// Increment both pointers by 1 byte
	fprintf(g_mipsFileText, "\t\taddi\t$t0, $t0, 1\n");
	fprintf(g_mipsFileText, "\t\taddi\t$t1, $t1, 1\n");

	// while c!=0
	fprintf(g_mipsFileText, "\t\tbne\t$t2, $zero, loop_%s\n\n", id);
}

void addReadToMips(char* id, char type)
{
	switch (type)
	{
	case 'i':
		fprintf(g_mipsFileText, "\tli\t$v0, 5\n");
		fprintf(g_mipsFileText, "\tsyscall\n");
		fprintf(g_mipsFileText, "\tsw\t$v0, %s\n\n", id);
		break;

	case 'f':
		fprintf(g_mipsFileText, "\tli\t$v0, 6\n");
		fprintf(g_mipsFileText, "\tsyscall\n");
		fprintf(g_mipsFileText, "\tswc1\t$f0, %s\n\n", id);
		break;

	case 's':
		fprintf(g_mipsFileText, "\tli\t$v0, 8\n");
		fprintf(g_mipsFileText, "\tla\t$a0, %s\n", id);
		fprintf(g_mipsFileText, "\tli\t$a1, 50\n");
		fprintf(g_mipsFileText, "\tsyscall\n\n");
		break;
	}
}

void addOutToMips(char* id, char type, int intValue, float floatValue)
{
	switch (type)
	{
		case 'i':
			fprintf(g_mipsFileText, "\tli\t$v0, 1\n");

			if (id != NULL)
			{
				fprintf(g_mipsFileText, "\tlw\t$a0, %s\n", id);
			}
			else
			{
				fprintf(g_mipsFileText, "\tli\t$a0, %d\n", intValue); 
			}

			fprintf(g_mipsFileText, "\tsyscall\n\n");
			break;

		case 'f':
			fprintf(g_mipsFileText, "\tli\t$v0, 2\n");

			if (id != NULL)
			{
				fprintf(g_mipsFileText, "\tl.s\t$f12, %s\n", id);
			}
			else
			{
				fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue);
				fprintf(g_mipsFileText, "\tl.s\t$f12, floatConst_%d\n", g_dataCounter++);
			}
			
			fprintf(g_mipsFileText, "\tsyscall\n\n");
			break;
	
		case 's':
			fprintf(g_mipsFileText, "\tli\t$v0, 4\n");
			fprintf(g_mipsFileText, "\tla\t$a0, %s\n", id);
			fprintf(g_mipsFileText, "\tsyscall\n\n");
			break;
	
		case 'e':
			fprintf(g_mipsFileData, "\tstring_%d:\t.asciiz %s\n", g_stringCounter++, id);
			fprintf(g_mipsFileText, "\tli\t$v0, 4\n");
			fprintf(g_mipsFileText, "\tla\t$a0, string_%d\n", g_stringCounter);
			fprintf(g_mipsFileText, "\tsyscall\n\n");
	}
}

void addComparisonToMips(char* operation, char* id1, char* id2, int intValue1, int intValue2,
	float floatValue1, float floatValue2, char type1, char type2)
{
	if (id1 != NULL && id2 != NULL)
	{
		if (type1 == 'i' && type2 == 'i')
		{
			fprintf(g_mipsFileText, "\tlw\t$t1, %s\n", id1);
			fprintf(g_mipsFileText, "\tlw\t$t2, %s\n", id2);

			fprintf(g_mipsFileText, "\ts%s\t$s%d, $t1, $t2\n\n", operation, g_s_registerNumber);

			if (g_NotFlag)
			{
				fprintf(g_mipsFileText, "\txor\t$s%d, 1\n", g_s_registerNumber);
				g_NotFlag = FALSE;
			}

			g_s_registerNumber = !g_s_registerNumber;

			return;
		}
		else if (type1 == 'f' && type2 == 'f')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f0, %s\n", id1);
			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id2);
		}
		else if (type1 == 'i' && type2 == 'f')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f0, %s\n", id1);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f0, $f0\n");

			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id2);
		}
		else // (type1 == 'f' && type2 == 'i')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f0, %s\n", id1);

			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id2);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
		}
	}
	else if (id1 == NULL && id2 == NULL)
	{
		if (type1 == 'i' && type2 == 'i')
		{
			fprintf(g_mipsFileText, "\tli\t$t1, %d\n", intValue1);
			fprintf(g_mipsFileText, "\tli\t$t2, %d\n", intValue2);

			fprintf(g_mipsFileText, "\ts%s\t$s%d, $t1, $t2\n\n", operation, g_s_registerNumber);

			if (g_NotFlag)
			{
				fprintf(g_mipsFileText, "\txor\t$s%d, 1\n", g_s_registerNumber);
				g_NotFlag = FALSE;
			}

			g_s_registerNumber = !g_s_registerNumber;

			return;
		}
		else if (type1 == 'f' && type2 == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f0, floatConst_%d\n", g_dataCounter++);

			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f1, floatConst_%d\n", g_dataCounter++);
		}
		else if (type1 == 'i' && type2 == 'f')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f0, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f0, $f0\n");

			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f1, floatConst_%d\n", g_dataCounter++);
		}
		else // (type1 == 'f' && type2 == 'i')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f0, floatConst_%d\n", g_dataCounter++);

			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f1, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
		}
	}
	else if (id1 != NULL && id2 == NULL)
	{
		fprintf(g_mipsFileText, "\tl.s\t$f0, %s\n", id1);

		if (type1 == 'i')
		{
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f0, $f0\n");
		}

		if (type2 == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f1, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
		}
		else // (type2 == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f1, floatConst_%d\n", g_dataCounter++);
		}
	}
	else // (id1 == NULL && id2 != NULL)
	{
		if (type1 == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f0, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f0, $f0\n");
		}
		else // (type1 == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f0, floatConst_%d\n", g_dataCounter++);
		}

		fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id2);

		if (type2 == 'i')
		{
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
		}
	}

	if (strcmp("ne", operation) == 0)
	{
		fprintf(g_mipsFileText, "\tc.eq.s\t$f0, $f1\n");
		fprintf(g_mipsFileText, "\tbc1f\tstart_%d\n\n", g_jumpCounter);
	}
	else if (strcmp("gt", operation) == 0)
	{
		fprintf(g_mipsFileText, "\tc.le.s\t$f0, $f1\n");
		fprintf(g_mipsFileText, "\tbc1f\tstart_%d\n\n", g_jumpCounter);
	}
	else if (strcmp("ge", operation) == 0)
	{
		fprintf(g_mipsFileText, "\tc.lt.s\t$f0, $f1\n");
		fprintf(g_mipsFileText, "\tbc1f\tstart_%d\n\n", g_jumpCounter);
	}
	else
	{
		fprintf(g_mipsFileText, "\tc.%s.s\t$f0, $f1\n", operation);
		fprintf(g_mipsFileText, "\tbc1t\tstart_%d\n\n", g_jumpCounter);
	}

	fprintf(g_mipsFileText, "\tli\t$s%d, 0\n", g_s_registerNumber);
	fprintf(g_mipsFileText, "\tj\tbeqz_%d\n\n", g_jumpCounter);

	fprintf(g_mipsFileText, "\tstart_%d:\n", g_jumpCounter);
	fprintf(g_mipsFileText, "\tli\t$s%d, 1\n\n", g_s_registerNumber);

	fprintf(g_mipsFileText, "\tbeqz_%d:\n", g_jumpCounter++);

	if (g_NotFlag)
	{
		fprintf(g_mipsFileText, "\txor\t$s%d, 1\n", g_s_registerNumber);
		g_NotFlag = FALSE;
	}

	g_s_registerNumber = !g_s_registerNumber;
}

void addComparisonValidationStatementToMips()
{
	g_s_registerNumber = !g_s_registerNumber;
	fprintf(g_mipsFileText, "\tbeqz\t$s%d, else_%d\n\n", g_hasOrAnd, g_jumpCounter);
	g_hasOrAnd = 0;
}

void addElseStatementToMips()
{
	fprintf(g_mipsFileText, "\tj\tend_%d\n\n", g_jumpCounter);
	fprintf(g_mipsFileText, "\telse_%d:\n", g_jumpCounter);
}

void addEndIfStatementToMips()
{
	fprintf(g_mipsFileText, "\tend_%d:\n", g_jumpCounter++);
}

void addAndOrStatementToMips(char* operation)
{
	fprintf(g_mipsFileText, "\t%s\t$s2, $s0, $s1\n", operation);
	fprintf(g_mipsFileText, "\tmove\t$s1, $s2\n\n");
	g_hasOrAnd = 2;
}

void addStartWhileStatementToMips()
{
	fprintf(g_mipsFileText, "\twhile_%d:\n", g_jumpCounter);
}

void addWhileValidationStatementToMips()
{
	g_s_registerNumber = !g_s_registerNumber;
	fprintf(g_mipsFileText, "\tbeqz\t$s%d, end_while_%d\n\n", g_hasOrAnd, g_jumpCounter);
	g_hasOrAnd = 0;
}

void addEndOfWhileStatementToMips()
{
	fprintf(g_mipsFileText, "\tj\twhile_%d\n\n", g_jumpCounter);
	fprintf(g_mipsFileText, "\tend_while_%d:\n", g_jumpCounter++);
}

void addStartDoStatementToMips()
{
	fprintf(g_mipsFileText, "\tdo_while_%d:\n", g_jumpCounter);
}

void addDoValidationStatementToMips()
{
	g_s_registerNumber = !g_s_registerNumber;
	fprintf(g_mipsFileText, "\tbeqz\t$s%d, end_do_%d\n\n", g_hasOrAnd, g_jumpCounter);
	g_hasOrAnd = 0;
}

void addEndOfDoStatementToMips()
{
	fprintf(g_mipsFileText, "\tj\tdo_while_%d\n\n", g_jumpCounter);
	fprintf(g_mipsFileText, "\tend_do_%d:\n", g_jumpCounter++);
}

void addStartForeachStatementToMips()
{
	fprintf(g_mipsFileText, "\tforeach_%d:\n", g_jumpCounter);
}

void addForeachValidationStatementToMips()
{
	g_s_registerNumber = !g_s_registerNumber;
	fprintf(g_mipsFileText, "\tbeqz\t$s%d, end_foreach_%d\n\n", g_hasOrAnd, g_jumpCounter);
	g_hasOrAnd = 0;
}

void addEndOfForeachStatementToMips()
{
	fprintf(g_mipsFileText, "\tj\tforeach_%d\n\n", g_jumpCounter);
	fprintf(g_mipsFileText, "\tend_foreach_%d:\n", g_jumpCounter++);
}

void addSwitchChoiceToMips(char* id, int intValue, float floatValue, char type)
{
	if (id != NULL)
	{
		fprintf(g_mipsFileText, "\tl.s\t$f24, %s\n", id);
		
		if (type == 'i')
		{
			fprintf(g_mipsFileText, "\tcvt.w.s\t$f24, $f24\n");
		}
	}
	else // (id == NULL)
	{
		if (type == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue);
			fprintf(g_mipsFileText, "\tl.s\t$f24, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f24, $f24\n");
		}
		else // (type == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue);
			fprintf(g_mipsFileText, "\tl.s\t$f24, floatConst_%d\n", g_dataCounter++);
		}
	}
}

void addSwitchCaseToMips(int intValue, float floatValue, char type)
{
	fprintf(g_mipsFileText, "\tcase_%d:\n", g_caseNumber++);

	if (type == 'i')
	{
		fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue);
		fprintf(g_mipsFileText, "\tl.s\t$f25, wordConst_%d\n", g_dataCounter++);
		fprintf(g_mipsFileText, "\tcvt.s.w\t$f25, $f25\n");
	}
	else // (type == 'f')
	{
		fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue);
		fprintf(g_mipsFileText, "\tl.s\t$f25, floatConst_%d\n", g_dataCounter++);
	}

	fprintf(g_mipsFileText, "\tc.eq.s\t$f24, $f25\n");
	fprintf(g_mipsFileText, "\tbc1t\tstart_%d\n\n", g_jumpCounter);

	fprintf(g_mipsFileText, "\tli\t$s7, 0\n");
	fprintf(g_mipsFileText, "\tj\tbeqz_%d\n\n", g_jumpCounter);

	fprintf(g_mipsFileText, "\tstart_%d:\n", g_jumpCounter);
	fprintf(g_mipsFileText, "\tli\t$s7, 1\n\n");

	fprintf(g_mipsFileText, "\tbeqz_%d:\n", g_jumpCounter++);
	fprintf(g_mipsFileText, "\tbeqz\t$s7, case_%d\n\n", g_caseNumber);
}

void addSwitchBreakToMips()
{
	fprintf(g_mipsFileText, "\tj\tbreak_switch_%d\n\n", g_breakCounter);
}

void addSwitchDefaultToMips()
{
	fprintf(g_mipsFileText, "\tcase_%d:\n", g_caseNumber++);
}

void addSwitchEndToMips()
{
	fprintf(g_mipsFileText, "\tbreak_switch_%d:\n", g_breakCounter++);
}

void addArithmeticOperationToMips(char* operation, char* id1, char* id2, int intValue1, int intValue2,
	float floatValue1, float floatValue2, char type1, char type2)
{
	if (id1 != NULL && id2 != NULL)
	{
		if (type1 == 'i' && type2 == 'i')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id1);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");

			fprintf(g_mipsFileText, "\tl.s\t$f2, %s\n", id2);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f2, $f2\n");
		}
		else if (type1 == 'f' && type2 == 'f')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id1);
			fprintf(g_mipsFileText, "\tl.s\t$f2, %s\n", id2);
		}
		else if (type1 == 'i' && type2 == 'f')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id1);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");

			fprintf(g_mipsFileText, "\tl.s\t$f2, %s\n", id2);
		}
		else // (type1 == 'f' && type2 == 'i')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id1);

			fprintf(g_mipsFileText, "\tl.s\t$f2, %s\n", id2);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f2, $f2\n");
		}
	}
	else if (id1 == NULL && id2 == NULL)
	{
		if (type1 == 'i' && type2 == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f1, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
			
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f2, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f2, $f2\n");
		}
		else if (type1 == 'f' && type2 == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f1, floatConst_%d\n", g_dataCounter++);

			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f2, floatConst_%d\n", g_dataCounter++);
		}
		else if (type1 == 'i' && type2 == 'f')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f1, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");

			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f2, floatConst_%d\n", g_dataCounter++);
		}
		else // (type1 == 'f' && type2 == 'i')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f1, floatConst_%d\n", g_dataCounter++);

			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f2, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f2, $f2\n");
		}
	}
	else if (id1 != NULL && id2 == NULL)
	{
		fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id1);

		if (type1 == 'i')
		{
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
		}

		if (type2 == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f2, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f2, $f2\n");
		}
		else // (type2 == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue2);
			fprintf(g_mipsFileText, "\tl.s\t$f2, floatConst_%d\n", g_dataCounter++);
		}
	}
	else if (id1 == NULL && id2 != NULL)
	{
		if (type1 == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f1, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
		}
		else // (type1 == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue1);
			fprintf(g_mipsFileText, "\tl.s\t$f1, floatConst_%d\n", g_dataCounter++);
		}

		fprintf(g_mipsFileText, "\tl.s\t$f2, %s\n", id2);

		if (type2 == 'i')
		{
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f2, $f2\n");
		}
	}

	fprintf(g_mipsFileText, "\t%s.s\t$f2, $f1, $f2\n\n", operation);

	g_continueOperation = TRUE;
}

void addArithmeticOperationContinuationToMips(char* operation, char* id, int intValue, float floatValue, char type)
{
	if (id != NULL)
	{
		if (type == 'i')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
		}
		else // (type == 'f')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f1, %s\n", id);
		}
	}
	else // (id == NULL)
	{
		if (type == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue);
			fprintf(g_mipsFileText, "\tl.s\t$f1, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f1, $f1\n");
		}
		else // (type == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue);
			fprintf(g_mipsFileText, "\tl.s\t$f1, floatConst_%d\n", g_dataCounter++);
		}
	}

	fprintf(g_mipsFileText, "\t%s.s\t$f2, $f1, $f2\n\n", operation);
}

void addPreperationForAssignmentToMips(char* idToAssign, char typeToAssign, char* id, int intValue, float floatValue, char type)
{
	if (id != NULL)
	{
		if (typeToAssign == 'i' && type == 'i')
		{
			fprintf(g_mipsFileText, "\tlw\t$f2, %s\n", id);
		}
		else if (typeToAssign == 'f' && type == 'f')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f2, %s\n", id);
		}
		else if (typeToAssign == 'i' && type == 'f')
		{
			fprintf(g_mipsFileText, "\tl.s\t$f2, %s\n", id);
			fprintf(g_mipsFileText, "\tcvt.w.s\t$f2, $f2\n");
		}
		else // (typeToAssign == 'f' && type == 'i')
		{
			fprintf(g_mipsFileText, "\tlw\t$f2, %s\n", id);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f2, $f2\n");
		}
	}
	else // (id == NULL)
	{
		if (typeToAssign == 'i' && type == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue);
			fprintf(g_mipsFileText, "\tl.s\t$f2, wordConst_%d\n", g_dataCounter++);
		}
		else if (typeToAssign == 'f' && type == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue);
			fprintf(g_mipsFileText, "\tl.s\t$f2, floatConst_%d\n", g_dataCounter++);
		}
		else if (typeToAssign == 'i' && type == 'f')
		{
			fprintf(g_mipsFileData, "\tfloatConst_%d:\t.float %f\n", g_dataCounter, floatValue);
			fprintf(g_mipsFileText, "\tl.s\t$f2, floatConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.w.s\t$f2, $f2\n");
		}
		else // (typeToAssign == 'f' && type == 'i')
		{
			fprintf(g_mipsFileData, "\twordConst_%d:\t.word %d\n", g_dataCounter, intValue);
			fprintf(g_mipsFileText, "\tl.s\t$f2, wordConst_%d\n", g_dataCounter++);
			fprintf(g_mipsFileText, "\tcvt.s.w\t$f2, $f2\n");
		}
	}

	addEndAssignmentToMips(idToAssign, typeToAssign);
}

void addEndAssignmentToMips(char* idToAssign, char typeToAssign)
{

	if (typeToAssign == 'i' && g_continueOperation)
	{
		fprintf(g_mipsFileText, "\tcvt.w.s\t$f2, $f2\n");
	}

	fprintf(g_mipsFileText, "\ts.s\t$f2, %s\n\n", idToAssign);

	g_continueOperation = FALSE;
}

void addExitToMips()
{
	fprintf(g_mipsFileText, "\tli\t$v0, 10\n");
	fprintf(g_mipsFileText, "\tsyscall\n\n");
}

void addError_redeclaration(char* id)
{
	fprintf(g_errorFile, "Line %d.\tError: redeclaration of %s!\n", g_line - 1, id);
	g_errorCounter++;
}

void addError_undeclared(char* id)
{
	fprintf(g_errorFile, "Line %d.\tError: '%s' undeclared!\n", g_line - 1, id);
	g_errorCounter++;
}

void addError_assighmentWrongType(char* id, char type)
{
	fprintf(g_errorFile, "Line %d.\tError: assigment to expression with %s type, '%s'!\n", g_line - 1,
		(type == 's' ? "string" : (type == 'i' ? "int" : "float")), id);
	g_errorCounter++;
}

void addError_const(char* id)
{
	fprintf(g_errorFile, "Line %d.\tError: assigment of read-only variable, '%s'!\n", g_line - 1, id);
	g_errorCounter++;
}

void addError_stringOperation()
{
	fprintf(g_errorFile, "Line %d.\tError: operation of string type!\n", g_line - 1);
	g_errorCounter++;
}

void addError_idTooLong()
{
	fprintf(g_errorFile, "Line %d.\tError: maximum length of ID is 9!\n", g_line - 1);
	g_errorCounter++;
}

void addError_unrecognizableCharacters()
{
	fprintf(g_errorFile, "Line %d.\tError: unrecognizable characters!\n", g_line - 1);
	g_errorCounter++;
}