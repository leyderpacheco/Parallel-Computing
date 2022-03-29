GCC = gcc 
FLAGS = -pedantic -Wall
CFLAGS = -lm -pthread

PROGS: MM1c MM1f MMPosixc


MM1c:
	$(GCC) $(FLAGS) modulo.c -c
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) modulo.o $@.o -o ejecutable_$@
	
MM1f:
	$(GCC) $(FLAGS) modulo.c -c
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) modulo.o $@.o -o ejecutable_$@

MMPosixc:
	$(GCC) $(FLAGS) modulo.c -c $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS)
	$(GCC) $(FLAGS) modulo.o $@.o -o ejecutable_$@ $(CFLAGS)

clean:
	$(RM) $(PROGS) *.o

	