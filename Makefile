all: scanner.l
	flex scanner.l
	gcc -o compilador lex.yy.c
