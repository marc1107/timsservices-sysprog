/*
 * pointervar.c
 *
 * Beispiel-Programm Zeiger-Variable
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015 / 10.11.2017 (C11)
 */

#include <stdio.h>

int main(void)
{
    int i = 3082;
    int *p = &i;

    //---------------------------------------------- print pointer value
    printf("p = %p\n", (void*) p);

    //-------------------------------------------- print pointer address
    printf("&p = %p\n", (void*) &p);

    //----------------------------------------------- print pointer size
    printf("sizeof p = %zu\n", sizeof p);

    //--------------------------------- print dereferenced pointer value
    printf("*p = %d\n", *p);

    return 0;
}

