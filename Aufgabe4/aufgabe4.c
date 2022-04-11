/*
 * aufgabe4.c
 *
 * Liest Fachnamen mit Beurteilung ein und gibt dann einen Notenspiegel aus.
 *
 * Autor: Tim Koehler
 * Erstellt am: 02.05.19
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

enum PruefungsArt
{
    BENOTED,
    UNBENOTED
};

typedef struct fachnote fach_note; 

struct fachnote
{
    union benotung
    {
        int note;
        char beurteilung;
    } ben;

    fach_note *prev;
    fach_note *next;
    char name[20];
    enum PruefungsArt art;
};

uint32_t einlesen(fach_note *fachnote);
void ausgeben(const fach_note *notenspiegel);
fach_note* einfuegen(fach_note *notenspiegel, fach_note *fachnote);
void schleife(fach_note *notenspiegel, void (*) (const fach_note*));
fach_note* entfernen(fach_note *notenspiegel, fach_note **p);

int main(void)
{
    fach_note *notenspiegel = NULL;
    //------------------------------------------- Notenspiegel einlesen
    fprintf(stderr, "Faecher mit Noten eingeben (Ende mit Strg-D):\n");

    for (;;)
    {
        fach_note *p = (fach_note *) malloc(sizeof (fach_note));
        if (p == NULL)
        {
            fprintf(stderr, "Zu viele Faecher!\n");
            break;
        }

        if (!einlesen(p))
        {
            fprintf(stderr, "Eingabeende!\n");
            free(p);
            break;
        }

        notenspiegel = einfuegen(notenspiegel, p);
    }

    //------------------------------------------- Notenspiegel ausgeben
    printf("Notenspiegel:\n");

    schleife(notenspiegel, ausgeben);

    //------------------------------------------- Notenspiegel loeschen
    while (notenspiegel != NULL)
    {
        fach_note *p;
        notenspiegel = entfernen(notenspiegel, &p);
        free(p);
    }

    return 0;
}

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

fach_note* einfuegen(fach_note *notenspiegel, fach_note *fachnote)
{
    if(notenspiegel == NULL)
    {
        notenspiegel = fachnote;
        notenspiegel->prev = NULL;
        notenspiegel->next = NULL;
    }
    else
    {
        fachnote->next = notenspiegel;
        notenspiegel->prev = fachnote;
    }
    
    return fachnote;
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

void schleife(fach_note *notenspiegel, void (*ausgeben) (const fach_note *))
{   
    while(notenspiegel != NULL)
    {
        ausgeben(notenspiegel);
        notenspiegel = notenspiegel->next;
    }
}

fach_note* entfernen(fach_note *notenspiegel, fach_note **p)
{
    fach_note *returnNote = notenspiegel->next;
    
    if(notenspiegel->next != NULL)
    {
        notenspiegel->next->prev = NULL;
        notenspiegel->next = NULL;
    }

    *p = notenspiegel;
    return returnNote;
}

