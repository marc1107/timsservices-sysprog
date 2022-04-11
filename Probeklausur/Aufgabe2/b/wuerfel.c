#include "../a/quadrat.h"
#include "wuerfel.h"

double oberflaeche(const double kantenlaenge)
{
    return quadrat_flaeche(kantenlaenge) * 6;
}

double volumen(const double kantenlaenge)
{
    return quadrat_flaeche(kantenlaenge) * kantenlaenge;
}

