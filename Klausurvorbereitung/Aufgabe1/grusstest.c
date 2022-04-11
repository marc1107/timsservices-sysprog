#include <stdio.h>
#include "gruss.h"

int main(int argc, char const *argv[])
{
    printf("Bitte Vorname eingeben: ");
    char vorname[30];
    scanf("%s", vorname);
    ausgeben(vorname);
    return 0;

}