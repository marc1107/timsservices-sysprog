#include "gruss.h"
#include <string.h>
#include <stdio.h>

#define GRUSS_FORMAT "%s %s!\n"

void ausgeben(char* vorname)
{
    if(strcmp(vorname, "Sepp") == 0)
    {
        printf(GRUSS_FORMAT, "Servus", vorname);
    }
    else
    {
        printf(GRUSS_FORMAT, "Hallo", vorname);
    }
}

