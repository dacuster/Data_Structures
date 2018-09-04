#include <iostream>
#include <string>
#include <vector>
#include "Square.hpp"
using namespace std;

template <typename Comparable>
const Comparable & findMax(const vector<Comparable> & a)
{
	int maxIndex = 0;

	for (int i = 1; i < a.size(); i++)
	{
		if (a[maxIndex] < a[i])
			maxIndex = i;
	}
	return a[maxIndex];
}

int main() {

	vector<int> intVec = { 1, 5, 3, 4, 2 };
	vector<double> doubleVec = { 1.0, 5.0, 3.0, 4.0, 2.0 };
	vector<string> stringVec = { "the", "owls", "are", "not", "what", "they", "seem" };


	 
	cout << findMax(intVec) << endl;
	cout << findMax(doubleVec) << endl;
	cout << findMax(stringVec) << endl;



	string temp;
	cin >> temp;
}