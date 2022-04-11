/*
 * outparam.c
 *
 * Beispiel-Programm Ausgabe-Parameter
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015
 */

#include <stdio.h>

int read_and_return_int(void);
void read_int(int*);

int main(void)
{
    int n;

    n = read_and_return_int();
    printf("%d\n", n);

    read_int(&n);
    printf("%d\n", n);

    return 0;
}

int read_and_return_int(void)
{
    int n;

    printf("int read_and_return_int(void), Zahl eingeben: ");
    scanf("%d", &n);

    return n;
}

void read_int(int *n)
{
    printf("void read_int(int*), Zahl eingeben: ");
    scanf("%d", n);
}

