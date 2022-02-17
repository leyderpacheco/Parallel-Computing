/*  UNiversidad Setgio Arboleda
    Fecha: 8-22-2022
    Autor: John Corredor
    Materia: Parallel Computing
    Tema: Implementacion benchmark en C
*/

#include <stdio.h>
#include <stdlib.h>
#include 


/* Se crea una variable con un valor alto para reservar memoria */
#define DATA_SZ (1024*1024*64*3)

/* Se reserva el espacio de memoria segun el valor */
static double MEM_CHUNK[DATA_SZ];

/*  Se crea la funcion para inicializar las matrices */
void InitMatrix(int SZ,double *Ma, double *Mb, double *Mr){
    int i,j,k;
    for ( i = 0; i < SZ; i++)
    {
        for (j = 0; j< SZ; j++)
        {
            Ma[j+i*SZ] = 3.0*(i-j);
            Mb[j+i*SZ] = 2.8*(j+i);
            Mr[j+i*SZ] = 0.0;
        }
        
    }
    
}

/* Se implementa la impresion para efectos de validacion */

void printMatrix(int SZ,double *M){
    int i,j,k;
    for ( i = 0; i < SZ; i++)
    {
        for (j = 0; j< SZ; j++)
        {
           printf("%f ",M[j+i*SZ]);
        }
        printf("\n");
    }
    
}

/* Se implementa paso a paso benchmark muktiplicacion de matricea 
    Algoritmo clasico (filas x columnas) de natrices de igual dimension */


int main(int argc, char const *argv[])
{
    int i,j,k;
    /*  Se captura la dimension de la matriz */
    int N = (int) atof(argv[1]);
    printf("Valor ingresado %d",N);
    printf("\n");

    /*  Apuntamos los vectores (creacion) al espaco de memoria reservado, con dimensiones NxN */

    double *Ma, *Mb, *Mr;

    Ma = MEM_CHUNK;
    Mb = Ma + N*N;
    Mr = Mb +N*N;

    InitMatrix(N,Ma,Mb,Mr);
    printf("\n MAtriz A \n");
    printMatrix(N,Ma);
    printf("\n MAtriz B \n");
    printMatrix(N,Mb);
   

    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            /* Necesito punteros auxiliares */
            double *pA,*pB,*pC;
            double sumaAuxiliar = 0.0;

            pA = Ma + (i*N);
            pB = Mb + j;
            for ( k = 0; k < N; k++ ,pA++,pB++)
            {
               sumaAuxiliar += (*pA * *pB);
            }

            Mr[i*N+j] = sumaAuxiliar;
            
        }
        
    }
    printf("\n MAtriz Mr \n");
    printMatrix(N,Mr);
    

    return 0;
}
