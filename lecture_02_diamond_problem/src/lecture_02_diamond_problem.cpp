//============================================================================
// Name        : lecture_02_diamond_problem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Person{
public:
//virtual void live(){
//    	cout << "Person::live()\n";
//    };
};
class Faculty: virtual public Person{
public:
    virtual void live(){
    	cout << "Faculty::live()\n";
    };
};
class Student: virtual public Person{
public:
    virtual void live(){
    	cout << "Student::live()\n";
    };
};
class TA: public Faculty, public Student{
public:
//	void live(){
//	   	cout << "TA::live()\n";
//	}
};

int main() {
	cout << "Diamond problem" << endl; // prints Diamond problem

	Faculty f1;
	f1.live();

	Student s1;
	s1.live();

	TA ta1;
	ta1.live(); // error: request for member ‘live’ is ambiguous
	ta1.Faculty::live();
	ta1.Student::live();

	return 0;
}
