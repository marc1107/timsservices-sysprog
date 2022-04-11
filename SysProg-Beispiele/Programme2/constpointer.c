/*
 * constpointer.c
 *
 * Beispiel-Programm Zeiger-Variable
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015
 */

#include <stdio.h>

int main(void)
{
    const int i = 0;
    const int *p = &i;

    int j = 0;
    int * const q = &j;

/* Fehler, *p konstant:
    *p = 0;
*/
    p = NULL;

    *q = 0;
/* Fehler, q konstant:
    q = NULL;
*/

    return 0;
}

