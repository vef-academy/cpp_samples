//============================================================================
// Name        : lecture_02_initializer_list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Vect
{
public:
	Vect(const int n); // Constructor that takes in the size
	// We can also overload the subscript operator here
	int getElement(const size_t i) const;
	void setElement(const size_t i, const int val);

	~Vect();           // Destructor
private:
	int size;          // size of the vector
	int* data;         // an array holding the vector
};

// The Constructor that doesn't use initializer list
//Vect::Vect(const int n)
//{
//	size = n;
//	data = new int[n];  // allocate array
//}

// The Constructor that uses initializer list -- better
Vect::Vect(const int n): size(n), data(new int[size]) {}

int Vect::getElement(const size_t i) const
{
	return data[i];
}

void Vect::setElement(const size_t i, const int val)
{
	data[i] = val;
}

Vect::~Vect()
{
	delete [] data;
}

// This is how we avoid magic numbers
enum {
	VECTOR_SIZE = 5
};

int main() {
	cout << "Initializer list " << endl;

	Vect v(VECTOR_SIZE);

	for (int i=0; i<VECTOR_SIZE; ++i)
	{
		v.setElement(i, 2*i);
	}

	for (int i=0; i<VECTOR_SIZE; ++i)
	{
		cout << "Element " << i << ": " << v.getElement(i) << endl;
	}

	return 0;
}
