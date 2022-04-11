#include <string.h>
#include <stdlib.h>

char *s = "Halli";
char *t = "Hallo";

char *st = (char*) calloc(1, strlen(s) + strlen(t) + 1); // '\0' nicht vergessen!

strcat(st, s);
strcat(st, t);

free(st);
