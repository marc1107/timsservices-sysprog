#include <iostream>
#include <string>
#include "gruss.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Bitte Vorname eingeben: ";
    string vorname;
    cin >> vorname;
    Gruss::ausgeben(vorname);
    return 0;
}