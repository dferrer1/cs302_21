// Challenge 06: Palindrome Permutation
// Author: Diego Ferrer
// Dates: 9/13 - 9/

#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

// is_palindrome prototype
void is_palindrome(string s);

int main(int argc, char *argv[]) {
	unordered_set<string> ius;
	unordered_set<string>::iterator iusi;
	string input;
	// // Read in input
	// read all phrases from standard input, store them in unordered_set
    while (getline(cin, input)) {
		ius.insert(input);
	}

	//DEBUG CHUNK: Check input unordered_set
	for (iusi = ius.begin(); iusi != ius.end(); iusi++) {
		cout << (*iusi) << endl;
	}
	

	return (0);
} // end of main

// is_palindrome:	takes in a string, outputs a bool
//					checks if the input string is a palindrome
//					couts result
void is_palindrome(string s) {
	// // Check if input strings are palindromes
	// // Output all results
} // end of is_palindrome
