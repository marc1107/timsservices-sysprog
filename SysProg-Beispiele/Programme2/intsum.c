/*
 * intsum.c
 *
 * Liest ganze Zahlen ein und summiert sie.
 *
 * Autor: H.Drachenfels
 * Erstellt am: 25.2.2015
 */

#include <stdio.h>

int main(void)
{
    int sum = 0;
    int number;

    printf("Ganze Zahlen eingeben (Ende mit Strg-D):\n");

    while (scanf("%d", &number) > 0)
    {
        sum += number;
    }

    printf("Summe: %d\n", sum);

    return 0;
}

