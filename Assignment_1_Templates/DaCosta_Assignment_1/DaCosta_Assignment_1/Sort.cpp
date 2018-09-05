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
using std::swap;

template <typename Comparable>
const Comparable & sort(vector<Comparable> & a)
{
	Comparable temp;

	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = 1; j < a.size(); j++)
		{
			if (a[j] < a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}

	return a[a.size() - 1];
}

int main()
{
	vector<Song> songs = { Song("artist", "title"), Song("artist2", "title2") }; 
	vector<int> intVec = { 1, 5, 3, 4, 2                                      };   


	cout << sort(intVec) << endl; 
	cout << sort(songs)  << endl;  



	string temp; 
	cin >> temp; 
}

template < class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
	{
		os << " " << *ii;
	}
	os << "]";
	return os;
}