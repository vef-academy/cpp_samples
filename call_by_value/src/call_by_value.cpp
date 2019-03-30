//============================================================================
// Name        : call_by_value.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void doubleIt1(int y) {
	y *= 2; // y = y*2
}
void doubleIt2(int& y) {
	y *= 2; // y = y*2
}
int main(){
	int x = 5;
	doubleIt1(x);
	cout << "x = " << x << endl;
	x = 6;
	doubleIt2(x);
	cout << "x = " << x << endl;
	return 0;
}

