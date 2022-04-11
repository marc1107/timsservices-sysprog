#include "../b/wuerfel.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double k = atof(argv[1]);
    double f = oberflaeche(k);
    double v = volumen(k);
    
    printf("Kantenlaenge %f, Oberflaeche %f, Volumen %f\n", k, f, v);
    return 0;
}