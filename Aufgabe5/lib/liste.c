#include "liste.h"

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