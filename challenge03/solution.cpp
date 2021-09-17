// Challenge 03: Palindrome Permutation
// Author: Diego Ferrer
// Dates: 9/13 - 9/17
// Description: This challenge involves taking in strings from standard input and checking if they are palindromes. My code
//				implements this by taking in strings using getline and calling is_palindrome(), a function a created 
//				described below, on them.

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// is_palindrome prototype
void is_palindrome(string s);

int main(int argc, char *argv[]) {
	string input;
	
	// // Read in input
	// read all phrases from standard input, store them in unordered_set
    while (getline(cin, input)) {
		is_palindrome(input);
	}
	
	return (0);
} // end of main

// is_palindrome:	takes in a string, returns nothing
//					checks if the input string (storing all characters and their count in a map) is a palindrome
//					couts result
void is_palindrome(string s) {
	unordered_map<char, int> charc;
	int palindrome = 0;

	// // Check if input strings are palindromes
	// count each character instance in s
	for (int i = 0; i < int(s.size()); i++) {
		if (charc.find(s[i]) == charc.end()) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				charc.insert({s[i], 1});
			}
		} else {
			charc.at(s[i])++;
		}
	}

	// count non-even-repeating characters
	for (const auto& charcit : charc) {
		if ((charcit.second % 2) == 1) {
			palindrome++;
		}
	}

	// // Output results
	if (palindrome < 2) {
		cout << "\"" << s << "\" is a palindrome permutation" << endl;
	} else {
		cout << "\"" << s << "\" is not a palindrome permutation" << endl;
	}
} // end of is_palindrome
