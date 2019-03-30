//============================================================================
// Name        : stack_variables.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description : This program shows that stack variables, be they objects or
// pointers, get destroyed when they go out of scope
//============================================================================

#include <iostream>
#include <tuple>
using namespace std;

int* foo(){
	int num = 5; // a stack variable
	int* pNum = &num; // get address of num
	cout << "pNum = " << pNum << endl;
	return pNum; // warning: address of stack memory associated with local variable 'num' returned
				 // pNum is also a stack variable but we return by value so its value gets copied
}

std::pair<int*, int**> bar(){
	int* pNum = new int(7);
	int** ppNum = &pNum;
	cout << "*pNum = " << *pNum << endl;
	cout << "pNum = " << pNum << endl;
	cout << "ppNum = " << ppNum << endl;
	return pair<int*, int**>(pNum, ppNum);
}

int main() {

	// Objects as stack variables
	cout << "*********** Objects as stack variables *************\n";
	int* pInt = foo();

	// We see that the value of the pointer is retained, but the int that it points to
	// is no longer 5
	cout << "pInt = " << pInt << endl;
	cout << "*pInt = " << *pInt << endl;

	cout << "*********** Pointers as stack variables *************\n";
	// Pointers as stack variables
	std::pair<int*, int**> ptrPair = bar();

	// both pNum and ppNum are stack variables, but we first copy them into
	// the pair<int*, int**> and then the pair is returned by value,
	// so the value of pNum and ppNum are retained
	cout << "ptrPair.first = " << ptrPair.first << endl;
	// Note that the int allocated on memory heap is intact
	cout << "*ptrPair.first = " << *ptrPair.first << endl;
	cout << "ptrPair.second = " << ptrPair.second << endl;
	// But the stack variable pNum has been destroyed
	cout << "*ptrPair.second = " << *ptrPair.second << endl;
	cout << "*ptrPair.second == ptrPair.first: " << boolalpha
			<< (*ptrPair.second == ptrPair.first) << endl;

	delete ptrPair.first;

	return 0;
}
