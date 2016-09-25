%{ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "parser.h"

#define YYDEBUG 1

extern FILE *yyin;

int yylex(void);
tipoTree * cria_node(int token_n, int n_filhos, ...);
tipoTree * terminalNumber(int token_n);
tipoTree * terminalToken(char *id);
void yyerror(char *string);

tipoTree *treeRoot = NULL;

%}

%union {
	tipoTree *treePointer;
	int integer; 
	char id[20];
};

%token SEMICOL ASSIGN 
%token DO END WHILE
%token FOR COMMA
%token IF THEN FUNCTION ELSEIF ELSE
%token OPENPAR CLOSEPAR
%token LOCAL RETURN NIL
%token TIMES MINUS PLUS DIV LT LTEQ GT GTEQ EQ NEQ AND OR
%token BLOCO
%token FUNCALL
%token COMANDO_N
%token RETURN_N
%token EXP_N
%token LIST_N
%token LISTEXP_N
%token NOT
%token COMMENT
%token C_COMMENT

%token <id> NAME
%token <integer> NUMBER
%type <treePointer> programa bloco comando otherexp elseif else optionListanome assignlistaexp comandoret optionListaexp optionSemicol exp chamadadefuncao listadenomes commaNome listaexp commaExp

//%nonassoc IFX
//%nonassoc ELSE

%left AND 
%left OR
%left LT GT LTEQ GTEQ EQ NEQ
%left OPENPAR CLOSEPAR
%left TIMES DIV
%left PLUS MINUS

%right NOT

%start programa

%%

programa: bloco { treeRoot = $1; printTree(treeRoot); }
		;

bloco	: {$$ = NULL;}
		| comando bloco { $$ = cria_node(BLOCO, 2, $1, $2); }
		| comandoret { $$ = cria_node(BLOCO, 1, $1); }
		;

comando	: SEMICOL { $$ = cria_node(COMANDO_N, 1, ";");}
		| listadenomes ASSIGN listaexp {$$ = cria_node(ASSIGN, 2, $1, $3); }
		| chamadadefuncao {$$ = cria_node(COMANDO_N, 1, $1); }
		| DO bloco END {$$ = cria_node(COMANDO_N, 3, terminalToken("do"), terminalToken("end")); }
		| WHILE exp DO bloco END {$$ = cria_node(COMANDO_N, 5, terminalToken("while"), $2, terminalToken("do"), $4, terminalToken("end")); }
		| FOR NAME ASSIGN exp COMMA exp otherexp DO bloco END {$$ = cria_node(COMANDO_N, 10, terminalToken("for"), terminalToken($2), terminalToken("="), $4, terminalToken(","), $6, $7, terminalToken("do"), $9, terminalToken("end") ); }
		| IF exp THEN bloco elseif else END { $$ = cria_node(COMANDO_N, 7, terminalToken("if"), $2, terminalToken("then"), $4, $5, $6, terminalToken("end")); }
		| FUNCTION NAME OPENPAR optionListanome CLOSEPAR bloco END {$$ = cria_node(FUNCALL, 7, terminalToken("function"), terminalToken($2), terminalToken("("), $4, terminalToken(")"), $6, terminalToken("end")); }
		| LOCAL listadenomes assignlistaexp { $$ = cria_node(COMANDO_N, 3, terminalToken("local"), $2, $3); }
		;

otherexp: { $$ = NULL; }
		| COMMA exp { cria_node(LISTEXP_N, 2, terminalToken(","), $2); }
		;

elseif	: { $$ = NULL; }
		| elseif ELSEIF exp THEN bloco { $$ = cria_node(COMANDO_N, 5, $1, terminalToken("elseif"), $3, terminalToken("then"), $5); }
		;

else	: {$$ = NULL; }
		| ELSE bloco { $$ = cria_node(COMANDO_N, 2, terminalToken("else"), $2); }
		;

optionListanome	: {$$ = NULL;}
		| listadenomes { $$ = cria_node(LIST_N, 1, $1); }
		;

assignlistaexp	: { $$ = NULL;}
		| ASSIGN listaexp { $$ = cria_node(ASSIGN, 2, terminalToken("="), $2); }
		;

comandoret	: RETURN optionListaexp optionSemicol { $$ = cria_node(RETURN_N, 3, terminalToken("return"), $2, $3); }
		;

optionListaexp	: { $$ = NULL; }
		| listaexp { $$ = cria_node(LIST_N, 1, $1); }
		;

optionSemicol	: { $$ = NULL; }
		| SEMICOL { $$ = terminalToken(";"); }
		;

