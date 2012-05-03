prog: prog.o algorithms.o ressources.o
	gcc prog.o algorithms.o ressources.o -o prog

prog.o: prog.c ressources.h algorithms.h acronym.h
	gcc -c prog.c -o prog.o

algorithms.o: algorithms.c algorithms.h acronym.h
	gcc -c algorithms.c -o algorithms.o

ressources.o: ressources.c ressources.h acronym.h
	gcc -c ressources.c -o ressources.o
