GCC = gcc-9
FLAGS = -ansi -pedantic -Wall 
CFLAGS = -lm -lpthread -fopenmp 
THEPROGS= MMPosix MM1cOMP MM1fOMP

PROGS:  MMPosix MM1cOMP MM1fOMP


MM1cOMP:
	$(GCC) $(FLAGS) module.c -c -D_POSIX_C_SOURCE=199309L $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS)
	$(GCC) $(FLAGS) module.o $@.o -o $@ $(CFLAGS)

MM1fOMP:
	$(GCC) $(FLAGS) module.c -c -D_POSIX_C_SOURCE=199309L $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS)
	$(GCC) $(FLAGS) module.o $@.o -o $@ $(CFLAGS)
		
MMPosix:
	$(GCC) $(FLAGS) module.c -c $(CFLAGS) -D_POSIX_C_SOURCE=199309L 
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS) 
	$(GCC) $(FLAGS) module.o $@.o -o $@ $(CFLAGS) 

clean:
	$(RM) $(THEPROGS) *.o
