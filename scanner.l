%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag_comma = 1;
%}

letter					[a-zA-Z]
float					[0-9]+\.[0-9]+
number					[0-9]+
negativeno				\-({float}|{number})
id					[a-zA-Z_][a-zA-Z_0-9]*

%%

"--"					comments();

"and"					{
						if(flag_comma == 1){
							printf("[T_AND, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_AND, \"%s\"]", yytext);
					}
"not"					{
						if(flag_comma == 1){
							printf("[T_NOT, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_NOT, \"%s\"]", yytext);
					}
"or"					{
						if(flag_comma == 1){
							printf("[T_OR, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_OR, \"%s\"]", yytext);
					}
"elseif"				{
						if(flag_comma == 1){
							printf("[T_ELSEIF, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_ELSEIF, \"%s\"]", yytext);
					}
"while"					{
						if(flag_comma == 1){
							printf("[T_WHILE, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_WHILE, \"%s\"]", yytext);
					}
"do"					{
						if(flag_comma == 1){
							printf("[T_DO, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n{T_DO, \"%s\"]", yytext);
					}
"function"				{
						if(flag_comma == 1){
							printf("[T_FUNCTION, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_FUNCTION, \"%s\"]", yytext);
					}
"end"					{
						if(flag_comma == 1){
							printf("[T_END, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_END, \"%s\"]", yytext);
					}
"for"					{
						if(flag_comma == 1){
							printf("[T_FOR, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_FOR, \"%s\"]", yytext);
					}
"else"					{
						if(flag_comma == 1){
							printf("[T_ELSE, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_ELSE, \"%s\"]", yytext);
					}
"if"					{
						if(flag_comma == 1){
							printf("[T_IF, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_IF, \"%s\"]", yytext);
					}
"then"					{
						if(flag_comma == 1){
							printf("[T_THEN, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_THEN, \"%s\"]", yytext);
					}
"return"				{
						if(flag_comma == 1){
							printf("[T_RETURN, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_RETURN, \"%s\"]", yytext);
					}
"local"					{
						if(flag_comma == 1){
							printf("[T_LOCAL, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_LOCAL, \"%s\"]", yytext);
					}
"nil"					{
						if(flag_comma == 1){
							printf("[T_NIL, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_NIL, \"%s\"]", yytext);
					}

{id}					{
						if(flag_comma == 1){
							printf("[T_NAME, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_NAME, \"%s\"]", yytext);
					}
{float}					{
						if(flag_comma == 1){
							printf("[T_NUMBER, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_NUMBER, \"%s\"]", yytext);
					}
{number}				{
						if(flag_comma == 1){
							printf("[T_NUMBER, \"%d\"]", atoi(yytext));
							flag_comma = 0;
						}else
							printf(",\n[T_NUMBER, \"%d\"]", atoi(yytext));
					}
{negativeno}				{
						if(flag_comma == 1){
							printf("[T_NUMBER, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_NUMBER, \"%s\"]", yytext);
					}

"+"					{
						if(flag_comma == 1){
							printf("[T_PLUS, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_PLUS, \"%s\"]", yytext);
					}
"-"					{
						if(flag_comma == 1){
							printf("[T_MINUS, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_MINUS, \"%s\"]", yytext);
					}
"*"					{
						if(flag_comma == 1){
							printf("[T_TIMES, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_TIMES, \"%s\"]", yytext);
					}
"/"					{
						if(flag_comma == 1){
							printf("[T_DIV, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_DIV, \"%s\"]", yytext);
					}

","					{
						if(flag_comma == 1){
							printf("[T_COMMA, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_COMMA, \"%s\"]", yytext);
					}
";"					{
						if(flag_comma == 1){
							printf("[T_SEMICOL, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_SEMICOL, \"%s\"]", yytext);
					}
"="					{
						if(flag_comma == 1){
							printf("[T_ASSIGN, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_ASSIGN, \"%s\"]", yytext);
					}
"=="					{
						if(flag_comma == 1){
							printf("[T_EQ, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_EQ, \"%s\"]", yytext);
					}
"~="					{
						if(flag_comma == 1){
							printf("[T_NEQ, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_NEQ, \"%s\"]", yytext);
					}
"<="					{
						if(flag_comma == 1){
							printf("[T_LTEQ, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_LTEQ, \"%s\"]", yytext);
					}
">="					{
						if(flag_comma == 1){
							printf("[T_GTEQ, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_GTEQ, \"%s\"]", yytext);
					}
"<"					{
						if(flag_comma == 1){
							printf("[T_LT, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_LT, \"%s\"]", yytext);
					}
">"					{
						if(flag_comma == 1){
							printf("[T_GT, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_GT, \"%s\"]", yytext);
					}
")"					{
						if(flag_comma == 1){
							printf("[T_CLOSEPAR, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_CLOSEPAR, \"%s\"]", yytext);
					}
"("					{
						if(flag_comma == 1){
							printf("[T_OPENPAR, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							printf(",\n[T_OPENPAR, \"%s\"]", yytext);
					}

\n					yylineno++;
[ \t]+					;
.					{
						if(flag_comma == 1)
							printf("LEXICAL ERROR AT LINE %d: %s\n", yylineno, yytext);
						else
							printf("\nLEXICAL ERROR AT LINE %d: %s", yylineno, yytext);
						//return 1;
					}
%%

comments(){
	char c;
	while((c = input()) != '\n');
	yylineno++;
}

int yywrap(){
	return 1;
}

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);
	printf("\n");
	return 0;
}
