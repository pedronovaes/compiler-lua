%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
						if(flag_comma == 1){
							fprintf(yyout, "[T_AND, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_AND, \"%s\"]", yytext);
						//return AND;
					}
"not"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_NOT, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_NOT, \"%s\"]", yytext);
						//return NOT;
					}
"or"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_OR, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_OR, \"%s\"]", yytext);
						//return OR;
					}
"elseif"				{
						if(flag_comma == 1){
							fprintf(yyout, "[T_ELSEIF, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_ELSEIF, \"%s\"]", yytext);
						//return ELSEIF;
					}
"while"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_WHILE, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_WHILE, \"%s\"]", yytext);
						//return WHILE;
					}
"do"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_DO, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_DO, \"%s\"]", yytext);
						//return DO;
					}
"function"				{
						if(flag_comma == 1){
							fprintf(yyout, "[T_FUNCTION, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_FUNCTION, \"%s\"]", yytext);
						//return FUNCTION;
					}
"end"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_END, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_END, \"%s\"]", yytext);
						//return END;
					}
"for"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_FOR, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_FOR, \"%s\"]", yytext);
						//return FOR;
					}
"else"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_ELSE, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_ELSE, \"%s\"]", yytext);
						//return ELSE;
					}
"if"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_IF, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_IF, \"%s\"]", yytext);
						//return IF;
					}
"then"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_THEN, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_THEN, \"%s\"]", yytext);
						//return THEN;
					}
"return"				{
						if(flag_comma == 1){
							fprintf(yyout, "[T_RETURN, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_RETURN, \"%s\"]", yytext);
						//return RETURN;
					}
"local"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_LOCAL, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_LOCAL, \"%s\"]", yytext);
						//return LOCAL;
					}
"nil"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_NIL, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_NIL, \"%s\"]", yytext);
						//return NIL;
					}

{id}					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_NAME, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_NAME, \"%s\"]", yytext);
						//return NAME;
					}
{float}					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_NUMBER, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_NUMBER, \"%s\"]", yytext);
						//return NUMBER;
					}
{number}				{
						if(flag_comma == 1){
							fprintf(yyout, "[T_NUMBER, \"%d\"]", atoi(yytext));
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_NUMBER, \"%d\"]", atoi(yytext));
						//return NUMBER;
					}

"+"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_PLUS, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_PLUS, \"%s\"]", yytext);
						//return PLUS;
					}
"-"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_MINUS, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_MINUS, \"%s\"]", yytext);
						//return MINUS;
					}
"*"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_TIMES, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_TIMES, \"%s\"]", yytext);
						//return TIMES;
					}
"/"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_DIV, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_DIV, \"%s\"]", yytext);
						//return DIV;
					}

","					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_COMMA, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_COMMA, \"%s\"]", yytext);
						//return COMMA;
					}
";"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_SEMICOL, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_SEMICOL, \"%s\"]", yytext);
						//return SEMICOL;
					}
"="					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_ASSIGN, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_ASSIGN, \"%s\"]", yytext);
						//return ASSIGN;
					}
"=="					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_EQ, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_EQ, \"%s\"]", yytext);
						//return EQ;
					}
"~="					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_NEQ, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_NEQ, \"%s\"]", yytext);
						//return NEQ;
					}
"<="					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_LTEQ, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_LTEQ, \"%s\"]", yytext);
						//return LTEQ;
					}
">="					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_GTEQ, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_GTEQ, \"%s\"]", yytext);
						//return GTEQ;
					}
"<"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_LT, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_LT, \"%s\"]", yytext);
						//return LT;
					}
">"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_GT, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_GT, \"%s\"]", yytext);
						//return GT;
					}
")"					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_CLOSEPAR, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_CLOSEPAR, \"%s\"]", yytext);
						//return CLOSEPAR;
					}
"("					{
						if(flag_comma == 1){
							fprintf(yyout, "[T_OPENPAR, \"%s\"]", yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\n[T_OPENPAR, \"%s\"]", yytext);
						//return OPENPAR;
					}

\n					yylineno++;
[ \t]+					;
.					{
						if(flag_comma == 1){
							fprintf(yyout, "LEXICAL ERROR AT LINE %d: %s", yylineno, yytext);
							flag_comma = 0;
						}else
							fprintf(yyout, ",\nLEXICAL ERROR AT LINE %d: %s", yylineno, yytext);
						//return 1;
					}
%%

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

int yywrap(){
	return 1;
}

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	yylex();
	fclose(yyin);
	fprintf(yyout, "\n");
	fclose(yyout);
	return 0;
}
