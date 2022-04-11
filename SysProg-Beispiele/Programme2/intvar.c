/*
 * intvar.c
 *
 * Beispiel-Programm int-Variable
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015 / 10.11.2017 (C11)
 */

#include <stdio.h>

int main(void)
{
    int i = 0;
    int j = 1;

    //------------------------------------------- print variable values
    printf("i = %d\n", i);
    printf("j = %d\n", j);

    //---------------------------------------- print variable addresses
    printf("&i = %p\n", (void*) &i);
    printf("&j = %p\n", (void*) &j);

    //----------------------------------- print type and variable sizes
    printf("sizeof (int) = %zu\n", sizeof (int));
    printf("sizeof i = %zu\n", sizeof i);

    return 0;
}

