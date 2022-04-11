#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	srand((unsigned int) time(NULL));
	if(argc != 2)
	{
		printf("Aufruf: %s [Anzahl]\n", argv[0]);
		return 1;
	}

	int32_t n = atoi(argv[1]);
	if(n < 1)
	{
		printf("Anzahl muss mindestes 1 sein\n");
		return 1;
	}

	int32_t offset = (strlen(argv[1]) + 1) * sizeof(char);

	char *words = (char*) malloc(offset * n);
	if(words == NULL)
	{
		printf("Can't allocate memory...");
		return 1;
	}

	printf("Unsortiertes Feld:\n");
	for (int i = 0; i < n; i++)
	{
		int32_t r = rand() % n;
		sprintf(words+(i * offset), "%d", r);
		printf("%s ", words+(i * offset));
	}
	printf("\n");

	// Sortieren
	char *tmp = (char*) malloc(offset);
	if(tmp == NULL)
	{
		printf("Can't allocate memory...");
		return 1;
	}
	for(int i = n; i > 1; i--)
	{
		for(int j = 0; j < i - 1; j++)
		{
			if(strcmp(words+(j*offset), words+((j*offset)+offset)) > 0)
			{		
				memcpy(tmp, words+((j*offset)+offset), offset);
				memcpy(words+((j*offset)+offset), words+(j*offset), offset);
				memcpy(words+(j*offset), tmp, offset);
			}
		}
	}
	free(tmp);

	char *outString = (char*) malloc(offset * n);
	if(outString == NULL)
	{
		printf("Can't allocate memory...");
		free(words);
		return 1;
	}

	strcpy(outString, words);
	for(int i = 1; i < n; i++)
	{
		if(strcmp(words+(i*offset), words+(i*offset)-offset) == 0)
		{
			strcat(outString, "*");
		}
		else
		{
			strcat(outString, " ");
			strcat(outString, words+(i*offset));
		}
	}

	printf("Sortiertes Feld:\n");
	printf("%s\n", outString);

	free(words);
	free(outString);
	return 0;
}
