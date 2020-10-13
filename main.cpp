#include <iostream>
#include <string>
#include "search.hpp"
#include "int-node.hpp"
#include <sys/time.h>


void FillArray (int arrayItems[]);
void PrintElapsedTime (timeval& prevTime, std::string  searchType);

const int LENGTH = 1000000000;

int main ()
{
	struct timeval checkpoint;
	gettimeofday(&checkpoint, nullptr);

	int searchKey = 0;
	static int arrayItems[LENGTH];
	int index = -1;
	FillArray(arrayItems);

	PrintElapsedTime(checkpoint, "Initializing array");

	while (true)
	{
		std::cout << "Enter a number to search for: ";
		std::cin >> searchKey;

		gettimeofday(&checkpoint, nullptr);

		if (searchKey < 0)
		{
			break;
		}

		index = Find(arrayItems, LENGTH, searchKey);
		PrintElapsedTime(checkpoint, "Search");

		if (index >= 0)
		{
			std::cout << "Found " << searchKey << " at index " << index << std::endl;
		}
		else
		{
			std::cout << searchKey << " not found!" << std::endl;
		}
		if (!std::cin)
		{
			std::cin.clear (); // Restore input stream to working state
			std::cin.ignore ( 100 , '\n' ); // Get rid of any garbage that user might have entered
		}
	}

	return 0;
}

void FillArray (int arrayValues[])
{
	int value = 0;
	for (int i = 0; i < LENGTH; ++i)
	{
		arrayValues[i] = int(value);
		value += (rand() % 3) + 1; // increase by 1-3 numbers
	}
}

void PrintElapsedTime (timeval& prevTime, std::string searchType)
{
	struct timeval nextTime;

	gettimeofday(&nextTime, nullptr);
	int numberOfSecondsDelta = nextTime.tv_sec - prevTime.tv_sec;
	int numberOfMicroSecondsDelta = nextTime.tv_usec - prevTime.tv_usec;

	std::cout << "\t" << searchType << ": " << (numberOfMicroSecondsDelta / 1000) + numberOfSecondsDelta * 1000 << "ms" << std::endl;
	prevTime = nextTime;
}
