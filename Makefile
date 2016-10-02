all: 	parser.h scanner.l parser.y
	yacc -d parser.y
	lex -l scanner.l
	gcc lex.yy.c y.tab.c -o compilador

clean: 
	rm *.tab.c *.tab.h compilador
