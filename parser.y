%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "parser.h"

#define YYDEBUG 1

int cont_while = 0;
int cont_for = 0;

extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
tipoTree * cria_node(char nonT[20], int n_filhos, ...);
tipoTree * terminalNumber(int token_n);
tipoTree * terminalToken(char id[20], int token_n);
char * consultaToken(int token_n);
void yyerror(char *string);

int insereVar(listaVar **p, char *id, int value);
listaVar * consultaVar(listaVar *p, char *id);
int consultaFuncs(listaFuncs *p, char *id);
int insereFunc(listaFuncs **p, char *id);
int assignValues(tipoTree *p);

tipoTree *treeRoot = NULL;
listaVar *vars = NULL;
listaFuncs *funcs = NULL;
int G_NUM = 1;
int G_ACC = 0;

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
%type <treePointer> programa bloco bloco2 bloco3 comando otherexp elseif else optionListanome assignlistaexp comandoret optionListaexp optionSemicol exp chamadadefuncao listadenomes commaNome listaexp commaExp

%left AND
%left OR
%left LT GT LTEQ GTEQ EQ NEQ
%left OPENPAR CLOSEPAR
%left PLUS MINUS
%left TIMES DIV

%right NOT

%start programa

%%

programa: bloco {
				if($1 != NULL){
					$$ = cria_node("programa", 1, $1);
					treeRoot = $$;
				}
		};

// bloco	: {$$ = NULL;}
		// | comando bloco { $$ = cria_node("bloco", 2, $1, $2); }
		// | comandoret { $$ = cria_node("bloco", 1, $1); }
		// ;
bloco	: comando bloco2 {$$ = cria_node("bloco", 2, $1, $2); }
		| bloco3 {$$ = cria_node("bloco", 1, $1);}
		;

bloco2 	: comando bloco2 { $$ = cria_node("comando", 2, $1, $2);}
		| bloco3 { $$ = NULL;}
		;
bloco3 	: { $$ = NULL; }
		| comandoret { $$ = cria_node("bloco", 1, $1); }
		;

comando	: SEMICOL { $$ = terminalToken(";", SEMICOL); }
		| listadenomes ASSIGN listaexp {$$ = cria_node("comando", 3, $1, terminalToken("=", ASSIGN), $3); }
		| chamadadefuncao {$$ = cria_node("comando", 1, $1); }
		| DO bloco END {$$ = cria_node("comando", 3, terminalToken("do", DO), terminalToken("end", END)); }
		| WHILE exp DO bloco END {$$ = cria_node("comando", 5, terminalToken("while", WHILE), $2, terminalToken("do", DO), $4, terminalToken("end", END)); }
		| FOR NAME ASSIGN exp COMMA exp otherexp DO bloco END {$$ = cria_node("comando", 10, terminalToken("for", FOR), terminalToken($2, NAME), terminalToken("=", ASSIGN), $4, terminalToken(",", COMMA), $6, $7, terminalToken("do", DO), $9, terminalToken("end", END) ); }
		| IF exp THEN bloco elseif else END { $$ = cria_node("comando", 7, terminalToken("if", IF), $2, terminalToken("then", THEN), $4, $5, $6, terminalToken("end", END)); }
		| FUNCTION NAME OPENPAR optionListanome CLOSEPAR bloco END {$$ = cria_node("comando", 7, terminalToken("function", FUNCTION), terminalToken($2, NAME), terminalToken("(", OPENPAR), $4, terminalToken(")", CLOSEPAR), $6, terminalToken("end", END)); }
		| LOCAL listadenomes assignlistaexp { $$ = cria_node("comando", 3, terminalToken("local", LOCAL), $2, $3); }
		;

otherexp: { $$ = NULL; }
		| COMMA exp {$$ = cria_node("listaexp", 2, terminalToken(",", COMMA), $2); }
		;

elseif	: { $$ = NULL; }
		| elseif ELSEIF exp THEN bloco { $$ = cria_node("elseif", 5, $1, terminalToken("elseif", ELSEIF), $3, terminalToken("then", THEN), $5); }
		;

else	: {$$ = NULL; }
		| ELSE bloco { $$ = cria_node("comando", 2, terminalToken("else", ELSE), $2); }
		;

