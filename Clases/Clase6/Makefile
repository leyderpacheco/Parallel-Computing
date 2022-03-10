GCC = gcc-9
FLAGS = -ansi -pedantic -Wall
CFLAGS = 

PROGS = main

main:
	$(GCC) $(FLAGS) funciones.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ funciones.o $@.o

clean:
	$(RM) $(PROGS) *.O

