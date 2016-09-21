%{ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

struct treeNode {
	int tokenNumber;
	int num_filhos;
	int number;
	char id[20];
	struct treeNode **filhos;
};

void yyerror(char *string);
struct treeNode * cria_node(int token_n, int n_filhos, ...);
struct treeNode * terminalNumber(int token_n, int token);
struct treeNode * terminalToken(int token_n, char *id);


struct treeNode *treeRoot = NULL;

%}


%union {
	int integer; 
	char id[20];
	treeNode *treePointer;
};

%start programa

%token SEMICOL ASSIGN 
%token DO END WHILE
%token FOR COMMA
%token IF THEN FUNCTION NAME ELSEIF ELSE
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

%token <id> NAME
%token <integer> NUMBER
%type <treePointer> programa bloco comando comandorep exp chamadadefuncao listadenomes listaexp opbin opunaria othername otherexp otherexp2 othersemicol elseif otherelse otherlista otherlista2 otherlistaexp

//%nonassoc IFX
//%nonassoc ELSE

%left OR
%left AND 
%left LT GT LTEQ GTEQ EQ NEQ
%left PLUS MINUS
%left TIMES DIV
%left OPENPAR CLOSEPAR

%%

programa	: bloco { treeRoot = $1; }
		;

bloco		: comando bloco comandoret { $$ = cria_node(BLOCO, 3, $1, $2, $3); }
		|
		;
comando		: SEMICOL { $$ = cria_node(SEMICOL, 1, terminalToken($1)); }
		| listadenomes ASSIGN listaexp { $$ = cria_node(ASSIGN, 2, $1, $3); }
		| chamadadefuncao { $$ = cria_node(FUNCALL,1,$1); }
		| DO bloco END { $$ = cria_node(BLOCO, 3, terminalToken($1), $2, terminalToken($3)); }
		| WHILE exp DO bloco END { $$ = cria_node(COMANDO_N, terminalToken($1), $2, terminalToken($3), $4, terminalToken($5)); }
		| FOR NAME ASSIGN exp COMMA exp otherexp DO bloco END {$$ = cria_node(COMANDO_N, 10, terminalToken($1), terminalToken($2), terminalToken($3), $4, terminalToken($5), $6, $7, terminalToken($8), $9, terminalToken($10) ); }
		| IF exp THEN bloco elseif otherelse END { $$ = cria_node(COMANDO_N, 7, terminalToken($1), $2, terminalToken($3), $4, $5, $6, terminalToken($7)); }
		| FUNCTION NAME OPENPAR otherlista CLOSEPAR bloco END { $$ = cria_node(COMANDO_N, 7, terminalToken($1), terminalToken($2), terminalToken($3), $4, terminalToken($5), $6, terminalToken($7)); }
		| LOCAL listadenomes otherlista2 { $$ = cria_node(COMANDO_N, 3, terminalToken($1), $2, $3); }
		;

comandoret	: RETURN otherlistaexp othersemicol { $$ = cria_node(RETURN_N, 3, terminalToken($1), $2, $3); }
		;

exp		: NUMBER { $$ = terminalNumber($1); }
		| NAME { $$ = terminalToken($1); }
		| NIL { $$ = terminalToken($1); }
		| chamadadefuncao { $$ = cria_node(FUNCALL, 0,$1) }
		| exp opbin exp { $$ = cria_node(EXP_N, 3, $1, $2, $3); }
		| opunaria exp { $$ = cria_node(EXP_N, 2, $1, $2); }
		| OPENPAR exp CLOSEPAR { $$ = cria_node(EXP_N, 3, terminalToken($1), $2, terminalToken($3)); }
		;

chamadadefuncao	: NAME OPENPAR otherlistaexp CLOSEPAR { $$ = cria_node(FUNCALL, 4, terminalToken($1), terminalToken($2), $3, terminalToken($4)); }
		;

listadenomes	: NAME othername { $$ = cria_node(LIST_N, 2, terminalToken($1), $2); }
		;

listaexp	: exp otherexp2 { $$ = cria_node(LISTEXP_N, 2, $1, $2); }
		;

opbin		: TIMES { $$ = terminalToken($1); }
		| MINUS { $$ = terminalToken($1); }
		| PLUS { $$ = terminalToken($1); }
		| DIV { $$ = terminalToken($1); }
		| LT { $$ = terminalToken($1); }
		| LTEQ { $$ = terminalToken($1); }
		| GT { $$ = terminalToken($1); }
		| GTEQ { $$ = terminalToken($1); }
		| EQ { $$ = terminalToken($1); }
		| NEQ { $$ = terminalToken($1); }
		| AND { $$ = terminalToken($1); }
		| OR { $$ = terminalToken($1); }
		;

opunaria	: MINUS { $$ = terminalToken($1); }
		| NOT { $$ = terminalToken($1); }
		;

othername	: COMMA listadenomes { $$ = cria_node(COMMA, 2, terminalToken($1), $2); }
		|
		;

otherexp	: COMMA exp { $$ = cria_node(COMMA, 2, terminalToken($1), $2); }
		|
		;

otherexp2	: COMMA listaexp { $$ = cria_node(COMMA, 2, terminalToken($1), $2); }
		|
		;

othersemicol	: SEMICOL {$$ = terminalToken($1)}
		|
		;

elseif		: ELSEIF exp THEN bloco elseif { $$ = cria_node(COMANDO_N, 5, terminalToken($1), $2, terminalToken($3), $4, $5); }
		|
		;

otherelse	: ELSE bloco { $$ = cria_node(ELSE, 2, terminalToken($1), $2); }
		|
		;

otherlista	: listadenomes { $$ = cria_node(LIST_N, 0,$1) }
		|
		;

otherlista2	: ASSIGN listaexp { $$ = cria_node(ASSIGN, 2, terminalToken($1), $2); }
		|
		;

otherlistaexp	: listaexp { $$ = cria_node(LISTEXP_N, 0, $1) }
		|
		;

%%

struct treeNode * cria_node(int token_n, int n_filhos, ...){

	va_list params;
	int i = 0;
	struct treeNode *aux = malloc(sizeof(struct treeNode));
	aux->tokenNumber = token;
	aux->num_filhos = n_filhos;
	aux->filhos = malloc(n_filhos * sizeof(struct treeNode));

	va_start(ap, n_filhos);
	while(i < n_filhos)
	{
		aux->filhos[i] = va_arg(params, treeNode*);
		i++;
	}
	
	va_end(params);
	return aux;
}

struct treeNode * terminalNumber(int token_n, int token){

	struct treeNode *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	aux->tokenNumber = token_n;
	aux->number = token;
	aux->id = NULL;
	return aux;
}

struct treeNode * terminalToken(int token_n, char *id){
	
	struct treeNode *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	aux->tokenNumber = token_n;
	strcpy(aux->id, id);
	return aux;

}

void yyerror(char *string){  fprintf(stderr, "%s\n", string); }