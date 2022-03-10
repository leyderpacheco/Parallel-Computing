/*
* Date: 2022-02-010
* Author: Leyder Pacheco
* Course: Paralell and Distributed Computing
* Topic: Programacion modular en C
* Fichero: Main
*
/* Se presenta la cabecera del modulo*/

#include "funciones.h"
#include <stdio.h>

int main ( ){
	int a = 10, b = 2, resul = 0;
	printf("Programa principal \n");
	printf("Llamada a la funcion \n");
	resul  = Sumar(a, b);
	printf("Resultado de la funcion: %d\n", resul);
	return 0;
}
