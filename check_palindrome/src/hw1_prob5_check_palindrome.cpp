//============================================================================
// Name        : check_palindrome.cpp
// Author      : VEF Academy
// Version     :
// Copyright   : Your copyright notice
// Description : Check if a string is a permutation of a palindrome, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <numeric>      // std::accumulate
using namespace std;

// Constant strings
const string EMPTY_STRING("String is empty!");
const string INVALID_CHARS("Invalid characters!");
const string STRING_TOO_LONG("String is too long!");
const string YES("Yes");
const string NO("No");

class Problem5{
public:
	// Member function to be implemented
	static string checkPalindrome(const string& s) {
		// Your implementation goes here
		return NO;
	}
	// Member function to score
	static size_t score(){

		// vector of scores for all the tests
		vector<int> scoreVector;

		// Test 1 -- Empty string
		scoreVector.push_back(static_cast<int>(checkPalindrome("") == EMPTY_STRING));

		// Test 2 -- Invalid characters
		scoreVector.push_back(static_cast<int>(checkPalindrome("$mm") == INVALID_CHARS));

		// Test 3 -- String is too long
		scoreVector.push_back(static_cast<int>(checkPalindrome("The quick brown fox jumps over the lazy dog") == STRING_TOO_LONG));

		// Test 4 -- a palindrome, all lower case
		scoreVector.push_back(static_cast<int>(checkPalindrome("racecar") == YES));

		// Test 5 -- a palindrome, mixed cases
		scoreVector.push_back(static_cast<int>(checkPalindrome("raCecar") == YES));

		// Test 6 -- permutation of a palindrome, all lower case
		scoreVector.push_back(static_cast<int>(checkPalindrome("raccear") == YES));

		// Test 7 -- permutation of a palindrome, mixed cases
		scoreVector.push_back(static_cast<int>(checkPalindrome("ARCecar") == YES));

		// Test 8 -- Not a permutation of any palindrome
		scoreVector.push_back(static_cast<int>(checkPalindrome("class") == NO));

		return accumulate(scoreVector.begin(), scoreVector.end(), 0);
	}

};

int main() {
	cout << "Palindrome Permutation" << endl;
	cout << "Total score = " << Problem5::score() << endl;
	return 0;
}
