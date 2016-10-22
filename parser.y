%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "parser.h"

#define YYDEBUG 1

extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
tipoTree * cria_node(char nonT[20], int n_filhos, ...);
tipoTree * terminalNumber(int token_n);
tipoTree * terminalToken(char id[20], int token_n);
char * consultaToken(int token_n);
void yyerror(char *string);

tipoTree *treeRoot = NULL;
localContext globalContext;

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
//					fprintf(yyout,"[programa ");
					// printTree(treeRoot);
//					fprintf(yyout,"]");
					//Inicializacao MIPS
					fprintf(yyout, "\n.data\n");
					fprintf(yyout, "_newline: .asciiz \"\\n\"\n");
					fprintf(yyout,".text\n");
					fprintf(yyout,".globl main\n\n");
					fprintf(yyout,"main:\n");

					geraCode(treeRoot);
					fprintf(yyout, "\nli $v0, 10\n");
					fprintf(yyout, "syscall");
					fprintf(yyout,"\n");
				}
		};

// bloco	: {$$ = NULL;}
		// | comando bloco { $$ = cria_node("bloco", 2, $1, $2); }
		// | comandoret { $$ = cria_node("bloco", 1, $1); }
		// ;
programa : bloco { $$ = cria_node("bloco", 1, $1); }
		;
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
		// | IF exp THEN bloco %prec END { $$ = cria_node("comando", 5, terminalToken("if", IF), $2, terminalToken("then", THEN), $4, terminalToken("end", END)); }
		| IF exp THEN bloco elseif else END { $$ = cria_node("comando", 7, terminalToken("if", IF), $2, terminalToken("then", THEN), $4, $5, $6, terminalToken("end", END)); }
		| FUNCTION NAME OPENPAR optionListanome CLOSEPAR bloco END {$$ = cria_node("comando", 7, terminalToken("function", FUNCTION), terminalToken($2, NAME), terminalToken("(", OPENPAR), $4, terminalToken(")", CLOSEPAR), $6, terminalToken("end", END)); }
		| LOCAL listadenomes assignlistaexp { $$ = cria_node("comando", 3, terminalToken("local", LOCAL), $2, $3); }
		;

otherexp: { $$ = NULL; }
		| COMMA exp { cria_node("listaexp", 2, terminalToken(",", COMMA), $2); }
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
			return "T_ WHILE";
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

int printTreeNew(tipoTree *p){

	if(p == NULL)
		return 0;
	if(p->nonTerminal != NULL && p->num_filhos != 1){
		fprintf(yyout,"[%s ", p->nonTerminal);
	}
	else if (p->num_filhos != 1)
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
	if (p->num_filhos != 1)
		fprintf(yyout,"]");
}

int geraCodeOpBin(tipoTree *p){

	int i;
	if (p == NULL)
		return 0;
	if( strcmp(p->nonTerminal,"opbin") == 0 ){

		//resolve primeiro filho
		if (p->filhos[0]->tokenNumber == NUMBER) {

			//Primeiro fator eh um numero
			fprintf(yyout,"li $a0, %d\n", p->filhos[0]->number);
			fprintf(yyout,"sw $a0, 0($sp)\n");
			fprintf(yyout,"addiu $sp, $sp, -4\n");
		}
		else
		{
			//Primeiro fator espera um resultado
			if ( strcmp(p->filhos[0]->nonTerminal, "exp") == 0 ){
				geraCodeOpBin(p->filhos[0]->filhos[1]);
				fprintf(yyout,"sw $a0, 0($sp)\n");
				fprintf(yyout,"addiu $sp, $sp, -4\n");
			}
			else{
				geraCodeOpBin(p->filhos[0]);
				fprintf(yyout,"sw $a0, 0($sp)\n");
				fprintf(yyout,"addiu $sp, $sp, -4\n");
			}
		}
		if (p->filhos[2]->tokenNumber == NUMBER) {

			//Segundo fator eh um numero
			fprintf(yyout,"li $a0, %d\n", p->filhos[2]->number);
			fprintf(yyout,"sw $a0, 0($sp)\n");
			fprintf(yyout,"addiu $sp, $sp, -4\n");
		}
		else
		{

			if ( strcmp(p->filhos[2]->nonTerminal, "exp") == 0 ){
				geraCodeOpBin(p->filhos[2]->filhos[1]);
				fprintf(yyout,"sw $a0, 0($sp)\n");
				fprintf(yyout,"addiu $sp, $sp, -4\n");
			}
			else
			{
				//Segundo fator espera um resultado
				geraCodeOpBin(p->filhos[2]);
				fprintf(yyout,"sw $a0, 0($sp)\n");
				fprintf(yyout,"addiu $sp, $sp, -4\n");
			}
		}
		//Opera fatores
		fprintf(yyout,"lw $t1, 4($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, 4\n");
		fprintf(yyout,"lw $a0, 4($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, 4\n");

		if(p->filhos[1]->tokenNumber == PLUS)
			fprintf(yyout,"add $a0, $a0, $t1\n");
		else if(p->filhos[1]->tokenNumber == MINUS)
			fprintf(yyout,"sub $a0, $a0, $t1\n");
		else if(p->filhos[1]->tokenNumber == TIMES)
		{
			fprintf(yyout,"mult $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
		}
		else if(p->filhos[1]->tokenNumber == DIV){
			fprintf(yyout,"div $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
		}
	}
	else if(p->filhos[0]->tokenNumber == NUMBER)
	{
		fprintf(yyout, "li $a0, %d\n",p->filhos[0]->number);
		return 0;
	}
	else
	{
		for(i = 0; i < p->num_filhos; i++)

			if (p->filhos[i] != NULL) {
				geraCodeOpBin(p->filhos[i]);
			}
	}
}

int geraCode(tipoTree *p){

	int i;
	if(p == NULL)
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

	if(p->filhos[0]->nonTerminal != NULL)
	{
		for(i = 0; i < p->num_filhos; i++){
				geraCode(p->filhos[i]);
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
	fclose(yyin);
	fclose(yyout);
}
