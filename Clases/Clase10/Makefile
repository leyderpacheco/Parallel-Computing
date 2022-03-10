GCC = gcc
FLAGS = -pthread
PROGS = Posix

all: Posix

Posix:
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) $modulo.c -c
	$(GCC) $(FLAGS) $modulo.o $@.o -o $@

clean:
	$(RM) $(PROGS) *.o



#1000-1250