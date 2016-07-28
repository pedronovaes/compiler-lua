#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern yylex();
extern int yylineno;
extern char *yytext;
extern FILE *yyin;

int main(int argc, char *argv[]){
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);
	return 0;
}