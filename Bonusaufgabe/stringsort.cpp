#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

int main(int argc, const char *argv[])
{
	std::srand((unsigned int) time(NULL));
	
	if(argc != 2)
	{
		std::cerr << "Aufruf: " << argv[0] << " [Anzahl]" << std::endl;
		return 1;
	}

	int n = std::atoi(argv[1]);

	if(n < 1)
	{
		std::cerr << "Anzahl muss mindestes 1 sein" << std::endl;
		return 1;
	}

	std::string words[n];
	
	std::cout << "Unsortiertes Feld:" <<std::endl;
	for (int i = 0; i < n; i++)
	{
		int r = std::rand() % n;
		std::ostringstream os;
    	os << r;
    	words[i] = os.str();
		std::cout << words[i] + " ";
	}
	std::cout << std::endl;

	// Sortieren
	for(int i = n; i > 1; i--)
	{
		for(int j = 0; j < i - 1; j++)
		{
			if(words[j].compare(words[j+1]) > 0)
			{
				std::string tmp = words[j+1];
				words[j+1] = words[j];
				words[j] = tmp;
			}
		}
	}

	std::string outString = words[0];
	for(int i = 1; i < n; i++)
	{
		if(words[i].compare(words[i-1]) == 0)
		{
			outString += "*";
		}
		else
		{
			outString += " ";
			outString += words[i];
		}
	}

	std::cout << "Sortiertes Feld:" << std::endl;
	std::cout << outString << std::endl;

	return 0;
}
