/*
 * arrayvar.c
 *
 * Beispiel-Programm Feld-Variable
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015 / 10.11.2017 (C11)
 */

#include <stdio.h>

int main(void)
{
    int a[] = {3421, 3442, 3635, 3814};
    const int n = (int)(sizeof a / sizeof (int));
  
    //------------------------------------ print array values and addresses
    printf("a = %p\n", (void*) a);

    for (int i = 0; i < n; ++i)
    {
        printf("%d: %p %d\n", i, (void*) &a[i], a[i]);
    }

    //---------------------------------------------------- print array size
    printf("sizeof a = %zu\n", sizeof a);

    return 0;
}

