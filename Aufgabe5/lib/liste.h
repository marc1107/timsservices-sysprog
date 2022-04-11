#include "fachnote.h"

fach_note* entfernen(fach_note *notenspiegel, fach_note **p);
void schleife(fach_note *notenspiegel, void (*ausgeben) (const fach_note *));
fach_note* einfuegen(fach_note *notenspiegel, fach_note *fachnote);