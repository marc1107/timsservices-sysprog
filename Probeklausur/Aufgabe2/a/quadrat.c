#include "quadrat.h"

static double zumquadrat(const double d)
{
    return d * d;
}

double quadrat_flaeche(const double seitenlaenge)
{
    return zumquadrat(seitenlaenge);
}

