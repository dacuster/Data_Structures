#include "HashTable.h"

/*
	All possible commands that can be used in the program.
*/
/// <summary>
///		All possible commands for the program.
/// </summary>
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

/*
	TODO:
	Read file
	First number is test cases (how many times it runs)
	Next number is song addition size
	Next number is number of lines of commands
	Next few lines are commands
	Next number is song addition
	Next number is number of lines of commands
	Next few lines are commands

	Inputs are ARTIST then TITLE

*/


/*
	These two functions are not mine. Credit is given down below at the definitions.
*/
int Sieve(int _numToCheck);
int binarySearch(std::vector<int> _primes, int _left, int _right, int _n);

int main()
{
	std::string command;

	HashTable newTable = HashTable(20);

	newTable.printAllContents();
	Song newSong = Song("Avenged_Sevenfold", "Nightmare");
	Song newSong2 = Song("Avenged_Sevenfold", "God_Hates_Us");

	newTable.addSong(newSong);

	newTable.addSong(newSong2);

	newTable.printAllContents();

	newTable.deleteSong(Song("Avenged_Sevenfold", "Nightmare"));


	newTable.printAllContents();

	system("pause");


	return 0;
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
///		The closest prime below the given input.
///	</returns>
int Sieve(int _numToCheck)
{
    const int n = 1000000;

	// Array to store all primes less than 10^6.
	std::vector<int> primes;

    /*
		In general, Sieve of Sundaram, produces primes
		smaller than (2*x + 2) for any number given
		a number x.
	*/
    int nNew = sqrt(n);

	/*
		This array is used to separate numbers of the
		form i+j+2ij from others where  1 <= i <= j
    */
	int marked[n / 2 + 500] = {0};

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
///		The closest prime lower than the given input n.
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