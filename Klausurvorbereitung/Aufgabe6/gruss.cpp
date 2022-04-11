#include "gruss.h"
#include <iostream>

void Gruss::ausgeben(string vorname)
{
    if(vorname.compare("Sepp") == 0)
    {
        cout << "Servus " << vorname << "!" << endl;
    }
    else
    {
        cout << "Hallo " << vorname << "!" << endl;
    }
}

