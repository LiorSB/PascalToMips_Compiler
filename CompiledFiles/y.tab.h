/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _relop = 258,
     _addop = 259,
     _mulop = 260,
     _assignop = 261,
     _orop = 262,
     _andop = 263,
     _andorop = 264,
     _number = 265,
     _id = 266,
     _sentence = 267,
     _bgn = 268,
     _break = 269,
     _case = 270,
     _final = 271,
     _default = 272,
     _do = 273,
     _else = 274,
     _end = 275,
     _foreach = 276,
     _if = 277,
     _int = 278,
     _let = 279,
     _out = 280,
     _program = 281,
     _real = 282,
     _read = 283,
     _string = 284,
     _switch = 285,
     _till = 286,
     _var = 287,
     _while = 288,
     _with = 289
   };
#endif
/* Tokens.  */
#define _relop 258
#define _addop 259
#define _mulop 260
#define _assignop 261
#define _orop 262
#define _andop 263
#define _andorop 264
#define _number 265
#define _id 266
#define _sentence 267
#define _bgn 268
#define _break 269
#define _case 270
#define _final 271
#define _default 272
#define _do 273
#define _else 274
#define _end 275
#define _foreach 276
#define _if 277
#define _int 278
#define _let 279
#define _out 280
#define _program 281
#define _real 282
#define _read 283
#define _string 284
#define _switch 285
#define _till 286
#define _var 287
#define _while 288
#define _with 289



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 6 "cpm.y"

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


/* Line 2058 of yacc.c  */
#line 145 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
