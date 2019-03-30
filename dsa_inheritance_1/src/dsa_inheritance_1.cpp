//============================================================================
// Name        : static_binding.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
//============================================================================

/** Description :
 * Static binding
 * When a class is derived from a base class, as with Student and Person,
 * the derived class becomes a subtype of the base class, which means that we
 * can use the derived class wherever the base class is acceptable.
 * Consider a non-virtual function that is implemented in both the base class
 * and the derived class.
 * When determining which member function to call, C++’s default action is to
 * consider an object’s declared type, not its actual type.
 * To compile and run:
 * In the terminal of Linux or Mac:
 * g++ -o static_binding static_binding.cpp
 * ./static_binding
 * or
 * Put the code in a source file of a project in an IDE such as Eclipse
**/

#include <iostream>
using namespace std;

// Person (base class)
class Person {
public:
	void print() const
	{
		cout << "Person::print() \n";
	}
};

// Student (derived from Person)
class Student : public Person
{
public:
    void print() const
    {
		cout << "Student::print() \n";
    }

    void study() const
    {
    	cout << "Student::study() \n";
    }
};

int main() {

	cout << "Static binding \n" << endl;

	Person* pp[100]; // array of 100 Person pointers
	pp[0] = new Person(); // add a Person (details omitted)
	pp[1] = new Student(); // add a Student (details omitted)
	pp[0]->print(); // calls Person::print()
	pp[1]->print(); // also calls Person::print() (!)
	// pp[1]->study(); // error: no member named 'study' in 'Person'
	Student* s = new Student; // Student::study()
	s->study();

	// Remember to delete the objects allocated using new
	delete pp[0];
	delete pp[1];
	delete s;

	return 0;
}

