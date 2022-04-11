#include "stdlib.h"

struct data
{
    char geb;
    int raum;
};

typedef struct data data;

int main(int argc, char const *argv[])
{
    int n = 123;

    data *p = (data*) malloc(sizeof(data));
    p->geb = 'G';
    p->raum = 149;

    double a[2];
    a[0] = 1.2;
    a[1] = 3.4;

    free(p);

    return 0;
}
