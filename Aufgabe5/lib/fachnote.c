#include "fachnote.h"

uint32_t einlesen(fach_note *fachnote)
{
    if(scanf("%20s", fachnote->name) <= 0)
        return 0;
    
    char *c;
    while((c = strchr(fachnote->name, '_')) != NULL)
    {
        *c = ' ';
    }


    if(scanf("%d", &fachnote->ben.note) > 0)
    {
        fachnote->art = BENOTED;
        return 1;
    }

    if (scanf("%c", &fachnote->ben.beurteilung) > 0)
    {
        fachnote->art = UNBENOTED;
        return 1;
    }
   
    return 0;
}

void ausgeben(const fach_note *fachnote)
{
    printf("%-20s\t", fachnote->name);

    if(fachnote->art == BENOTED)
    {
        if((fachnote->ben.note >= 10 && fachnote->ben.note <= 40) || fachnote->ben.note == 50)
            printf("%d,%d\n", fachnote->ben.note / 10, fachnote->ben.note % 10);
        else
            printf("Fehler: %d\n", fachnote->ben.note);
    }
    else
    {
        if(fachnote->ben.beurteilung == 'B')
            printf("bestanden\n");
        else if(fachnote->ben.beurteilung == 'N')
            printf("nicht bestanden\n");
        else
            printf("Fehler: %c\n", fachnote->ben.beurteilung);
    }
}