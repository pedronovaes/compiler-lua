%{

%}

%option yylineno
%option yywrap

letter					[a-zA-Z]
float					[0-9]+\.[0-9]+
number					[0-9]+
negativeno				\-({float}|{number})
id					[a-zA-Z_][a-zA-Z_0-9]*

%%

"and"					printf("[T_AND, \"%s\"],\n", yytext);
"not"					printf("[T_NOT, \"%s\"],\n", yytext);
"or"					printf("[T_OR, \"%s\"],\n", yytext);
"elseif"				printf("[T_ELSEIF, \"%s\"],\n", yytext);
"while"					printf("[T_WHILE, \"%s\"],\n", yytext);
"do"					printf("[T_DO, \"%s\"],\n", yytext);
"function"				printf("[T_FUNCTION, \"%s\"],\n", yytext);
"end"					printf("[T_END, \"%s\"],\n", yytext);
"for"					printf("[T_FOR, \"%s\"],\n", yytext);
"else"					printf("[T_ELSE, \"%s\"],\n", yytext);
"if"					printf("[T_IF, \"%s\"],\n", yytext);
"then"					printf("[T_THEN, \"%s\"],\n", yytext);
"return"				printf("[T_RETURN, \"%s\"],\n", yytext);
"local"					printf("[T_LOCAL, \"%s\"],\n", yytext);
"nil"					printf("[T_NIL, \"%s\"],\n", yytext);

{id}					printf("[T_NAME, \"%s\"],\n", yytext);
{float}					printf("[T_NUMBER, \"%s\"],\n", yytext);
{number}				printf("[T_NUMBER, \"%d\"],\n", atoi(yytext));
{negativeno}				printf("[T_NUMBER, \"%s\"],\n", yytext);

"+"					printf("[T_PLUS, \"%s\"],\n", yytext);
"-"					printf("[T_MINUS, \"%s\"],\n", yytext);
"*"					printf("[T_TIMES, \"%s\"],\n", yytext);
"/"					printf("[T_DIV, \"%s\"],\n", yytext);

","					printf("[T_COMMA, \"%s\"],\n", yytext);
";"					printf("[T_SEMICOL, \"%s\"],\n", yytext);
"="					printf("[T_ASSIGN, \"%s\"],\n", yytext);
"=="					printf("[T_EQ, \"%s\"],\n", yytext);
"~="					printf("[T_NEQ, \"%s\"],\n", yytext);
"<="					printf("[T_LTEQ, \"%s\"],\n", yytext);
">="					printf("[T_GTEQ, \"%s\"],\n", yytext);
"<"					printf("[T_LT, \"%s\"],\n", yytext);
">"					printf("[T_GT, \"%s\"],\n", yytext);
")"					printf("[T_CLOSEPAR, \"%s\"],\n", yytext);
"("					printf("[T_OPENPAR, \"%s\"],\n", yytext);

\n					yylineno++;
[ \t]+					;
.					{
						printf("LEXICAL ERROR AT LINE %d: %s\n", yylineno, yytext);
						//return 1;
					}								 

%%

int yywrap(void){
	return 1;
}