optionListanome	: {$$ = NULL;}
		| listadenomes { $$ = cria_node("listadenomes", 1, $1); }
		;

assignlistaexp	: { $$ = NULL;}
		| ASSIGN listaexp { $$ = cria_node("listaexp", 2, terminalToken("=", ASSIGN), $2); }
		;

comandoret	: RETURN optionListaexp optionSemicol { $$ = cria_node("comandoret", 3, terminalToken("return", RETURN), $2, $3); }
		;

optionListaexp	: { $$ = NULL; }
		| listaexp { $$ = cria_node("listaexp", 1, $1); }
		;

optionSemicol	: { $$ = NULL; }
		| SEMICOL { $$ = terminalToken(";", SEMICOL); }
		;

chamadadefuncao	: NAME OPENPAR optionListaexp CLOSEPAR { $$ = cria_node("chamadadefuncao", 4,terminalToken($1, NAME), terminalToken("(", OPENPAR), $3, terminalToken(")", CLOSEPAR)); }
				;

listadenomes	: NAME commaNome { $$ = cria_node("listadenomes", 2, terminalToken($1, NAME), $2); }
				;

commaNome	: { $$ = NULL;}
			| commaNome COMMA NAME { $$ = cria_node("listadenomes", 3, $1, terminalToken(",", COMMA), terminalToken($3, NAME)); }
			;

listaexp	: exp commaExp { $$ = cria_node("listaexp", 2,$1, $2); }
			;

commaExp	: { $$ = NULL; }
			| commaExp COMMA exp { $$ = cria_node("listaexp", 3, $1, terminalToken(",", COMMA), $3); }
			;

exp		: NUMBER { $$ = terminalNumber($1); }
		| NAME { $$ = terminalToken($1, NAME); }
		| NIL { $$ = terminalToken("nil", NIL); }
		| chamadadefuncao { $$ = cria_node("chamadadefuncao", 1, $1); }
		| exp PLUS exp { $$ = cria_node("opbin", 3, $1, terminalToken("+", PLUS), $3); }
		| exp MINUS exp { $$ = cria_node("opbin", 3, $1, terminalToken("-", MINUS), $3); }
		| exp TIMES exp { $$ = cria_node("opbin", 3, $1, terminalToken("*", TIMES), $3); }
		| exp DIV exp { $$ = cria_node("opbin", 3, $1, terminalToken("/", DIV), $3); }
		| exp OR exp { $$ = cria_node("opbin", 3, $1, terminalToken("or", OR), $3); }
		| exp AND exp { $$ = cria_node("opbin", 3, $1, terminalToken("and", AND), $3); }
		| exp LT exp  { $$ = cria_node("opbin", 3, $1, terminalToken("<", LT), $3); }
		| exp LTEQ exp { $$ = cria_node("opbin", 3, $1, terminalToken("<=", LTEQ), $3); }
		| exp GT exp { $$ = cria_node("opbin", 3, $1, terminalToken(">", GT), $3); }
		| exp GTEQ exp { $$ = cria_node("opbin", 3, $1, terminalToken(">=", GTEQ), $3); }
		| exp EQ exp { $$ = cria_node("opbin", 3, $1, terminalToken("==", EQ), $3); }
		| exp NEQ exp { $$ = cria_node("opbin", 3, $1, terminalToken("~=", NEQ), $3); }
		| NOT exp  { $$ = cria_node("opunaria", 2, terminalToken("not", NOT), $2); }
		| MINUS exp  { $$ = cria_node("opunaria", 2, terminalToken("-", MINUS), $2); }
		| OPENPAR exp CLOSEPAR { $$ = cria_node("exp", 3,terminalToken("(", OPENPAR), $2, terminalToken(")", CLOSEPAR)); }
		;
%%

