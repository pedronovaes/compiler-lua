#include <stdio.h>
#include "newScanner.h"

extern int yylex();
extern int yylineno();
extern char* yytext;

char *tokensNames[] = {NULL,"and", "not", "or", "elseif", "while", "do", "function", "end", "for", "else", "if", "then", "return", "local", "nil", "id", "number", "token_plus","token_minus", "token_mul", "token_div", "token_assign", "token_equal", "token_notequal", "token_lessequal", "token_greaterequal", "token_less", "token_greater", "token_rparen", "token_lparen"};


int main(){

	int name_token, value_token;

	value_token = yylex();
	while(value_token){
		
		printf("%d %s\n", value_token, tokensNames[value_token]);
		value_token = yylex();
	}
	return 0;
}
