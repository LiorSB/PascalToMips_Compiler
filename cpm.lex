%option noyywrap

%{
	#include "y.tab.h"

	extern	int atoi (const char *);
	extern	double atof(const char *nptr);

        int g_line = 1;
%}

DIGIT	[0-9]
LETTER	[a-zA-Z]

%%
[\n]		{ fprintf(yyout, "\n%d.\t", g_line++);			}
[ \t]+		{ fprintf(yyout, "%s", yytext);				}

"bgn"		{ fprintf(yyout, "%s", yytext);	return _bgn;		}
"break"		{ fprintf(yyout, "%s", yytext);	return _break;		}
"case"		{ fprintf(yyout, "%s", yytext);	return _case;		}
"final"		{ fprintf(yyout, "%s", yytext);	return _final;		}
"default"	{ fprintf(yyout, "%s", yytext);	return _default;	}
"do"		{ fprintf(yyout, "%s", yytext);	return _do;		}
"else"		{ fprintf(yyout, "%s", yytext);	return _else;		}
"end"		{ fprintf(yyout, "%s", yytext);	return _end;		}
"foreach"	{ fprintf(yyout, "%s", yytext);	return _foreach;	}
"if"		{ fprintf(yyout, "%s", yytext);	return _if;		}
"int"		{ fprintf(yyout, "%s", yytext);	return _int;		}
"let"		{ fprintf(yyout, "%s", yytext);	return _let;		}
"out"		{ fprintf(yyout, "%s", yytext);	return _out;		}
"program"	{ fprintf(yyout, "%s", yytext);	return _program;	}
"real"		{ fprintf(yyout, "%s", yytext);	return _real;		}
"read"		{ fprintf(yyout, "%s", yytext);	return _read;		}
"string"	{ fprintf(yyout, "%s", yytext);	return _string;		}
"switch"	{ fprintf(yyout, "%s", yytext);	return _switch;		}
"till"		{ fprintf(yyout, "%s", yytext);	return _till;		}
"var"		{ fprintf(yyout, "%s", yytext);	return _var;		}
"while"		{ fprintf(yyout, "%s", yytext);	return _while;		}
"with"		{ fprintf(yyout, "%s", yytext);	return _with;		}

"("		{ fprintf(yyout, "%s", yytext);	return '(';		}
")"		{ fprintf(yyout, "%s", yytext);	return ')';		}
"{"		{ fprintf(yyout, "%s", yytext);	return '{';		}
"}"		{ fprintf(yyout, "%s", yytext);	return '}';		}
","		{ fprintf(yyout, "%s", yytext);	return ',';		}
":"		{ fprintf(yyout, "%s", yytext);	return ':';		}
";"		{ fprintf(yyout, "%s", yytext);	return ';';		}
"!"		{ fprintf(yyout, "%s", yytext);	return '!';		}

"=="		{ fprintf(yyout, "%s", yytext);	yylval.operation = EQ;		return _relop;		}
"<>"		{ fprintf(yyout, "%s", yytext);	yylval.operation = NE;		return _relop;		}
"<"		{ fprintf(yyout, "%s", yytext);	yylval.operation = LT;		return _relop;		}
">"		{ fprintf(yyout, "%s", yytext);	yylval.operation = GT;		return _relop;		}
">="		{ fprintf(yyout, "%s", yytext);	yylval.operation = GE;		return _relop;		}
"<="		{ fprintf(yyout, "%s", yytext);	yylval.operation = LE;		return _relop;		}

"+"		{ fprintf(yyout, "%s", yytext);	yylval.operation = ADD;		return _addop;		}
"-"		{ fprintf(yyout, "%s", yytext);	yylval.operation = SUB;		return _addop;		}

"*"		{ fprintf(yyout, "%s", yytext);	yylval.operation = MUL;		return _mulop;		}
"/"		{ fprintf(yyout, "%s", yytext);	yylval.operation = DIV;		return _mulop;		}

"="		{ fprintf(yyout, "%s", yytext);	yylval.operation = ASSIGN;	return _assignop;	}

"||"		{ fprintf(yyout, "%s", yytext);	yylval.operation = OR;		return _andorop;	}
"&&"		{ fprintf(yyout, "%s", yytext);	yylval.operation = AND;		return _andorop;	}

{LETTER}({LETTER}|{DIGIT})*	{
	if(yyleng > 9)
	{
		addError_idTooLong();
	}
	
	fprintf(yyout, "%s", yytext);

	yylval.variable.id = strdup(yytext);

	return _id;
}

{DIGIT}+			{
	fprintf(yyout, "%s", yytext);

	yylval.variable.type = 'i';
	yylval.variable.value.intValue = atoi(yytext);

	return _number;
}

{DIGIT}+"."{DIGIT}+		{
	fprintf(yyout, "%s", yytext);

	yylval.variable.type = 'f';
	yylval.variable.value.floatValue = atof(yytext);

	return _number;
}

\"({LETTER}|"."|","|"!"|"?"|" "|{DIGIT})*\"	{
	fprintf(yyout, "%s", yytext);

	yylval.variable.type = 's';
	yylval.variable.value.stringValue = strdup(yytext);

	return _sentence;
}

"/*".*"*/"	{}

.		{
	addError_unrecognizableCharacters();
}
%%