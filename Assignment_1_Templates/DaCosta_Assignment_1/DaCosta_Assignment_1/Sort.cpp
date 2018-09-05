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

#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
//using namespace std;

using std::cout;
using std::cin;
using std::vector;
using std::iter_swap;

template <typename Comparable>
const Comparable & sort(vector<Comparable> & a)
{
	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[j] < a[i])
			{
				iter_swap(&a[j], &a[i]);
			}
		}
	}
	
	return a[(a.size() - 1)];
}


template <typename Printable>
const Printable & print(vector<Printable> & vec)
{
	for (typename vector<Printable>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it;
	}

	return vec[0];
}


int main()
{
	vector<Song> songs = { Song("artist", "title"), Song("artist2", "title2") }; 
	vector<int> intVec = { 1, 5, 3, 4, 2                                      };   


	//cout << sort(intVec) << endl; 
	//cout << sort(songs)  << endl; 

	sort(intVec);
	sort(songs);

	print(intVec);
	print(songs);



	string temp; 
	cin >> temp; 
}