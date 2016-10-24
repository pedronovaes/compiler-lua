/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOL = 258,
    ASSIGN = 259,
    DO = 260,
    END = 261,
    WHILE = 262,
    FOR = 263,
    COMMA = 264,
    IF = 265,
    THEN = 266,
    FUNCTION = 267,
    ELSEIF = 268,
    ELSE = 269,
    OPENPAR = 270,
    CLOSEPAR = 271,
    LOCAL = 272,
    RETURN = 273,
    NIL = 274,
    TIMES = 275,
    MINUS = 276,
    PLUS = 277,
    DIV = 278,
    LT = 279,
    LTEQ = 280,
    GT = 281,
    GTEQ = 282,
    EQ = 283,
    NEQ = 284,
    AND = 285,
    OR = 286,
    BLOCO = 287,
    FUNCALL = 288,
    COMANDO_N = 289,
    RETURN_N = 290,
    EXP_N = 291,
    LIST_N = 292,
    LISTEXP_N = 293,
    NOT = 294,
    COMMENT = 295,
    C_COMMENT = 296,
    NAME = 297,
    NUMBER = 298
  };
#endif
/* Tokens.  */
#define SEMICOL 258
#define ASSIGN 259
#define DO 260
#define END 261
#define WHILE 262
#define FOR 263
#define COMMA 264
#define IF 265
#define THEN 266
#define FUNCTION 267
#define ELSEIF 268
#define ELSE 269
#define OPENPAR 270
#define CLOSEPAR 271
#define LOCAL 272
#define RETURN 273
#define NIL 274
#define TIMES 275
#define MINUS 276
#define PLUS 277
#define DIV 278
#define LT 279
#define LTEQ 280
#define GT 281
#define GTEQ 282
#define EQ 283
#define NEQ 284
#define AND 285
#define OR 286
#define BLOCO 287
#define FUNCALL 288
#define COMANDO_N 289
#define RETURN_N 290
#define EXP_N 291
#define LIST_N 292
#define LISTEXP_N 293
#define NOT 294
#define COMMENT 295
#define C_COMMENT 296
#define NAME 297
#define NUMBER 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "parser.y" /* yacc.c:1909  */

	tipoTree *treePointer;
	int integer;
	char id[20];

#line 146 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