/*exp	: NUMBER { $$ = terminalNumber($1); }
		| NAME { $$ = terminalToken($1); }
		| NIL { $$ = terminalToken("nil"); }
		| chamadadefuncao { $$ = cria_node(FUNCALL, 1, $1); }
		| exp opbin exp { $$ = cria_node(LISTEXP_N, 3, $1, $2 ,$3); }
		| opunaria exp { $$ = cria_node(EXP_N, 2, $1, $2); }
		| OPENPAR exp CLOSEPAR { $$ = cria_node(EXP_N, 3,terminalToken("("), $2, terminalToken(")")); }
		;
*/

chamadadefuncao	: NAME OPENPAR optionListaexp CLOSEPAR { $$ = cria_node(FUNCALL, 4,terminalToken($1), terminalToken("("), $3, terminalToken(")")); }
				;

listadenomes	: NAME commaNome { $$ = cria_node(LIST_N, 2, terminalToken($1), $2); }
				;

commaNome	: { $$ = NULL;}
			| commaNome COMMA NAME { $$ = cria_node(COMMA, 3, $1, terminalToken(","), terminalToken($3)); }
			;

listaexp	: exp commaExp { $$ = cria_node(LIST_N, 2,$1, $2); }
			;

commaExp	: { $$ = NULL; }
			| commaExp COMMA exp { $$ = cria_node(EXP_N, 3, $1, terminalToken(","), $3); }
			;

exp		: NUMBER { $$ = terminalNumber($1); }
		| NAME { $$ = terminalToken($1); }
		| NIL { $$ = terminalToken("nil"); }
		| chamadadefuncao { $$ = cria_node(FUNCALL, 1, $1); }
		| exp PLUS exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("+"), $3); }
		| exp MINUS exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("-"), $3); }
		| exp TIMES exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("*"), $3); }
		| exp DIV exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("/"), $3); }
		| exp OR exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("or"), $3); }
		| exp AND exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("and"), $3); }
		| exp LT exp  { $$ = cria_node(EXP_N, 3, $1, terminalToken("<"), $3); }
		| exp LTEQ exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("<="), $3); }
		| exp GT exp { $$ = cria_node(EXP_N, 3, $1, terminalToken(">"), $3); }
		| exp GTEQ exp { $$ = cria_node(EXP_N, 3, $1, terminalToken(">="), $3); }
		| exp EQ exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("=="), $3); }
		| exp NEQ exp { $$ = cria_node(EXP_N, 3, $1, terminalToken("~="), $3); }
		| NOT exp  { $$ = cria_node(EXP_N, 2, terminalToken("not"), $2); }
		| MINUS exp  { $$ = cria_node(EXP_N, 2, terminalToken("-"), $2); }
		| OPENPAR exp CLOSEPAR { $$ = cria_node(EXP_N, 3,terminalToken("("), $2, terminalToken(")")); }
		;

/*opbin	: PLUS { $$ = terminalToken("+"); }
		| MINUS { $$ = terminalToken("-"); }
		| TIMES { $$ = terminalToken("*"); }
		| DIV { $$ = terminalToken("/"); }
		| LT { $$ = terminalToken("<"); }
		| LTEQ { $$ = terminalToken("<="); }
		| GT { $$ = terminalToken(">"); }
		| GTEQ { $$ = terminalToken(">="); }
		| EQ { $$ = terminalToken("=="); }
		| NEQ { $$ = terminalToken("~="); }
		| AND { $$ = terminalToken("and"); }
		| OR { $$ = terminalToken("or"); }
		;

opunaria: MINUS { $$ = terminalToken("-"); }
		| NOT { $$ = terminalToken("not"); }
		;
*/

%%

tipoTree * cria_node(int token_n, int n_filhos, ...){

	va_list params;
	int i = 0;
	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->tokenNumber = token_n;
	aux->num_filhos = n_filhos;
	aux->filhos = malloc(n_filhos * sizeof(struct treeNode));

	va_start(params, n_filhos);
	while(i < n_filhos)
	{
		aux->filhos[i] = va_arg(params, tipoTree*);
		i++;
	}
	
	va_end(params);
	return aux;
}

tipoTree * terminalNumber(int token_n){

	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	aux->tokenNumber = NUMBER;
	aux->number = token_n;
	aux->id = NULL;
	return aux;
}

tipoTree * terminalToken(char id[20]){
	
	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	//aux->tokenNumber = token_n;
	strcpy(aux->id, id);
	return aux;
}

void yyerror(char *string){  fprintf(stderr, "%s\n", string); }

int printTree(tipoTree *p){

	if(p == NULL)
		return 0;
	printf("[");
	if(p->num_filhos == 0)
	{
		if (p->tokenNumber == NUMBER)
			printf("%d %d", p->tokenNumber, p->number);
		else if(p->tokenNumber == NAME)
			printf("%d %s", p->tokenNumber, p->id);
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			printTree(p->filhos[i]);
	}
	printf("]");
}

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");

	if(!yyin) printf("Deu ruim!\n");

	yyparse();
}