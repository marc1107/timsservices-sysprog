#include <inttypes.h>
#include <stdio.h>
#include <string.h>

typedef struct fachnote fach_note; 

void ausgeben(const fach_note *fachnote);
uint32_t einlesen(fach_note *fachnote);

enum PruefungsArt
{
    BENOTED,
    UNBENOTED
};

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