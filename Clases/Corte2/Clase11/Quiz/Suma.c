/*Autor: Juan Camilo Rodriguez Giraldo*/
/*Este programa tiene como objetivo sumar dos numeros*/
#include<stdio.h>
#include<stdlib.h>
/*Funcion para sumar dos numeros*/
/*La funcion promete devolver un entero*/
/*La funcion necesita dos enteros como argumentos*/
int sumar_dos_numeros (int a, int b){
	/*SE realiza la suma*/
	int suma = a+b;
	/*Devuelve la suma*/
	return suma;
}
int main (int argc, char** argv){
	/*Los valores tomados por el argv se castean a entero (int)*/
	int  N_1 = (int) atof(argv[1]);
	int  N_2 = (int) atof(argv[2]);
	/*Se imprimen por consola para Verificar los numeros de entrada*/
	printf("valor ingresado %d, %d\n",N_1, N_2);
	/*SE llama a la funcion para realizar la suma*/
	int suma = sumar_dos_numeros(N_1,N_2);
	/*SE imprime la suma*/
	printf("El valor de la suma es: %d\n", suma);
}