tipoTree * cria_node(char nonT[20], int n_filhos, ...){

	va_list params;
	int i = 0;
	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->nonTerminal = malloc(sizeof(char)*strlen(nonT));
	strcpy(aux->nonTerminal, nonT);
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

tipoTree * terminalToken(char id[20], int token_n){

	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	aux->tokenNumber = token_n;
	aux->id = malloc(sizeof(char)*strlen(id));
	strcpy(aux->id, id);
	return aux;
}

char * consultaToken(int token_n){

	switch( token_n ){
		case AND :
			return "T_AND";
			break;
		case  NOT:
			return "T_NOT";
			break;
		case OR:
			return "T_OR";
			break;
		case ELSEIF:
			return "T_ELSEIF";
			break;
		case WHILE:
			return "T_WHILE";
			break;
		case DO:
			return "T_DO";
			break;
		case FUNCTION:
			return "T_FUNCTION";
			break;
		case END:
			return "T_END";
			break;
		case FOR:
			return "T_FOR";
			break;
		case ELSE:
			return "T_ELSE";
			break;
		case IF:
			return "T_IF";
			break;
		case THEN:
			return "T_THEN";
			break;
		case RETURN:
			return "T_RETURN";
			break;
		case LOCAL:
			return "T_LOCAL";
			break;
		case NIL:
			return "T_NIL";
			break;
		case NAME:
			return "T_NAME";
			break;
		case NUMBER:
			return "T_NUMBER";
			break;
		case PLUS:
			return "T_PLUS";
			break;
		case MINUS:
			return "T_MINUS";
			break;
		case TIMES:
			return "T_TIMES";
			break;
		case DIV:
			return "T_DIV";
			break;
		case COMMA:
			return "T_COMMA";
			break;
		case SEMICOL:
			return "T_SEMICOL";
			break;
		case ASSIGN:
			return "T_ASSIGN";
			break;
		case EQ:
			return "T_EQ";
			break;
		case NEQ:
			return "T_NEQ";
			break;
		case LTEQ:
			return "T_LTEQ";
			break;
		case GTEQ:
			return "T_GTEQ";
			break;
		case LT:
			return "T_LT";
			break;
		case GT:
			return "T_GT";
			break;
		case CLOSEPAR:
			return "T_CLOSEPAR";
			break;
		case OPENPAR:
			return "T_OPENPAR";
			break;
		default :
			return "NONE";
	}
};

int insereVar(listaVar **p, char *id, int value){

	listaVar *aux = malloc(sizeof(struct listaV));
	strcpy(aux->varName, id);
	aux->varValue = value;
	aux->prox = *p;
	*p = aux;
}

listaVar * consultaVar(listaVar *p, char *id){

	listaVar *aux;
	for(aux = p; aux != NULL; aux = aux->prox){
		if( strcmp(aux->varName,id) == 0){
			return aux;
		}
	}
	return NULL;
}

int consultaFuncs(listaFuncs *p, char *id){

	listaFuncs *aux;
	for(aux = p; aux != NULL; aux = aux->prox){
		if( strcmp(aux->fname,id) == 0 ){
			return 1;
		}
	}
	return 0;
}

int insereFunc(listaFuncs **p, char *id){

	listaFuncs *aux = malloc(sizeof(struct listaF));
	strcpy(aux->fname, id);
	aux->prox = *p;
	*p = aux;
}

int updateVar(listaVar *p, char *id, int newValue){

	listaVar *aux = consultaVar(p, id);
	printf("foi?\n");
	if (aux != NULL)
		aux->varValue = newValue;
	else
		return -1;
	return 1;
}

void yyerror(char *string){  fprintf(stderr, "%s\n", string); }

int printTree(tipoTree *p){

	if(p == NULL)
		return 0;
	if(p->nonTerminal != NULL)
		fprintf(yyout,"[%s ", p->nonTerminal);
	else
		fprintf(yyout, "[");
	if(p->num_filhos == 0)
	{
		if (p->tokenNumber == NUMBER)
			fprintf(yyout, "%s %d", consultaToken(p->tokenNumber), p->number);
		else
			fprintf(yyout, "%s %s", consultaToken(p->tokenNumber), p->id);
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			printTree(p->filhos[i]);
	}
	fprintf(yyout,"]");
}


int geraCodeOpBin(tipoTree *p){

	int i,x,y;
	if (p == NULL)
		return 0;
	if (p->nonTerminal == NULL)
		return 0;

	printf("cheguei em %s\n", p->nonTerminal);
	if( strcmp(p->nonTerminal,"opbin") == 0 ){

		//resolve primeiro filho
		if (p->filhos[0]->tokenNumber == NUMBER){

			//Primeiro fator eh um numero
			fprintf(yyout,"li $a0, %d\n", p->filhos[0]->number);
			fprintf(yyout,"sw $a0, 0($sp)\n");
			fprintf(yyout,"addiu $sp, $sp, -4\n");
			x = p->filhos[0]->number;
		}
		else
		{
			//Primeiro fator espera um resultado
			if( p->filhos[0]->nonTerminal != NULL){
				if ( strcmp(p->filhos[0]->nonTerminal, "exp") == 0 ){
					geraCodeOpBin(p->filhos[0]->filhos[1]);
				}
				else{
					geraCodeOpBin(p->filhos[0]);
				}
				fprintf(yyout,"sw $a0, 0($sp)\n");
				fprintf(yyout,"addiu $sp, $sp, -4\n");
				x = G_ACC;
			}
			else
			{
				if(p->filhos[0]->tokenNumber == NAME){
					printf("achei a var %s\n", p->filhos[0]->id);
					listaVar *aux = consultaVar(vars, p->filhos[0]->id);
					if (aux == NULL)
						printf("Erro : var nao encontrada!!!!\n");
					else{
						fprintf(yyout, "l2 $a0, %s\n", aux->filhos[0]->id);
						fprintf(yyout, "sw $a0, 0($sp)\n");
						fprintf(yyout,"addiu $sp, $sp, -4\n");
					}
					x = aux->varValue;
				}
				else{
					// printf("entrei aqui dentro do %s\n", p->nonTerminal);
					geraCodeOpBin(p->filhos[2]);
					fprintf(yyout,"sw $a0, 0($sp)\n");
					fprintf(yyout,"addiu $sp, $sp, -4\n");
					x = G_ACC;
				}
			}
		}
		if (p->filhos[2]->tokenNumber == NUMBER) {
			printf("cheguei aqui tbm hein\n");
			//Segundo fator eh um numero
			fprintf(yyout,"li $a0, %d\n", p->filhos[2]->number);
			fprintf(yyout,"sw $a0, 0($sp)\n");
			fprintf(yyout,"addiu $sp, $sp, -4\n");
			y = p->filhos[2]->number;
		}
		else
		{
			if( p->filhos[2]->nonTerminal != NULL){
				if ( strcmp(p->filhos[2]->nonTerminal, "exp") == 0 ){
					printf("entrou em exp\n");
					geraCodeOpBin(p->filhos[2]->filhos[1]);
				}
				else{
					printf("gerei aqui\n");
					geraCodeOpBin(p->filhos[2]);
				}
				fprintf(yyout,"sw $a0, 0($sp)\n");
				fprintf(yyout,"addiu $sp, $sp, -4\n");
				y = G_ACC;
			}
			else
			{
				if(p->filhos[2]->tokenNumber == NAME){
					printf("achei a var %s\n", p->filhos[2]->id);
					listaVar *aux = consultaVar(vars, p->filhos[2]->id);
					if (aux == NULL)
						printf("Erro : var nao encontrada!!!!\n");
					else
					{
						fprintf(yyout, "lw $a0, %s\n", p->filhos[2]->id);
						fprintf(yyout, "sw $a0, 0($sp)\n");
						fprintf(yyout,"addiu $sp, $sp, -4\n");
					}
					y = aux->varValue;
				}
				else{
					// printf("entrei aqui dentro do %s\n", p->nonTerminal);
					geraCodeOpBin(p->filhos[2]);
					fprintf(yyout,"sw $a0, 0($sp)\n");
					fprintf(yyout,"addiu $sp, $sp, -4\n");
					y = G_ACC;
				}
			}
		}
		//Opera fatores
		fprintf(yyout,"lw $t1, 4($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, 4\n");
		fprintf(yyout,"lw $a0, 4($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, 4\n");

		if(p->filhos[1]->tokenNumber == PLUS){
			fprintf(yyout,"add $a0, $a0, $t1\n");
			G_ACC = x + y;
		}
		else if(p->filhos[1]->tokenNumber == MINUS)
		{
			fprintf(yyout,"sub $a0, $a0, $t1\n");
			G_ACC = x - y;
		}
		else if(p->filhos[1]->tokenNumber == TIMES)
		{
			fprintf(yyout,"mult $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
			G_ACC = x * y;
		}
		else if(p->filhos[1]->tokenNumber == DIV){
			fprintf(yyout,"div $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
			G_ACC = x/y;
		}
		else if(p->filhos[1]->tokenNumber == EQ)
		{
			fprintf(yyout, "seq $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == NEQ)
		{
			fprintf(yyout, "sne $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == GTEQ)
		{
			fprintf(yyout, "sge $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == GT)
		{
			fprintf(yyout, "sgt $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == LTEQ)
		{
			fprintf(yyout, "sle $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == LT)
		{
			printf("ta saindo da jaula\n");
			fprintf(yyout, "slt $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == AND)
		{
			fprintf(yyout, "and $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == OR)
		{
			fprintf(yyout, "or $a0, $a0, $t1\n");
		}
	}
	else if(p->filhos[0]->tokenNumber == NUMBER)
	{
		printf("achei o numero %d\n", p->filhos[0]->number);
		fprintf(yyout, "li $a0, %d\n",p->filhos[0]->number);
		G_ACC = p->filhos[0]->number;
		return 0;
	}
	else if(p->filhos[0]->tokenNumber == NAME){

		printf("achei a var %s\n", p->filhos[0]->id);
		listaVar *aux = consultaVar(vars, p->filhos[0]->id);
		if (aux == NULL)
			printf("Erro : var nao encontrada!!!!\n");
		else
		fprintf(yyout, "li $a0, %d\n", aux->varValue);

		G_ACC = aux->varValue;
	}
	else
	{

		for(i = 0; i < p->num_filhos; i++){
			if (p->filhos[i] != NULL) {
				geraCodeOpBin(p->filhos[i]);
			}
		}
	}
	return 0;
}

int trataVars(tipoTree *p){

	if(p == NULL)
		return 0;
	if(p->num_filhos == 0)
	{
		if ((p->tokenNumber == NAME) && (consultaVar(vars, p->id) == NULL) && !(consultaFuncs(funcs,p->id))){
			insereVar(&vars, p->id, 0);
			fprintf(yyout, "%s: .word 0\n");
		}
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			trataVars(p->filhos[i]);
	}
}

int trataFuncs(tipoTree *p){

	if(p == NULL)
		return 0;

	if( strcmp(p->nonTerminal,"comando") == 0){
		if(p->filhos[0]->id != NULL)
		{
			if( strcmp(p->filhos[0]->id, "function")){
				if(!consultaFuncs(funcs, p->filhos[1]->id))
					insereFunc(&funcs, p->filhos[1]->id);
			}
		}
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			trataFuncs(p->filhos[i]);
	}
}

// int buscaValor(tipoTree *p){
//
// }

// int buscaVar(tipoTree *p, tipoTree *q){
//
// 	int new_value, i;
// 	if(p == NULL)
// 		return 0;
// 	else if(p->nonTerminal == NULL){
// 		if (p->tokenNumber == NAME){
// 			new_value = buscaValor(q);
// 			updateVar(vars, p->id, new_value);
// 			G_NUM++;
// 		}
// 	}
// 	else
// 		for(i = 0; i < p->num_filhos; i++)
// 			buscaVar(p->filhos[i], q);
// }

int geraCode(tipoTree *p){

	int i;
	if(p == NULL)
		return 0;
	if(p->nonTerminal == NULL)
		return 0;

	printf("entrei em %s\n", p->nonTerminal);

	if( strcmp(p->nonTerminal, "chamadadefuncao") == 0 )
	{
		if( strcmp(p->filhos[0]->id, "print") == 0){
			printf("entrei no print\n");
			geraCode(p->filhos[2]);
			printf("saiu print\n");
			fprintf(yyout, "li $v0, 1\n");
			fprintf(yyout, "syscall\n");
		}
		return 0;
	}

	if( strcmp(p->nonTerminal, "listaexp") == 0 ){

		printf("entrei na listaexp\n");
		geraCodeOpBin(p);
		printf("sai de listaexp\n");
		return 0;
	}
	if( strcmp(p->nonTerminal, "comando") == 0){

		if (p->filhos[0]->id != NULL) {

			// gerando codigo para instrucao while
			if (strcmp(p->filhos[0]->id, "while") == 0) {
				cont_while++;
				fprintf(yyout, "true_bw%d:\n", cont_while);
				geraCodeOpBin(p->filhos[1]);
				fprintf(yyout, "li $t1, 0\n");
				fprintf(yyout, "beq $a0, $t1, false_bw%d\n", cont_while);
				geraCode(p->filhos[3]);
				fprintf(yyout, "j true_bw%d\n", cont_while);
				fprintf(yyout, "false_bw%d:\n", cont_while);
			}

			// gerando codigo para instrucao for
			// $t0 vai guardar a condicao inicial
			// $t2 vai guardar ate onde o loop deve ir
			// $t1 vai guardar o quanto deve incrementar por cada passada no for (se existir essa informacao)
			if (strcmp(p->filhos[0]->id, "for") == 0) {
				printf("entrei aqui\n");
				int tem_ramificacao = 0;
				cont_for++;
				geraCodeOpBin(p->filhos[3]);
				fprintf(yyout, "move $t0, $a0\n");
				printf("jeba\n");
				geraCodeOpBin(p->filhos[5]);
				fprintf(yyout, "move $t2, $a0\n");
				if (p->filhos[6] != NULL) {
					tem_ramificacao = 1;
					geraCodeOpBin(p->filhos[6]);
					fprintf(yyout, "move $t1, $a0\n");
				}

				if (tem_ramificacao == 1) {
					fprintf(yyout, "true_bf%d:\n", cont_for);
					geraCode(p->filhos[8]);
					fprintf(yyout, "beq $t0, $t2, false_bf%d\n", cont_for);
					fprintf(yyout, "add $t0, $t0, $t1\n");
					fprintf(yyout, "j true_bf%d\n", cont_for);

					fprintf(yyout, "false_bf%d:\n", cont_for);
				}
				else {
					fprintf(yyout, "true_bf%d:\n", cont_for);
					geraCode(p->filhos[8]);
					fprintf(yyout, "beq $t0, $t2, false_bf%d\n", cont_for);
					fprintf(yyout, "addiu $t1, 0\n");
					fprintf(yyout, "add $t0, $t0, $t1\n");
					fprintf(yyout, "j true_bf%d\n", cont_for);

					fprintf(yyout, "false_bf%d:\n", cont_for);
				}
			}
			return 0;
		}

		if(p->num_filhos == 3)
		{
			if(p->filhos[1]->tokenNumber == ASSIGN)
			{
				printf("entrei no assign\n");
				geraCodeOpBin(p->filhos[2]);
				listaVar *aux;
				int new_value = G_ACC;
				printf("saiu com valor: %d\n", new_value);
				printf("%s\n", p->filhos[0]->filhos[0]->id);
				aux = consultaVar(vars, p->filhos[0]->filhos[0]->id);
				aux->varValue = new_value;
				fprintf(yyout, "li $a0, %d\n", new_value);
				fprintf(yyout, "sw $a0, %s\n", p->id);
				printf("sai do assign\n");
			}
			return 0;
		}
	}
	if(p->filhos[0]->nonTerminal != NULL)
	{
		for(i = 0; i < p->num_filhos; i++){
			if(p->filhos[i] != NULL){
				printf("%d %s\n", i, p->nonTerminal);
				geraCode(p->filhos[i]);
			}
		}
	}
	printf("terminei os filhos de %s\n", p->nonTerminal);
}

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	if(!yyin) printf("Arquivo nao pode ser aberto!\n");
	else{
		yyparse();
	}

	//Inicialiazao de ambiente
	// printTree(treeRoot);
	insereFunc(&funcs, "print");
	trataFuncs(treeRoot);

	//Inicializacao MIPS
	fprintf(yyout, "\n.data\n");
	trataVars(treeRoot);
	fprintf(yyout, "\n");
	fprintf(yyout, "_newline: .asciiz \"\\n\"\n");
	fprintf(yyout,".text\n");
	fprintf(yyout,".globl main\n\n");
	fprintf(yyout,"main:\n");
	geraCode(treeRoot);

	fprintf(yyout, "\nli $v0, 10\n");
	fprintf(yyout, "syscall");
	fprintf(yyout,"\n");

	fclose(yyin);
	fclose(yyout);

	return 0;
}
