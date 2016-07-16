%{

#include <stdio.h>

%}

digito			[0-9]
letra			[a-zA-Z]

%%

[0-9]+			printf("Numero\n");
[a-zA-Z]+		printf("Letra\n");
.				;								 

%%

int yywrap(void){
	return 1;
}

int main(void){

	yylex();

	return 1;
}