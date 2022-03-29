#include <stdlib.h>
#include <stdio.h>




int main(int argc, char const *argv[]){

int a ,b;
printf("Digite el numero 1: ");
scanf("%d",&a);

printf("Digite el numero 2: ");
scanf("%d",&b);

suma(a,b);
}

void suma(int a,int b){

    printf("La suma es : %d",a+b); 
}