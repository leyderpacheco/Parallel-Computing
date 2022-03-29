#include <stdlib.h>
#include <stdio.h>

// Ejercicio donde se leen tres datos de tipo entero y se aplica un consicional a estos

int main(int argc, char const *argv[])
{
    int a, b, c;

    printf("introduzca a: ");
    scanf("%d", &a);

    printf("introduzca b: ");
    scanf("%d", &b);

    printf("introduzca c: ");
    scanf("%d", &c);

    if (a > b)
    {
        if (a > c)
        {
            printf("A es el numero mayor");
        }
        else
        {
            printf("C es el numero mayor");
        }
    }
    else
    {

        if (b > c)
        {
            printf("B es el numero mayor");
        }
        else
        {
            printf("C es el numero mayor");
        }

        return 0;
    }
}
