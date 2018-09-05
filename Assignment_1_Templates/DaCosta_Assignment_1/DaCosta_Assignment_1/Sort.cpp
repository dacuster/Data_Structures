/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Assignment 1, Sorting Function Template
*Date Assigned:		08-30-2018
*Due Date:			09-06-2018 11:59pm
*
*Description:		This file includes the functions for the Main file.
*
*Certification of Authenticity:
*I certify that this is entirely my own work, except where I have given
*fully-documented references to the work of others. I understand the definition
*and consequences of plagiarism and acknowledge that the assessor of this
*assignment may, for the purpose of assessing this assignment: Reproduce this
*assignment and provide a copy to another member of academic staff; and/or
*Communicate a copy of this assignment to a plagiarism checking service (which
*may then retain a copy of this assignment on its database for the purpose of
*future plagiarism checking).
*/

#include <vector>
#include "Song.h"
#include <algorithm>
#include <iterator>
//using namespace std;

using std::cout;
using std::cin;
using std::vector;
using std::iter_swap;


template <typename Sortable>
void sort(vector<Sortable> & _sortVector)
{
	for (int counterOne = 0; counterOne < _sortVector.size() - 1; counterOne++)
	{
		for (int counterTwo = counterOne + 1; counterTwo < _sortVector.size(); counterTwo++)
		{
			if (_sortVector[counterTwo] < _sortVector[counterOne])
			{
				iter_swap(&_sortVector[counterTwo], &_sortVector[counterOne]);
			}
		}
	}
}


template <typename Printable>
void print(vector<Printable> &_printVector)
{
	typename vector<Printable>::const_iterator _printIterator;

	for (_printIterator = _printVector.begin(); _printIterator != _printVector.end(); ++_printIterator)
	{
		cout << *_printIterator << endl;
	}

	cout << endl;
}


int main()
{
	vector<Song> songs = { Song("Starset", "My Demons"), Song("Avenged Sevenfold", "Unholy Confessions"), Song("Metallica", "Enter Sandman"), Song("Avenged Sevenfold", "The Stage"), Song("Metallica", "King Nothing") }; 
	vector<int> intVec = { 1, 5, 3, 4, 2                                      };    

	sort(intVec);
	sort(songs);

	print(intVec);
	print(songs);

	string temp;
	cin >> temp;

	return 0;
}