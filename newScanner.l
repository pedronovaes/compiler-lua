%{

#include <stdio.h>
#include <string.h>
#include "newScanner.h"

%}

%option yylineno
%option yywrap

letter			[a-zA-Z]
number			[0-9]
id 			[a-zA-Z_][a-zA-Z_0-9]*

%%

"and"			return AND;
"not"			return NOT;
"or"			return OR;
"elseif"		return ELSEIF;
"while"			return WHILE;
"do"			return DO;
"function"		return FUNCTION;
"end"			return END;
"for"			return FOR;
"else"			return ELSE;
"if"			return IF;
"then"			return THEN;
"return"		return RETURN;
"local"			return LOCAL;
"nil"			return NIL;

{id}			return ID;
{number}*		return NUMBER;

"+"			return TOKEN_PLUS;
"-"			return TOKEN_MINUS;
"*"			return TOKEN_MULT;
"/"			return TOKEN_DIV;

"="			return TOKEN_ASSIGN;
"=="			return TOKEN_EQUAL;
"~="			return TOKEN_NOTQUEAL;
"<="			return TOKEN_LESSEQUAL;
">="			return TOKEN_GREATEREQUAL;
"<"			return TOKEN_LESS;
">"			return TOKEN_GREATER;
")"			return TOKEN_RPAREN;
"("			return TOKEN_LPAREN;

[ \t\n]+		;
.			printf("Caracter Desconhecido: %s\n", yytext);								 

%%

int yywrap(void){
	return 1;
}
