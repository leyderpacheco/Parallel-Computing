/* Universidad Sergio Arboleda
	Autor: Leyder Pacheco
	Fecha: 10-2-22
	Materia: Parallel Computing
	Tema:	Progamacion Modular en C
	Fichero: Automatizacion de compilacion  */



GCC = gcc-11
FLAGS = -ansi -pedantic -Wall


PROGS = principal

principal:
	$(GCC) $(FLAGS) funciones.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ funciones.o $@.o

clean:
	$(RM) $(PROGS) *.o
