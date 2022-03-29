/*Autor: Juan Camilo Rodriguez Giraldo*/

#include<stdio.h>
#include<stdlib.h>
/*Este programa tiene como objetivo comparar 3 numeros y determinar cual
es mas grande*/
int main (int argc, char** argv){
	/*Los valores tomados por el argv se castean a entero (int)*/
	int  a = (int) atof(argv[1]);
	int  b = (int) atof(argv[2]);
	int  c = (int) atof(argv[3]);
	/*Se hace comparacion de a con b, si a es mayor pasa */
	if (a > b){
		/*Se hace una comparacion de a con c, si es mayor se imprime en consola*/
		if (a > c){
			printf("EL numero mas grande es a: %d\n",a);
		}
		/*Si es falsa la comparacion anterior, se imprime c en consola*/
		else{
			printf("EL numero mas grande es c: %d\n",c);
		}
	}/*Si es falsa la comparacion anterior, entra en el else*/
	else{
		/*Se hace una comparacion de a con c, si es mayor se imprime en consola*/
		if (b > c){
			printf("EL numero mas grande es b: %d\n",b);
		}
		/*Si es falsa la comparacion anterior, se imprime c en consola*/
		else{
			printf("EL numero mas grande es c: %d\n",c);
		}	
	}

}