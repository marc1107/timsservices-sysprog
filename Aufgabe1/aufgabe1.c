#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i = -33;
    long int li = -5;
    long long int lli = -11;
    unsigned int ui = 12;
    unsigned long int uli = 77;
    unsigned long long int ulli = 1200;

    short sh = 1;
    unsigned short us = 11;

    float f = 3.1f;

    double d = 3.3;
    long double ld = 3.33;

    const char* s = "Hallo";
    char c = 'c';
    signed char sc = '-1';
    unsigned char uc = 'a';
    bool b = true;

    printf("Adresse\t\t Groese\t\t\t      Typ\tName\tWert\n");
    printf("%p\t%2zu\t%25s\t%4s\t%d\n", (void*) &i, sizeof(i), "Int", "i", i);
    printf("%p\t%2zu\t%25s\t%4s\t%ld\n", (void*) &li, sizeof(li), "Long Int", "li", li);
    printf("%p\t%2zu\t%25s\t%4s\t%lld\n", (void*) &lli, sizeof(lli), "Long Long Int", "lli", lli);
    printf("%p\t%2zu\t%25s\t%4s\t%o\n", (void*) &ui, sizeof(ui), "Unsigned Int", "ui", ui);
    printf("%p\t%2zu\t%25s\t%4s\t%lu\n", (void*) &uli, sizeof(uli), "Unsigned Long Int", "uli", uli);
    printf("%p\t%2zu\t%25s\t%4s\t%llu\n", (void*) &ulli, sizeof(ulli), "Unsigned Long Long Int", "ulli", ulli);
    printf("%p\t%2zu\t%25s\t%4s\t%hd\n", (void*) &sh, sizeof(sh), "Short", "sh", sh);
    printf("%p\t%2zu\t%25s\t%4s\t%d\n", (void*) &us, sizeof(us), "Unsigned Short", "us", us);
    printf("%p\t%2zu\t%25s\t%4s\t%lf\n", (void*)  &d, sizeof(d), "Double", "d", d);
    printf("%p\t%2zu\t%25s\t%4s\t%Lf\n", (void*)  &ld, sizeof(ld), "Long Double", "ld", ld);
    printf("%p\t%2zu\t%25s\t%4s\t%f\n", (void*) &f, sizeof(f), "Float", "f", f);
    printf("%p\t%2zu\t%25s\t%4s\t%c\n", (void*) &c, sizeof(c), "Char", "c", c);
    printf("%p\t%2zu\t%25s\t%4s\t%uc\n", (void*) &uc, sizeof(uc), "Unsigned Char", "uc", uc);
    printf("%p\t%2zu\t%25s\t%4s\t%s\n", (void*) &s, sizeof(s), "String", "s", s);
    printf("%p\t%2zu\t%25s\t%4s\t%d\n", (void*) &b, sizeof(b), "Bool", "b", b);

    if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(char*) == 4)
        printf("\nEs handelt sich um ein ILP32-Datenmodell\n");
    else if (sizeof(int) == 4 && sizeof(long) == 8 && sizeof(char*) == 8)
        printf("\nEs handelt sich um ein LP64-Datenmodell\n");
    else if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(long long) == 8 && sizeof(char*) == 8)
        printf("\nEs handelt sich um ein LLP64-Datenmodell\n");
    else
        printf("\nEs liegt keines der beiden vor\n");

    return 0;
}
