%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "y.tab.h"

int flag_comma = 1;
%}

letter					[a-zA-Z]
float					[0-9]+\.[0-9]+
number					[0-9]+
/*negativeno				\-({float}|{number})*/
id					[a-zA-Z_][a-zA-Z_0-9]*

%%

"--"					simple_comment();
"--["					complex_comment();

"and"					{
						//print_token("T_AND");
						return AND;
					}
"not"					{
						//print_token("T_NOT");
						return NOT;
					}
"or"					{
						//print_token("T_OR");
						return OR;
					}
"elseif"				{
						//print_token("T_ELSEIF");
						return ELSEIF;
					}
"while"					{
						//print_token("T_WHILE");
						return WHILE;
					}
"do"					{
						//print_token("T_DO");
						return DO;
					}
"function"				{
						//print_token("T_FUNCTION");
						return FUNCTION;
					}
"end"					{
						//print_token("T_END");
						return END;
					}
"for"					{
						//print_token("T_FOR");
						return FOR;
					}
"else"					{
						//print_token("T_ELSE");
						return ELSE;
					}
"if"					{
						//print_token("T_IF");
						return IF;
					}
"then"					{
						//print_token("T_THEN");
						return THEN;
					}
"return"				{
						//print_token("T_RETURN");
						return RETURN;
					}
"local"					{
						//print_token("T_LOCAL");
						return LOCAL;
					}
"nil"					{
						//print_token("T_NIL");
						return NIL;
					}

{id}					{
						//print_token("T_NAME");
						strcpy(yylval.id, yytext);
						return NAME;
					}
{float}					{
						//print_token("T_NUMBER");
						return NUMBER;
					}
{number}			{
						//print_token("T_NUMBER");
						yylval.integer = atoi(yytext);
						return NUMBER;
					}

"+"					{
						//print_token("T_PLUS");
						return PLUS;
					}
"-"					{
						//print_token("T_MINUS");
						return MINUS;
					}
"*"					{
						//print_token("T_TIMES");
						return TIMES;
					}
"/"					{
						//print_token("T_DIV");
						return DIV;
					}
","					{
						//print_token("T_COMMA");
						return COMMA;
					}
";"					{
						//print_token("T_SEMICOL");
						return SEMICOL;
					}
"="					{
						//print_token("T_ASSIGN");
						return ASSIGN;
					}
"=="					{
						//print_token("T_EQ");
						return EQ;
					}
"~="					{
						//print_token("T_NEQ");
						return NEQ;
					}
"<="					{
						//print_token("T_LTEQ");
						return LTEQ;
					}
">="					{
						//print_token("T_GTEQ");
						return GTEQ;
					}
"<"					{
						//print_token("T_LT");
						return LT;
					}
">"					{
						//print_token("T_GT");
						return GT;
					}
")"					{
						//print_token("T_CLOSEPAR");
						return CLOSEPAR;
					}
"("					{
						//print_token("T_OPENPAR");
						return OPENPAR;
					}

\n					yylineno++;
[ \t]+					;
.					{
						//print_error();
						yyerror("CARACTER NAO ESPERADO");
						return 1;
					}
%%

print_token(char *tokentype){
	if(flag_comma == 1){
		fprintf(yyout, "[%s, \"%s\"]", tokentype, yytext);
		flag_comma = 0;
	}
	else
		fprintf(yyout, ",\n[%s, \"%s\"]", tokentype, yytext);
}

print_error(){
	if(flag_comma == 1){
		fprintf(yyout, "LEXICAL ERROR AT LINE %d: %s", yylineno, yytext);
		flag_comma = 0;
	}
	else
		fprintf(yyout, ",\nLEXICAL ERROR AT LINE %d: %s", yylineno, yytext);
}

simple_comment(){
	char c;
	while((c = input()) != '\n');
	yylineno++;
}

complex_comment(){
	char c;
	while(1){
		c = input();
		if(c == '\n')
			yylineno++;
		if(c == '-'){
			c = input();
			if(c == '\n')
				yylineno++;
			if(c == '-'){
				c = input();
				if(c == '\n')
					yylineno++;
				if(c == ']')
					break;
			}
		}
	}
}

int yywrap(void) {
    return 1;
}

//int main(){
	//yyin = fopen(argv[1], "r");
	//yyout = fopen(argv[2], "w");
//	yylex();
	//fclose(yyin);
	//fprintf(yyout, "\n");
	//fclose(yyout);
	//return 0;
//}
