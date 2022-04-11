#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Parameter fehlt!\n");
        return 1;
    }

    int len = atoi(argv[1]);
    int *data = (int*) calloc(len, sizeof(int));

    if(data == NULL)
    {
        printf("Es konnte kein Speicher zugewiesen");
        return 1;
    }


    printf("Bitte %d ganze Zahlen eingeben: ", len);
    int i = 0;
    while(i < len && scanf("%d", &data[i]) > 0)
        i++;
    
    
    srand((unsigned int) time(NULL));
    while(i < len)
    {
        data[i] = rand() % 10001; 
        i++;
    }
    

    printf("\nSortierte Zahlenfolge:\n");
    for (int i = len; i > 1; i--) 
    {
        // groessten Wert nach hinten schieben
        for (int j = 0; j < i - 1; ++j) 
        {
            if (data[j] > data[j + 1]) 
            {
                // Werte tauschen
                int tmp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = tmp;
            }
        }
    }

    for(int x = 0; x < len; x++)
    {
        printf("%d\n", data[x]);
    }

    free(data);

    return 0;
}