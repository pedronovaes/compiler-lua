all: 	scanner.l parser.y y.tab.c lex.yy.c 
	bison -d parser.y
	flex -l scanner.l
	gcc lex.yy.c y.tab.c -o compiler
