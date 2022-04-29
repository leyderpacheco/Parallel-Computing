# Punto 2 taller
# Serie Fibonacci Python
# Autor: Leyder Pacheco
# computacion paralela 

import sys

#funcion fib que recibe el tamaño de la serie y un numiter
def fib(n):
	a, b = 0.0, 1.0
	for i in range(n):
		a, b = a + b, a
	return a

if __name__ == '__main__':
	import sys
	arg, numiter = map(int, sys.argv[1:])
	for i in range(numiter):
		fib(arg)