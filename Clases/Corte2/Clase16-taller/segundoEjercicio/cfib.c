/*
# punto 2 taller
# Serie Fibonacci
# Autor: Leyder Pacheco
# computacion paralela */

/*Se Crea la funcion que genera la serie de fibonacci de tamaño n*/

#include "cfib.h"

double cfib(int n) {
	int i;
	double a=0.0, b=1.0, tmp;
	for (i=0; i<n; ++i) {
		tmp = a; a = a + b; b = tmp;
	}
return a;
}