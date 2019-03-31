//============================================================================
// Name        : call-by-pointer.cpp
// Author      : Kien Nguyen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const size_t MAX_ARRAY_LEN = 10;
// Also possible
// int calculateSum(int* myArray, size_t arrayLen){
int calculateSum(int myArray[MAX_ARRAY_LEN], size_t arrayLen){
	int sum = 0;
	for (size_t i=0; i< arrayLen; ++i){
		sum += myArray[i];
	}
	return sum;
}
int main() {
	int arr[MAX_ARRAY_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 10};
	cout << "Sum = " << calculateSum(arr, MAX_ARRAY_LEN);
	return 0;
}
