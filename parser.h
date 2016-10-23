typedef struct treeNode{
	int num_filhos;
	int tokenNumber;
	int number;
	char *id;
	char *nonTerminal;
	struct treeNode **filhos;
} tipoTree;

typedef struct listaV{
	char varName[20];
	int varValue;
	struct listaV *prox;
} listaVar;

typedef struct listaF
{
	char fname[20];
	int n_param;
	struct listaF *prox;
} listaFuncs;

typedef  struct context {
	int id;
	char name[20];
	listaVar *vars;
	listaFuncs *funcs;

}localContext;
