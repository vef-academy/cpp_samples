//============================================================================
// Name        : lecture_02_dynamic_binding.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
//============================================================================

/** Description :
 * Dynamic binding
 * an object’s contents determine which member function is called.
 * To specify that a member function should use dynamic binding,
 * the keyword “virtual” is added to the function’s declaration.
 * To compile and run:
 * In the terminal of Linux or Mac:
 * g++ -o dynamic_binding lecture_02_dynamic_binding.cpp
 * ./dynamic_binding
 * or
 * Put the code in a source file of a project in an IDE such as Eclipse
**/

#include <iostream>
using namespace std;

// Person (base class)
class Person {
public:
	virtual void print() const
	{
		cout << "Person::print() \n";
	}

	virtual ~Person() {}
};

// Student (derived from Person)
class Student : public Person
{
public:
    virtual void print() const
    // We don't need the keyword virtual here,
    // just put it in for the sake of clarity
    {
		cout << "Student::print() \n";
    }

    void study() const
    {
    	cout << "Student::study() \n";
    }

};

int main() {

	cout << "Dynamic binding \n" << endl;

	Person* pp[100]; // array of 100 Person pointers
	pp[0] = new Person(); // add a Person
	pp[1] = new Student(); // add a Student
	pp[0]->print(); // calls Person::print()
	pp[1]->print(); // calls Student::print(), dynamic binding
	// pp[1]->study(); // error: no member named 'study' in 'Person'
	Student* s = new Student;
	s->study(); // Student::study(), static binding

	// Remember to delete the objects allocated using new
	delete pp[0];
	delete pp[1];
	delete s;

	return 0;
}



