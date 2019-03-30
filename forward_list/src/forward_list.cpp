//============================================================================
// Name        : forward_list.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description : Iterators example
// Notes       : Use a compiler that supports C++11
//============================================================================

#include <iostream>
#include <forward_list>

using namespace std;

int main ()
{
  forward_list<string> myCities = {"Baltimore", "New York", "Beijing", "Delhi"};

  cout << "myCities contains:\n";
  for (auto it = myCities.begin(); it != myCities.end(); ++it)
    std::cout << "--" << *it;

  cout << '\n';

  auto it = myCities.begin();

  cout << "*it = " << *it << endl;

  myCities.push_front("Ho Chi Minh City");

  cout << "*it = " << *it << endl;

  cout << "myCities contains:\n";
  for (it = myCities.begin(); it != myCities.end(); ++it)
    std::cout << "--" << *it;
  //std::cout << "------" << *it;




  return 0;
}
