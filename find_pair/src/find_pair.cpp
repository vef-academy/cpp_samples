//============================================================================
// Name        : find_pair.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

bool findNumbers(const vector<int>& v1, const vector<int>& v2, const int m)
{
	bool found = false;
	for (size_t i=0; i<v1.size(); ++i)
	{
		for (size_t j=0; j<v2.size(); ++j)
		{
			if (v1[i] + v2[j] == m)
			{
				found = true;
				break;
			}
			if (found)
			{
				break;
			}
		}
	}
	return found;
}

int main() {
	cout << "Find two numbers that sum to m" << endl; // prints Find two numbers that sum to m

	vector<int> v1 {1, 5, 7, 3};
	vector<int> v2 {2, 4, 8, 6};

	cout << boolalpha << findNumbers(v1, v2, 9) << endl;
	cout << boolalpha << findNumbers(v1, v2, 20) << endl;

	return 0;
}
