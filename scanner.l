%{

#include <stdio.h>
#include <string.h>

%}

%option yylineno
%option yywrap

letter			[a-zA-Z]
float			[0-9]+\.[0-9]+
number			[0-9]+
negativeno		\-({float}|{number})
id 				[a-zA-Z_][a-zA-Z_0-9]*

%%

"and"			printf("<AND, \"%s\">\n", yytext);
"not"			printf("<NOT, \"%s\">\n", yytext);
"or"			printf("<OR, \"%s\">\n", yytext);
"elseif"		printf("<ELSEIF, \"%s\">\n", yytext);
"while"			printf("<WHILE, \"%s\">\n", yytext);
"do"			printf("<DO, \"%s\">\n", yytext);
"function"		printf("<FUNCTION, \"%s\">\n", yytext);
"end"			printf("<END, \"%s\">\n", yytext);
"for"			printf("<FOR, \"%s\">\n", yytext);
"else"			printf("<ELSE, \"%s\">\n", yytext);
"if"			printf("<IF, \"%s\">\n", yytext);
"then"			printf("<THEN, \"%s\">\n", yytext);
"return"		printf("<RETURN, \"%s\">\n", yytext);
"local"			printf("<LOCAL, \"%s\">\n", yytext);
"nil"			printf("<NIL, \"%s\">\n", yytext);

{id}			printf("<ID, \"%s\">\n", yytext);
{float}			printf("<FLOAT, \"%s\">\n", yytext);
{number}		printf("<NUMBER, \"%d\">\n", atoi(yytext));
{negativeno}	printf("<NEGATIVE NUMBER, \"%s\">\n", yytext);

"+"				printf("<TOKEN_PLUS, \"%s\">\n", yytext);
"-"				printf("<TOKEN_MINUS, \"%s\">\n", yytext);
"*"				printf("<TOKEN_MULT, \"%s\">\n", yytext);
"/"				printf("<TOKEN_DIV, \"%s\">\n", yytext);

"="				printf("<TOKEN_ASSIGN, \"%s\">\n", yytext);
"=="			printf("<TOKEN_EQUAL, \"%s\">\n", yytext);
"~="			printf("<TOKEN_NOTQUEAL, \"%s\">\n", yytext);
"<="			printf("<TOKEN_LESSEQUAL, \"%s\">\n", yytext);
">="			printf("<TOKEN_GREATEREQUAL, \"%s\">\n", yytext);
"<"				printf("<TOKEN_LESS, \"%s\">\n", yytext);
">"				printf("<TOKEN_GREATER, \"%s\">\n", yytext);
")"				printf("<TOKEN_RPAREN, \"%s\">\n", yytext);
"("				printf("<TOKEN_LPAREN, \"%s\">\n", yytext);

[ \t\n]+		;
.				printf("Caracter Desconhecido: %s\n", yytext);								 

%%

int yywrap(void){
	return 1;
}

int main(void){

	yylex();

	return 1;
}