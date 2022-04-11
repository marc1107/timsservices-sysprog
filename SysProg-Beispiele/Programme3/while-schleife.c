/*
 * while-schleife.c
 *
 * Liest beliebig viele Zahlen ein und gibt deren Summe aus
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015
 */

#include <stdio.h>

int main(void)
{
    int sum = 0;
    int n;
	
    printf("Zahlen eingeben (Ende mit Strg-d): ");
    while (scanf("%d", &n) == 1)
    {
        sum += n;
    }

    printf("Summe: %d\n", sum);

    return 0;
}

