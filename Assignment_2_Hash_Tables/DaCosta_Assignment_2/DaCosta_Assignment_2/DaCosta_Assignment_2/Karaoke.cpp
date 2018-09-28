/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 2 Hash Tables
Date Assigned:	09-11-2018
Due Date:		09-27-2018 11:59pm

Description:	This file includes the main and other non-class specific functions.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment: Reproduce this
assignment and provide a copy to another member of academic staff; and/or
Communicate a copy of this assignment to a plagiarism checking service (which
may then retain a copy of this assignment on its database for the purpose of
future plagiarism checking).
*/

#include "HashTable.h"
#include <fstream>

const std::string FILE_NAME = "karaoke.txt";
const int TABLE_SIZE_MULTIPLIER = 9;

enum COMMANDS
{
	/// <summary>
	///		Add a song to the hash table.
	/// </summary>
	ADD,
	/// <summary>
	///		List all the songs by a given artist.
	/// </summary>
	LIST,
	/// <summary>
	///		Delete a specific song by an artist.
	/// </summary>
	DELETE,
	/// <summary>
	///		Quit the program.
	/// </summary>
	QUIT
};

COMMANDS convertStringToEnum(std::string _command);

/*
	These two functions are not mine. Credit is given down below at the definitions.
*/
int Sieve(int _numToCheck);
int binarySearch(std::vector<int> _primes, int _left, int _right, int _n);

int main()
{
	std::ifstream inputFile(FILE_NAME);

	int testCaseNumber = 0;

	std::string command   = ""; 
	std::string inputLine = "";  
	
	inputFile >> command;

	testCaseNumber = std::stoi(command);

	for (int counterOne = 1; counterOne <= testCaseNumber; counterOne++)
	{
		std::cout << "--------------------- TEST CASE " << counterOne << " ---------------------" << std::endl;

		inputFile >> command;

		int size = std::stoi(command);

		HashTable newTable = HashTable(Sieve(size * TABLE_SIZE_MULTIPLIER));

		inputFile >> command;

		int numberOfCommands = std::stoi(command);

		for (int counterTwo = 0; counterTwo < numberOfCommands; counterTwo++)
		{
			inputFile >> command;

			std::string songArtist = ""; 
			std::string songTitle  = ""; 

			switch (convertStringToEnum(command))
			{
			case ADD:
				inputFile >> songArtist;
				inputFile >> songTitle;

				newTable.addSong(Song(songArtist, songTitle));

				break;
			case DELETE:
				inputFile >> songArtist;
				inputFile >> songTitle;

				newTable.deleteSong(Song(songArtist, songTitle));

				break;
			case LIST:
				inputFile >> songArtist;

				newTable.listArtistSongs(songArtist);

				break;
			case QUIT:
				std::cout << "Quitting application." << std::endl;

				counterTwo = numberOfCommands;
				counterOne = testCaseNumber++;

				break;
			default:
				std::cout << "Error. No correct command found. Exiting." << std::endl;

				counterTwo = numberOfCommands;
				counterOne = testCaseNumber++;

				break;
			}
		}
		/*
			Uncomment to print all the contents in the current table.
		*/
		//newTable.printAllContents();

		std::cout << std::endl;
	}
	std::cout << "Enter a character to close the console..." << std::endl;

	std::string input;

	std::cin >> input;

	return 0;
}

/// <summary>
/// Converts a string to a command enum.
/// </summary>
/// <param name="_command">
///		The command to convert.
///	</param>
/// <returns>
///		Enumerator.
///	</returns>
COMMANDS convertStringToEnum(std::string _command)
{
	if (_command == "ADD")
	{
		return ADD;
	}
	else if (_command == "LIST")
	{
		return LIST;
	}
	else if (_command == "DELETE")
	{
		return DELETE;
	}
	else
	{
		return QUIT;
	}
}


/*
	Thanks to Shashank Mishra ( Gullu ) from geeksforgeeks.org for all
	of the following functions (with some modifications by me).
	https://www.geeksforgeeks.org/nearest-prime-less-given-number-n/
*/

// C++ program to find the nearest prime to n.

/// <summary>
///		Utility function of Sieve of Sundaram to create a list of all primes up to 10^6.
/// </summary>
/// <param name="_numToCheck">
///		The number used to find the closest prime below it.
///	</param>
/// <returns>
///		Integer.
///	</returns>
int Sieve(int _numToCheck)
{
	const int n = 100000;

	// Array to store all primes less than 10^5.
	std::vector<int> primes;

    /*
		In general, Sieve of Sundaram, produces primes
		smaller than (2*x + 2) for any number given
		a number x.
	*/
    int nNew = (int)sqrt(n);

	/*
		This array is used to separate numbers of the
		form i+j+2ij from others where  1 <= i <= j
    */
	int marked[n / 2 + 500] { 0 };

    // Eliminate indexes which do not produce primes.
	for (int i = 1; i <= (nNew - 1) / 2; i++)
	{
		for (int j = (i * (i + 1)) << 1; j <= n / 2; j = j + 2 * i + 1)
		{
			marked[j] = 1;
		}
	}

    // Since 2 is a prime number.
    primes.push_back(2);

	/*
		Remaining primes are of the form 2 * i + 1 such
		that marked[i] is false.
	*/
	for (int i = 1; i <= n / 2; i++)
	{
		if (marked[i] == 0)
		{
			primes.push_back(2 * i + 1);
		}
	}
	return binarySearch(primes, 0, primes.size() - 1, _numToCheck);
}

/// <summary>
///		A modified binary search of the primes array to find the closest prime less the given input n.
/// </summary>
/// <param name="_primes">
///		The primes array.
///	</param>
/// <param name="_left">
///		The lowest number for the binary search.
///	</param>
/// <param name="_right">
///		The highest number for the binary search.
///	</param>
/// <param name="_n">
///		The input number.
///	</param>
/// <returns>
///		Integer.
///	</returns>
int binarySearch(std::vector<int> _primes, int _left, int _right, int _n)
{
    if (_left <= _right)
    {
        int mid = (_left + _right) / 2;

		/*
			Base condition is, if we are reaching the left
			corner or right corner of primes[] array then
			return that corner element because before or
			after that we don't have any prime number in
			primes array.
		*/
        if (mid == 0 || mid == _primes.size() - 1)
            return _primes[mid];

		/*
			If n is a prime itself, it will be present
			in the primes array. Now, we have to find the nearest
			prime less than n so we will return primes[mid - 1].
		*/
		if (_primes[mid] == _n)
		{
			return _primes[mid - 1];
		}

		/*
			If primes[mid] < n and primes[mid + 1] > n that
			mean we reached the nearest prime.
		*/
		if (_primes[mid] < _n && _primes[mid + 1] > _n)
		{
			return _primes[mid];
		}
		if (_n < _primes[mid])
		{
			return binarySearch(_primes, _left, mid - 1, _n);
		}
		else
		{
			return binarySearch(_primes, mid + 1, _right, _n);
		}
    }
    return 0;
}