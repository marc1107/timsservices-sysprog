#include <stdlib.h>

size_t strlen(const char *s)
{
    size_t counter = 0;

    while(s[counter] != '\0')
    {
        counter++;
    }
    
    return counter;
}