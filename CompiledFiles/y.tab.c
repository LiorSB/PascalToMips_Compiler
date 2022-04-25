/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "cpm.y"

	#include "cpm.c"

/* Line 371 of yacc.c  */
#line 72 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
/* Line 387 of yacc.c  */
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


/* Line 387 of yacc.c  */
#line 203 "y.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 231 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  157

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    13,    17,    18,    21,    23,    24,
      29,    33,    36,    38,    40,    42,    50,    58,    59,    62,
      63,    65,    70,    72,    74,    76,    78,    84,    90,    96,
     101,   102,   103,   113,   114,   115,   123,   124,   135,   136,
     147,   148,   156,   158,   162,   170,   172,   174,   175,   176,
     186,   187,   192,   198,   204,   208,   212,   214,   215,   221,
     225,   229,   231,   235,   237,   241,   243
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    26,    11,    13,    46,    53,    20,    -1,
       1,    35,    -1,    24,    47,    52,    -1,    -1,    47,    48,
      -1,    48,    -1,    -1,    51,    49,    36,    50,    -1,    11,
      37,    50,    -1,    11,    38,    -1,    23,    -1,    27,    -1,
      29,    -1,    16,    51,    11,     6,    10,    38,    52,    -1,
      16,    51,    11,     6,    12,    38,    52,    -1,    -1,    53,
      54,    -1,    -1,    57,    -1,    11,     6,    12,    38,    -1,
      58,    -1,    56,    -1,    55,    -1,    66,    -1,    25,    39,
      77,    40,    38,    -1,    25,    39,    12,    40,    38,    -1,
      28,    39,    11,    40,    38,    -1,    11,     6,    77,    38,
      -1,    -1,    -1,    22,    39,    74,    40,    59,    54,    19,
      60,    54,    -1,    -1,    -1,    33,    61,    39,    74,    40,
      62,    66,    -1,    -1,    21,    11,     6,    10,    36,    10,
      63,    34,    73,    54,    -1,    -1,    21,    11,     6,    10,
      36,    11,    64,    34,    73,    54,    -1,    -1,    18,    65,
      66,    31,    39,    74,    40,    -1,    67,    -1,    41,    53,
      42,    -1,    30,    39,    68,    40,    41,    69,    42,    -1,
      11,    -1,    10,    -1,    -1,    -1,    15,    10,    36,    70,
      53,    14,    38,    71,    69,    -1,    -1,    17,    36,    72,
      53,    -1,    11,     6,    11,     4,    10,    -1,    11,     6,
      11,     5,    10,    -1,    74,     9,    75,    -1,    75,     9,
      75,    -1,    75,    -1,    -1,    43,    76,    39,    75,    40,
      -1,    77,     3,    77,    -1,    77,     4,    78,    -1,    78,
      -1,    78,     5,    79,    -1,    79,    -1,    39,    77,    40,
      -1,    11,    -1,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    83,    90,    92,    95,    97,   101,   100,
     107,   136,   165,   170,   175,   181,   222,   235,   238,   239,
     242,   244,   267,   269,   271,   273,   276,   323,   329,   360,
     415,   419,   414,   428,   432,   427,   441,   440,   455,   454,
     470,   469,   479,   482,   485,   488,   493,   500,   504,   499,
     510,   509,   519,   533,   548,   560,   572,   576,   575,   584,
     622,   689,   695,   762,   768,   773,   805
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_relop", "_addop", "_mulop",
  "_assignop", "_orop", "_andop", "_andorop", "_number", "_id",
  "_sentence", "_bgn", "_break", "_case", "_final", "_default", "_do",
  "_else", "_end", "_foreach", "_if", "_int", "_let", "_out", "_program",
  "_real", "_read", "_string", "_switch", "_till", "_var", "_while",
  "_with", "'\\n'", "':'", "','", "';'", "'('", "')'", "'{'", "'}'", "'!'",
  "$accept", "PROGRAM", "DECLARATIONS", "DECLARLIST", "DECL", "$@1",
  "LIST", "TYPE", "CDECL", "STMTLIST", "STMT", "OUT_STMT", "READ_STMT",
  "ASSIGNMENT_STMT", "CONTROL_STMT", "$@2", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "STMT_BLOCK", "SWITCH", "CHOICE", "CASES", "$@9", "$@10",
  "$@11", "STEP", "BOOLEXPRESSION", "BOOLFACTOR", "$@12", "EXPRESSION",
  "TERM", "FACTOR", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    10,    58,    44,    59,    40,
      41,   123,   125,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    47,    47,    49,    48,
      50,    50,    51,    51,    51,    52,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    57,
      59,    60,    58,    61,    62,    58,    63,    58,    64,    58,
      65,    58,    58,    66,    67,    68,    68,    70,    71,    69,
      72,    69,    73,    73,    74,    74,    74,    76,    75,    75,
      77,    77,    78,    78,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     3,     0,     2,     1,     0,     4,
       3,     2,     1,     1,     1,     7,     7,     0,     2,     0,
       1,     4,     1,     1,     1,     1,     5,     5,     5,     4,
       0,     0,     9,     0,     0,     7,     0,    10,     0,    10,
       0,     7,     1,     3,     7,     1,     1,     0,     0,     9,
       0,     4,     5,     5,     3,     3,     1,     0,     5,     3,
       3,     1,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     1,     5,     0,    19,
      12,    13,    14,    17,     7,     8,     0,     0,     6,     4,
       0,     0,    40,     2,     0,     0,     0,     0,     0,    33,
      19,    18,    24,    23,    20,    22,    25,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    66,    65,     0,     0,     0,    61,    63,     0,
       0,    57,     0,    56,     0,     0,     0,     0,    46,    45,
       0,     0,    43,     0,     0,    11,    21,     0,     0,    29,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    64,    60,    62,     0,
       0,     0,    54,     0,    55,    59,    27,    26,    28,     0,
      34,    17,    17,     0,    36,    38,     0,     0,     0,     0,
       0,     0,    15,    16,    41,     0,     0,    58,    31,     0,
      50,    44,    35,     0,     0,     0,    47,    19,     0,     0,
       0,    32,    19,    51,     0,    37,    39,     0,     0,     0,
       0,     0,    48,    52,    53,     0,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     9,    13,    14,    20,    51,    15,    19,    16,
      31,    32,    33,    34,    35,   103,   135,    47,   121,   125,
     126,    41,    36,    37,    70,   120,   142,   155,   137,   139,
      62,    63,    83,    64,    57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
      21,   -22,    43,    32,  -101,     8,  -101,    37,     4,  -101,
    -101,  -101,  -101,     7,  -101,  -101,    52,     4,  -101,  -101,
      29,    63,  -101,  -101,    60,    47,    53,    70,    74,  -101,
    -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,    79,    91,
      -2,    75,   111,     5,    14,   109,    68,    82,    34,   117,
      51,  -101,  -101,  -101,    86,    18,     0,   121,  -101,    98,
     118,  -101,     2,   122,    93,    92,     1,    94,  -101,  -101,
      95,     5,  -101,    48,    91,  -101,  -101,     3,    18,  -101,
      18,   101,   103,   102,     5,  -101,     5,    18,    99,   104,
     105,   106,    10,   107,   108,  -101,  -101,   121,  -101,     5,
      89,     5,  -101,    97,  -101,   129,  -101,  -101,  -101,    -3,
    -101,   120,   120,    11,  -101,  -101,   110,   125,   138,   113,
     112,    75,  -101,  -101,  -101,   119,   123,  -101,  -101,   115,
    -101,  -101,  -101,   141,   141,    97,  -101,  -101,   149,    97,
      97,  -101,  -101,    97,   145,  -101,  -101,    73,   100,   124,
     148,   150,  -101,  -101,  -101,    -3,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,  -101,  -101,   146,  -101,    87,   147,    -1,   -30,
    -100,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -101,   -40,  -101,  -101,    12,  -101,  -101,  -101,    31,
     -53,   -18,  -101,   -38,    85,    88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      48,    59,    56,   117,    78,    78,    66,    78,    52,    53,
      54,    84,   118,     4,   119,    52,    53,    77,    92,    84,
      84,     7,     1,    17,    52,    53,    65,    10,    52,    53,
      10,    11,     6,    12,    11,   141,    12,    55,    79,   145,
     146,    89,    85,    96,    55,    21,   113,     2,    61,   105,
     110,   124,    22,    55,     5,    24,    25,    55,    93,    26,
      94,     8,    27,    21,    28,    39,   102,    29,   104,    40,
      22,    42,    23,    24,    25,    30,    72,    26,    68,    69,
      27,   132,    28,   116,    21,    29,    43,   149,    74,    75,
      49,    22,    44,    30,    24,    25,    87,    78,    26,   114,
     115,    27,    50,    28,   150,   151,    29,   143,    21,    45,
     122,   123,   147,    46,    30,    22,    30,    60,    24,    25,
      67,    71,    26,    73,    76,    27,    80,    28,    82,    81,
      29,    86,    88,    78,    90,    91,    17,   106,    30,   100,
      99,   101,   107,   108,   128,   111,   112,   109,   129,   130,
     127,   136,   138,   133,   131,   144,   148,   134,   153,    18,
     154,    95,   152,    97,    38,   140,     0,   156,    98
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      30,    41,    40,   103,     4,     4,    44,     4,    10,    11,
      12,     9,    15,    35,    17,    10,    11,    55,    71,     9,
       9,    13,     1,    16,    10,    11,    12,    23,    10,    11,
      23,    27,     0,    29,    27,   135,    29,    39,    38,   139,
     140,    40,    40,    40,    39,    11,    99,    26,    43,    87,
      40,    40,    18,    39,    11,    21,    22,    39,    10,    25,
      12,    24,    28,    11,    30,    36,    84,    33,    86,     6,
      18,    11,    20,    21,    22,    41,    42,    25,    10,    11,
      28,   121,    30,   101,    11,    33,    39,    14,    37,    38,
      11,    18,    39,    41,    21,    22,     3,     4,    25,    10,
      11,    28,    11,    30,     4,     5,    33,   137,    11,    39,
     111,   112,   142,    39,    41,    18,    41,     6,    21,    22,
      11,    39,    25,     6,    38,    28,     5,    30,    10,    31,
      33,     9,    40,     4,    40,    40,    16,    38,    41,    36,
      39,    39,    38,    38,    19,    38,    38,    41,    10,    36,
      40,    36,    11,    34,    42,     6,    11,    34,    10,    13,
      10,    74,    38,    78,    17,   134,    -1,   155,    80
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    26,    45,    35,    11,     0,    13,    24,    46,
      23,    27,    29,    47,    48,    51,    53,    16,    48,    52,
      49,    11,    18,    20,    21,    22,    25,    28,    30,    33,
      41,    54,    55,    56,    57,    58,    66,    67,    51,    36,
       6,    65,    11,    39,    39,    39,    39,    61,    53,    11,
      11,    50,    10,    11,    12,    39,    77,    78,    79,    66,
       6,    43,    74,    75,    77,    12,    77,    11,    10,    11,
      68,    39,    42,     6,    37,    38,    38,    77,     4,    38,
       5,    31,    10,    76,     9,    40,     9,     3,    40,    40,
      40,    40,    74,    10,    12,    50,    40,    78,    79,    39,
      36,    39,    75,    59,    75,    77,    38,    38,    38,    41,
      40,    38,    38,    74,    10,    11,    75,    54,    15,    17,
      69,    62,    52,    52,    40,    63,    64,    40,    19,    10,
      36,    42,    66,    34,    34,    60,    36,    72,    11,    73,
      73,    54,    70,    53,     6,    54,    54,    53,    11,    14,
       4,     5,    38,    10,    10,    71,    69
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 79 "cpm.y"
    {
				addExitToMips();
			}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 84 "cpm.y"
    {
				yyerrok;  
				yyclearin;
			}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 101 "cpm.y"
    {
				g_type = (yyvsp[(1) - (1)].type);
			}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 108 "cpm.y"
    {	
				if (doesIdExist((yyvsp[(1) - (3)].variable).id))
				{	
					addError_redeclaration((yyvsp[(1) - (3)].variable).id);
				}
				else
				{
				
					switch (g_type)
					{
						case 'i':
							insertIntToList((yyvsp[(1) - (3)].variable).id, 0, FALSE, FALSE);
							insertIntVariableToMips((yyvsp[(1) - (3)].variable).id, 0);
							break;

						case 'f':
							insertFloatToList((yyvsp[(1) - (3)].variable).id, 0.0, FALSE, FALSE);
							insertFloatVariableToMips((yyvsp[(1) - (3)].variable).id, 0.0);
							break;

						case 's':
							insertStringToList((yyvsp[(1) - (3)].variable).id, NULL, FALSE, FALSE);
							insertStringVariableToMips((yyvsp[(1) - (3)].variable).id, NULL);
							break;
					}
				}
			}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 137 "cpm.y"
    {	
				if (doesIdExist((yyvsp[(1) - (2)].variable).id))
				{	
					addError_redeclaration((yyvsp[(1) - (2)].variable).id);
				}
				else
				{
					switch (g_type)
					{
						case 'i':
							insertIntToList((yyvsp[(1) - (2)].variable).id, 0, FALSE, FALSE);
							insertIntVariableToMips((yyvsp[(1) - (2)].variable).id, 0);
							break;

						case 'f':
							insertFloatToList((yyvsp[(1) - (2)].variable).id, 0.0, FALSE, FALSE);
							insertFloatVariableToMips((yyvsp[(1) - (2)].variable).id, 0.0);
							break;

						case 's':
							insertStringToList((yyvsp[(1) - (2)].variable).id, NULL, FALSE, FALSE);
							insertStringVariableToMips((yyvsp[(1) - (2)].variable).id, NULL);
							break;
					}
				}
			}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 166 "cpm.y"
    {
				(yyval.type) = 'i';
			}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 171 "cpm.y"
    {
				(yyval.type) = 'f';
			}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 176 "cpm.y"
    {
				(yyval.type) = 's';
			}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 182 "cpm.y"
    {
				if (doesIdExist((yyvsp[(3) - (7)].variable).id))
				{	
					addError_redeclaration((yyvsp[(3) - (7)].variable).id);
				}
				else
				{
					if ((yyvsp[(2) - (7)].type) == 'i')
					{
						if ((yyvsp[(5) - (7)].variable).type == 'i')
						{
							insertIntVariableToMips((yyvsp[(3) - (7)].variable).id, (yyvsp[(5) - (7)].variable).value.intValue);
							insertIntToList((yyvsp[(3) - (7)].variable).id, (yyvsp[(5) - (7)].variable).value.intValue, TRUE, TRUE);
						}
						else // ($5.type == 'f')
						{
							int intValue = (int)(yyvsp[(5) - (7)].variable).value.floatValue;

							insertIntVariableToMips((yyvsp[(3) - (7)].variable).id, intValue);
							insertIntToList((yyvsp[(3) - (7)].variable).id, intValue, TRUE, TRUE);
						}
					}
					else // $2 == 'f'
					{
						if ((yyvsp[(5) - (7)].variable).type == 'i')
						{	
							float floatValue = (float)(yyvsp[(5) - (7)].variable).value.intValue;

							insertFloatVariableToMips((yyvsp[(3) - (7)].variable).id, floatValue);
							insertFloatToList((yyvsp[(3) - (7)].variable).id, floatValue, TRUE, TRUE);
						}
						else // ($5.type == 'f')
						{
							insertFloatVariableToMips((yyvsp[(3) - (7)].variable).id, (yyvsp[(5) - (7)].variable).value.floatValue);
							insertFloatToList((yyvsp[(3) - (7)].variable).id, (yyvsp[(5) - (7)].variable).value.floatValue, TRUE, TRUE);
						}
					}
				}
			}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 223 "cpm.y"
    {
				if (doesIdExist((yyvsp[(3) - (7)].variable).id))
				{	
					addError_redeclaration((yyvsp[(3) - (7)].variable).id);
				}
				else
				{
					insertStringToList((yyvsp[(3) - (7)].variable).id, (yyvsp[(5) - (7)].variable).value.stringValue, TRUE, TRUE);
					insertStringVariableToMips((yyvsp[(3) - (7)].variable).id, (yyvsp[(5) - (7)].variable).value.stringValue);
				}
			}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 245 "cpm.y"
    {
				symbolNode* node = getNodeById((yyvsp[(1) - (4)].variable).id);

				if (node == NULL)
				{
					addError_undeclared((yyvsp[(1) - (4)].variable).id);
				}
				else if (node->type != 's')
				{
					addError_assighmentWrongType(node->id, node->type);
				}
				else if (node->isConst)
				{
					addError_const((yyvsp[(1) - (4)].variable).id);
				}
				else
				{
					assignStringValue((yyvsp[(1) - (4)].variable).id, (yyvsp[(3) - (4)].variable).value.stringValue);
					assignToStringMips((yyvsp[(1) - (4)].variable).id, (yyvsp[(3) - (4)].variable).value.stringValue);
				}
			}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 277 "cpm.y"
    {
				symbolNode* node = getNodeById((yyvsp[(3) - (5)].variable).id);
				
				if ((yyvsp[(3) - (5)].variable).id != NULL && !node->isInitialized)
				{
					addError_undeclared((yyvsp[(3) - (5)].variable).id);
				}
				else
				{
					if ((yyvsp[(3) - (5)].variable).id == NULL)
					{
						switch ((yyvsp[(3) - (5)].variable).type)
						{	
							case 'i':
								addOutToMips(NULL, 'i', (yyvsp[(3) - (5)].variable).value.intValue, (yyvsp[(3) - (5)].variable).value.floatValue);
								break;

							case 'f':
								addOutToMips(NULL, 'f', (yyvsp[(3) - (5)].variable).value.intValue, (yyvsp[(3) - (5)].variable).value.floatValue);
								break;

							case 's':
								addOutToMips(NULL, 's', (yyvsp[(3) - (5)].variable).value.intValue, (yyvsp[(3) - (5)].variable).value.floatValue);
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
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 324 "cpm.y"
    {
				addOutToMips((yyvsp[(3) - (5)].variable).value.stringValue, 'e', 0, 0.0);
			}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 330 "cpm.y"
    {
				symbolNode* node = getNodeById((yyvsp[(3) - (5)].variable).id);
				
				if (node == NULL)
				{
					addError_undeclared((yyvsp[(3) - (5)].variable).id);
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
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 361 "cpm.y"
    {
				symbolNode* node = getNodeById((yyvsp[(1) - (4)].variable).id);

				if (node == NULL)
				{
					addError_undeclared((yyvsp[(1) - (4)].variable).id);
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
					symbolNode* nodeExpression = getNodeById((yyvsp[(3) - (4)].variable).id);
				

					if ((yyvsp[(3) - (4)].variable).id != NULL && nodeExpression == NULL)
					{
						addError_undeclared((yyvsp[(3) - (4)].variable).id);
					}
					else if ((yyvsp[(3) - (4)].variable).id != NULL && nodeExpression->type == 's')
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
							addPreperationForAssignmentToMips(node->id, node->type, (yyvsp[(3) - (4)].variable).id, (yyvsp[(3) - (4)].variable).value.intValue, (yyvsp[(3) - (4)].variable).value.floatValue, (yyvsp[(3) - (4)].variable).type);
						}

						
						if (node->type == 'i')
						{
							assignIntValue((yyvsp[(1) - (4)].variable).id, (yyvsp[(3) - (4)].variable).value.intValue);
						}
						else
						{
							assignFloatValue((yyvsp[(1) - (4)].variable).id, (yyvsp[(3) - (4)].variable).value.floatValue);
						}
					}
				}
			}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 415 "cpm.y"
    {
				addComparisonValidationStatementToMips();
			}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 419 "cpm.y"
    {
				addElseStatementToMips();
			}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 423 "cpm.y"
    {
				addEndIfStatementToMips();
			}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 428 "cpm.y"
    {
				addStartWhileStatementToMips();
			}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 432 "cpm.y"
    {
				addWhileValidationStatementToMips();
			}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 436 "cpm.y"
    {
				addEndOfWhileStatementToMips();
			}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 441 "cpm.y"
    {
				insertIntToList((yyvsp[(2) - (6)].variable).id, (yyvsp[(4) - (6)].variable).value.intValue, FALSE, TRUE);
				insertIntVariableToMips((yyvsp[(2) - (6)].variable).id, (yyvsp[(4) - (6)].variable).value.intValue);

				addStartForeachStatementToMips();
				addComparisonToMips("ne", (yyvsp[(2) - (6)].variable).id, NULL, (yyvsp[(2) - (6)].variable).value.intValue, (yyvsp[(6) - (6)].variable).value.intValue, (yyvsp[(2) - (6)].variable).value.floatValue, (yyvsp[(6) - (6)].variable).value.floatValue, 'i', (yyvsp[(6) - (6)].variable).type);
				addForeachValidationStatementToMips();
			}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 450 "cpm.y"
    {
				addEndOfForeachStatementToMips();
			}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 455 "cpm.y"
    {
				insertIntToList((yyvsp[(2) - (6)].variable).id, (yyvsp[(4) - (6)].variable).value.intValue, FALSE, TRUE);
				insertIntVariableToMips((yyvsp[(2) - (6)].variable).id, (yyvsp[(4) - (6)].variable).value.intValue);

				addStartForeachStatementToMips();
				addComparisonToMips("ne", (yyvsp[(2) - (6)].variable).id, (yyvsp[(6) - (6)].variable).id, (yyvsp[(2) - (6)].variable).value.intValue, (yyvsp[(6) - (6)].variable).value.intValue, (yyvsp[(2) - (6)].variable).value.floatValue, (yyvsp[(6) - (6)].variable).value.floatValue, 'i', (yyvsp[(6) - (6)].variable).type);
				addForeachValidationStatementToMips();
			}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 464 "cpm.y"
    {
				addEndOfForeachStatementToMips();
				removeFromList((yyvsp[(2) - (10)].variable).id);
			}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 470 "cpm.y"
    {
				addStartDoStatementToMips();
			}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 474 "cpm.y"
    {
				addDoValidationStatementToMips();
				addEndOfDoStatementToMips();
			}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 489 "cpm.y"
    {
				addSwitchChoiceToMips((yyvsp[(1) - (1)].variable).id, 0, 0.0, (yyvsp[(1) - (1)].variable).type);
			}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 494 "cpm.y"
    {
				addSwitchChoiceToMips(NULL, (yyvsp[(1) - (1)].variable).value.intValue, (yyvsp[(1) - (1)].variable).value.floatValue, (yyvsp[(1) - (1)].variable).type);
			}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 500 "cpm.y"
    {
				addSwitchCaseToMips((yyvsp[(2) - (3)].variable).value.intValue, (yyvsp[(2) - (3)].variable).value.floatValue, (yyvsp[(2) - (3)].variable).type);
			}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 504 "cpm.y"
    {
				addSwitchBreakToMips();
			}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 510 "cpm.y"
    {
				addSwitchDefaultToMips();
			}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 514 "cpm.y"
    {
				addSwitchEndToMips();
			}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 520 "cpm.y"
    {
				if ((yyvsp[(4) - (5)].operation) = ADD)
				{
					addArithmeticOperationToMips("add", (yyvsp[(3) - (5)].variable).id, NULL, (yyvsp[(3) - (5)].variable).value.intValue, (yyvsp[(5) - (5)].variable).value.intValue, (yyvsp[(3) - (5)].variable).value.floatValue, (yyvsp[(5) - (5)].variable).value.floatValue, 'i', (yyvsp[(5) - (5)].variable).type);
					addEndAssignmentToMips((yyvsp[(1) - (5)].variable).id, 'i');
				}
				else //($4 == SUB)
				{
					addArithmeticOperationToMips("sub", (yyvsp[(3) - (5)].variable).id, NULL, (yyvsp[(3) - (5)].variable).value.intValue, (yyvsp[(5) - (5)].variable).value.intValue, (yyvsp[(3) - (5)].variable).value.floatValue, (yyvsp[(5) - (5)].variable).value.floatValue, 'i', (yyvsp[(5) - (5)].variable).type);
					addEndAssignmentToMips((yyvsp[(1) - (5)].variable).id, 'i');
				}
			}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 534 "cpm.y"
    {
				if ((yyvsp[(4) - (5)].operation) = MUL)
				{
					addArithmeticOperationToMips("mul", (yyvsp[(3) - (5)].variable).id, NULL, (yyvsp[(3) - (5)].variable).value.intValue, (yyvsp[(5) - (5)].variable).value.intValue, (yyvsp[(3) - (5)].variable).value.floatValue, (yyvsp[(5) - (5)].variable).value.floatValue, 'i', (yyvsp[(5) - (5)].variable).type);
					addEndAssignmentToMips((yyvsp[(1) - (5)].variable).id, 'i');
				}
				else //($4 == DIV)
				{
					addArithmeticOperationToMips("div", (yyvsp[(3) - (5)].variable).id, NULL, (yyvsp[(3) - (5)].variable).value.intValue, (yyvsp[(5) - (5)].variable).value.intValue, (yyvsp[(3) - (5)].variable).value.floatValue, (yyvsp[(5) - (5)].variable).value.floatValue, 'i', (yyvsp[(5) - (5)].variable).type);
					addEndAssignmentToMips((yyvsp[(1) - (5)].variable).id, 'i');
				}
			}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 549 "cpm.y"
    {
				if ((yyvsp[(2) - (3)].operation) == AND)
				{
					addAndOrStatementToMips("and");
				}
				else // ($2 == OR)
				{
					addAndOrStatementToMips("or");
				}
			}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 561 "cpm.y"
    {
				if ((yyvsp[(2) - (3)].operation) == AND)
				{
					addAndOrStatementToMips("and");
				}
				else // ($2 == OR)
				{
					addAndOrStatementToMips("or");
				}
			}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 576 "cpm.y"
    {
				g_NotFlag = TRUE;
			}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 580 "cpm.y"
    {
				g_NotFlag = FALSE;	
			}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 585 "cpm.y"
    {
				if ((yyvsp[(1) - (3)].variable).type == 's' || (yyvsp[(3) - (3)].variable).type == 's')
				{
					addError_stringOperation();
				}
				else
				{
					switch ((yyvsp[(2) - (3)].operation))
					{
						case EQ:	// ==
							addComparisonToMips("eq", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);
							break;
	
						case NE:	// !=
							addComparisonToMips("ne", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);	
							break;
		
						case LT:	// <
							addComparisonToMips("lt", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);	
							break;
	
						case GT:	// >
							addComparisonToMips("gt", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);	
							break;
	
						case GE:	// >=
							addComparisonToMips("ge", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);
							break;
		
						case LE:	// <=
							addComparisonToMips("le", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);	
							break;
					}
				}
			}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 623 "cpm.y"
    {
				symbolNode* node1 = getNodeById((yyvsp[(1) - (3)].variable).id);
				symbolNode* node2 = getNodeById((yyvsp[(3) - (3)].variable).id);


				if ((yyvsp[(1) - (3)].variable).type == 's' || (yyvsp[(3) - (3)].variable). type == 's')
				{
					addError_stringOperation();
				}
				else if ((yyvsp[(1) - (3)].variable).id != NULL && !node1->isInitialized)
				{
					addError_undeclared((yyvsp[(1) - (3)].variable).id);
				}
				else if ((yyvsp[(3) - (3)].variable).id != NULL && !node2->isInitialized)
				{
					addError_undeclared((yyvsp[(3) - (3)].variable).id);
				}
				else
				{
					if ((yyvsp[(2) - (3)].operation) == ADD)
					{
						if (g_continueOperation)
						{
							addArithmeticOperationContinuationToMips("add", (yyvsp[(3) - (3)].variable).id, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).type);
						}
						else
						{
							addArithmeticOperationToMips("add", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);
						}

						if ((yyvsp[(1) - (3)].variable).type == 'i' && (yyvsp[(3) - (3)].variable).type == 'i')
						{
							(yyval.variable).type = 'i';
							(yyval.variable).value.intValue = (yyvsp[(1) - (3)].variable).value.intValue + (yyvsp[(3) - (3)].variable).value.intValue;
						}
						else
						{
							(yyval.variable).type = 'f';
							(yyval.variable).value.floatValue = ((yyvsp[(1) - (3)].variable).type == 'i' ? (yyvsp[(1) - (3)].variable).value.intValue : (yyvsp[(1) - (3)].variable).value.floatValue) + ((yyvsp[(3) - (3)].variable).type == 'i' ? (yyvsp[(3) - (3)].variable).value.intValue : (yyvsp[(3) - (3)].variable).value.floatValue);
						}
					}
					else // ($2 == SUB)
					{
						if (g_continueOperation)
						{
							addArithmeticOperationContinuationToMips("sub", (yyvsp[(1) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type);
						}
						else
						{
							addArithmeticOperationToMips("sub", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);
						}

						if ((yyvsp[(1) - (3)].variable).type == 'i' && (yyvsp[(3) - (3)].variable).type == 'i')
						{
							(yyval.variable).type = 'i';
							(yyval.variable).value.intValue = (yyvsp[(1) - (3)].variable).value.intValue - (yyvsp[(3) - (3)].variable).value.intValue;
						}
						else
						{
							(yyval.variable).type = 'f';
							(yyval.variable).value.floatValue = ((yyvsp[(1) - (3)].variable).type == 'i' ? (yyvsp[(1) - (3)].variable).value.intValue : (yyvsp[(1) - (3)].variable).value.floatValue) - ((yyvsp[(3) - (3)].variable).type == 'i' ? (yyvsp[(3) - (3)].variable).value.intValue : (yyvsp[(3) - (3)].variable).value.floatValue);
						}
					}
				}
			}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 690 "cpm.y"
    {
				(yyval.variable) = (yyvsp[(1) - (1)].variable);
			}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 696 "cpm.y"
    {
				symbolNode* node1 = getNodeById((yyvsp[(1) - (3)].variable).id);
				symbolNode* node2 = getNodeById((yyvsp[(3) - (3)].variable).id);


				if ((yyvsp[(1) - (3)].variable).type == 's' || (yyvsp[(3) - (3)].variable). type == 's')
				{
					addError_stringOperation();
				}
				else if ((yyvsp[(1) - (3)].variable).id != NULL && !node1->isInitialized)
				{
					addError_undeclared((yyvsp[(1) - (3)].variable).id);
				}
				else if ((yyvsp[(3) - (3)].variable).id != NULL && !node2->isInitialized)
				{
					addError_undeclared((yyvsp[(3) - (3)].variable).id);
				}
				else
				{
					if ((yyvsp[(2) - (3)].operation) == MUL)
					{
						if (g_continueOperation)
						{
							addArithmeticOperationContinuationToMips("mul", (yyvsp[(1) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type);
						}
						else
						{
							addArithmeticOperationToMips("mul", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);
						}

						if ((yyvsp[(1) - (3)].variable).type == 'i' && (yyvsp[(3) - (3)].variable).type == 'i')
						{
							(yyval.variable).type = 'i';
							(yyval.variable).value.intValue = (yyvsp[(1) - (3)].variable).value.intValue * (yyvsp[(3) - (3)].variable).value.intValue;
						}
						else
						{
							(yyval.variable).type = 'f';
							(yyval.variable).value.floatValue = ((yyvsp[(1) - (3)].variable).type == 'i' ? (yyvsp[(1) - (3)].variable).value.intValue : (yyvsp[(1) - (3)].variable).value.floatValue) * ((yyvsp[(3) - (3)].variable).type == 'i' ? (yyvsp[(3) - (3)].variable).value.intValue : (yyvsp[(3) - (3)].variable).value.floatValue);
						}
					}
					else // ($2 == DIV)
					{
						if (g_continueOperation)
						{
							addArithmeticOperationContinuationToMips("div", (yyvsp[(1) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type);
						}
						else
						{
							addArithmeticOperationToMips("div", (yyvsp[(1) - (3)].variable).id, (yyvsp[(3) - (3)].variable).id, (yyvsp[(1) - (3)].variable).value.intValue, (yyvsp[(3) - (3)].variable).value.intValue, (yyvsp[(1) - (3)].variable).value.floatValue, (yyvsp[(3) - (3)].variable).value.floatValue, (yyvsp[(1) - (3)].variable).type, (yyvsp[(3) - (3)].variable).type);
						}

						if ((yyvsp[(1) - (3)].variable).type == 'i' && (yyvsp[(3) - (3)].variable).type == 'i')
						{
							(yyval.variable).type = 'i';
							(yyval.variable).value.intValue = (yyvsp[(1) - (3)].variable).value.intValue * (yyvsp[(3) - (3)].variable).value.intValue;
						}
						else
						{
							(yyval.variable).type = 'f';
							(yyval.variable).value.floatValue = ((yyvsp[(1) - (3)].variable).type == 'i' ? (yyvsp[(1) - (3)].variable).value.intValue : (yyvsp[(1) - (3)].variable).value.floatValue) * ((yyvsp[(3) - (3)].variable).type == 'i' ? (yyvsp[(3) - (3)].variable).value.intValue : (yyvsp[(3) - (3)].variable).value.floatValue);
						}
					}
				}
			}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 763 "cpm.y"
    {
				(yyval.variable) = (yyvsp[(1) - (1)].variable);
			}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 769 "cpm.y"
    {
				(yyval.variable) = (yyvsp[(2) - (3)].variable);
			}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 774 "cpm.y"
    {
				symbolNode* node = getNodeById((yyvsp[(1) - (1)].variable).id);

				if (node == NULL)
				{
					addError_undeclared((yyvsp[(1) - (1)].variable).id);
				}
				else
				{
					(yyval.variable).id = (yyvsp[(1) - (1)].variable).id;

					switch (node->type)
					{
						case 'i':
							(yyval.variable).type = 'i';
							(yyval.variable).value.intValue = (yyvsp[(1) - (1)].variable).value.intValue;
							break;

						case 'f':
							(yyval.variable).type = 'f';
							(yyval.variable).value.floatValue = (yyvsp[(1) - (1)].variable).value.floatValue;
							break;

						case 's':
							(yyval.variable).type = 's';
							(yyval.variable).value.stringValue = (yyvsp[(1) - (1)].variable).value.stringValue;
							break;
					}
				}
			}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 806 "cpm.y"
    {
				(yyval.variable).id = NULL;

				if ((yyvsp[(1) - (1)].variable).type == 'i')
				{
					(yyval.variable).type = 'i';
					(yyval.variable).value.intValue = (yyvsp[(1) - (1)].variable).value.intValue;
				}
				else
				{
					(yyval.variable).type = 'f';
					(yyval.variable).value.floatValue = (yyvsp[(1) - (1)].variable).value.floatValue;
				}
			}
    break;


/* Line 1792 of yacc.c  */
#line 2393 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 821 "cpm.y"
