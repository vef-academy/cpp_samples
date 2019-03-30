//============================================================================
// Name        : lecture_02_function_templates.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Function templates
//============================================================================

#include <iostream>
#include <utility>
using namespace std;

template <typename T, typename U>
pair<T, U> myPair(T t, U u){
   return pair<T, U>(t, u);
}

template <typename T>
void mySwap(T& a, T& b){
   T temp;
   temp = a; a = b; b = temp;
}

int main() {
	cout << "Function templates" << endl; // prints Function templates

	int i1 = 1;
	int i2 = 2;

	cout << "i1 = " << i1 << ", i2 = " << i2 << endl;

	// Compiler generates mySwap(int&, int&)
	// Specify T
	mySwap<int>(i1, i2);
	// Let the compiler infer T
	// mySwap(i1, i2);

	cout << "i1 = " << i1 << ", i2 = " << i2 << endl;

	char c1 = 'a';
	char c2 = 'b';

	cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

	// Compiler generates mySwap(char&, char&)
	// Specify T
	mySwap<char>(c1, c2);
	// Let the compiler infer T
	// mySwap(c1, c2);
	cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

	pair<string, int> p = myPair<string, int>("Anna", 30);
	cout << p.first << " " << p.second << endl;

	return 0;
}
