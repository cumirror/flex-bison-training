all:
	make prepare 
	gcc -o test lex.sig.c sig.tab.c key_pair.c application.c test.c

clean:
	rm -f lex.sig.c sig.tab.c sig.tab.h 
	rm -f test

prepare: sig.tab.c lex.sig.c

sig.tab.c: sig.y 
	bison -d -o sig.tab.c sig.y

lex.sig.c: sig.l 
	flex -o lex.sig.c sig.l

