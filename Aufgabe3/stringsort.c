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

	char **words = (char**) malloc(n * sizeof(char*));
	if(words == NULL)
	{
		printf("Can't allocate memory...");
		return 1;
	}

	printf("Unsortiertes Feld:\n");
	for (int i = 0; i < n; i++)
	{
		words[i] = (char*) malloc((strlen(argv[1]) + 1) * sizeof(char));
		if(words[i] == NULL)
		{
			printf("Can't allocate memory...");
			return 1;
		}
		int32_t r = rand() % n;
		sprintf(words[i], "%d", r);
		printf("%s ", words[i]);
	}
	printf("\n");

	// Sortieren
	for(int i = n; i > 1; i--)
	{
		for(int j = 0; j < i - 1; j++)
		{
			if(strcmp(words[j], words[j+1]) > 0)
			{
				char *tmp = words[j+1];
				words[j+1] = words[j];
				words[j] = tmp;
			}
		}
	}

	char *outString = (char*) malloc((strlen(argv[1]) + 1) * sizeof(char) * n);
	if(outString == NULL)
	{
		printf("Can't allocate memory...");
		return 1;
	}

	strcpy(outString, words[0]);
	for(int i = 1; i < n; i++)
	{
		if(strcmp(words[i], words[i-1]) == 0)
		{
			strcat(outString, "*");
		}
		else
		{
			strcat(outString, " ");
			strcat(outString, words[i]);
		}
	}

	printf("Sortiertes Feld:\n");
	printf("%s\n", outString);
	
	for(int i = 0; i < n; i++)
		free(words[i]);

	free(words);
	free(outString);
	return 0;
}
