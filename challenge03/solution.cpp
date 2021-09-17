// Challenge 06: Palindrome Permutation
// Author: Diego Ferrer
// Dates: 9/13 - 9/17

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

// is_palindrome prototype
void is_palindrome(string s);

int main(int argc, char *argv[]) {
	//unordered_set<string> ius;
	string input;
	// // Read in input
	// read all phrases from standard input, store them in unordered_set
    while (getline(cin, input)) {
		//ius.insert(input);
		is_palindrome(input);
	}
	
	/*
	// access each key and check if its a palindrome
	unordered_set<string>::iterator iusi;
	for (iusi = ius.begin(); iusi != ius.end(); iusi++) {
		//is_palindrome((*iusi));
		//DEBUG: Check input unordered_set
		cout << (*iusi) << endl;
	}
	*/

	return (0);
} // end of main

// is_palindrome:	takes in a string, returns nothing
//					checks if the input string is a palindrome
//					couts result
void is_palindrome(string s) {
	unordered_map<char, int> charc;
	//unordered_map<char, int>::iterator charcit;
	//const auto& charcit;
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

	//DEBUG CHUNK
	/*
	cout << s << " values: \n	";
	for (const auto& charcit : charc) {
		cout << charcit.first << " " << charcit.second << ", ";
	}
	cout << endl;
	*/

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
