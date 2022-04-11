#ifndef GRUSS_H
#define GRUSS_H
#include <string>

using namespace std;

class Gruss
{
private:
    Gruss();
    ~Gruss();
public:
    static void ausgeben(string vorname);
};

#endif