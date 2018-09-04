#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
using namespace std;

template <typename Comparable>
const Comparable & sort(const vector<Comparable> & a)
{
	int maxIndex = 0;

	for (int i = 1; i < a.size(); i++)
	{
		if (a[maxIndex] < a[i])
			maxIndex = i;
	}
	return a[maxIndex];
}

int main()
{
	vector<Song> songs = { Song("artist", "title"), Song("artist2", "title2") }; 
	vector<int> intVec = { 1, 5, 3, 4, 2                                      };  


	 
	cout << sort(intVec) << endl;
	cout << sort(songs) << endl;



	string temp;
	cin >> temp;
}