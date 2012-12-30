main: lex.o binary_system.o list.o parser.o assembler.o
	gcc -o assembler list.o lex.o binary_system.o parser.o assembler.o

lex.o: lex.c lex.h datatype.h
	gcc -o lex.o -c lex.c

binary_system.o: binary_system.c binary_system.h
	gcc -o binary_system.o -c binary_system.c
	
list.o: list.c list.h
	gcc -o list.o -c list.c

parser.o: parser.c parser.h
	gcc -o parser.o -c parser.c
	
assembler.o: assembler.c
	gcc -o assembler.o -c assembler.c
