GCC = gcc-9 
FLAGS = -ansi -pedantic -Wall 
CFLAGS = -lm -lpthread -fopenmp 
THEPROGS=MM1c MM1f MMPosix

PROGS: MM1c MM1f MMPosix

MM1c:
	$(GCC) $(FLAGS) modulo.c -c -D_POSIX_C_SOURCE=199309L 
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) modulo.o $@.o -o $@
	
MM1f:
	$(GCC) $(FLAGS) modulo.c -c -D_POSIX_C_SOURCE=199309L 
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) modulo.o $@.o -o $@
		
MMPosix:
	$(GCC) $(FLAGS) modulo.c -c $(CFLAGS) -D_POSIX_C_SOURCE=199309L 
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS) 
	$(GCC) $(FLAGS) modulo.o $@.o -o $@ $(CFLAGS) 

clean:
	$(RM) $(THEPROGS) *.o