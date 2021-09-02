// Challenge 02: Closest Numbers
// Name:  Diego Ferrer

// Brief description:

// This code solves challenge 02 based on the following idea/implementation...
//

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Main Execution

int main(int argc, char *argv[]) {
	string ssize;

	while(getline(cin, ssize)) {
		// vector variables
		vector<int> entries;
		string estring;
		int entry;
		
		// output variables
		int diff;

		// take array; store, parse, and sort it
		getline(cin, estring);
		stringstream ess(estring);
		while (ess >> entry) {
			entries.push_back(entry);
		}
		sort(entries.begin(), entries.end());

		// make a new vector of pairs
		vector<pair<int,int>> equal;
		
		// make a pair of the first two elements and add it to vector of pairs
		pair<int, int> smallest(entries[0], entries[1]);
		
		//cout << "Outputting differences: " << endl;
		// compare each element with the next element, not comparing the last element
		for (unsigned int i = 0; i < entries.size()-1 ; i++) {

			// calculate the absolute difference of one element and the next element
			diff = abs(entries[i] - entries[i+1]);
			
			//cout << diff << " ";
			
			// if the difference is smaller than the diff of the current smallest pair, clear the vector of pairs, set the newest smallest pair, and add the newest smallest pair to the vector
			if (diff < (abs(smallest.first - smallest.second))) {
				smallest.first = entries[i];
				smallest.second = entries[i+1];
			}
		}
		//cout << endl;
		
		// loop through again
		for (unsigned int i = 0; i < entries.size()-1; i++) {
			
			diff = abs(entries[i] - entries[i+1]);

			if (diff == (abs(smallest.first - smallest.second))) {
				equal.push_back(pair<int,int>(entries[i], entries[i+1]));
			}
		}

		// print all equal smallest pairs
		//cout << "Outputting pairs: " << endl;
		for (unsigned int i = 0; i < equal.size(); i++) {
			cout << equal[i].first << " " << equal[i].second;
			if (i != (equal.size() - 1)) {
				cout << " ";
			}
		}
		cout << endl;
	}

	return EXIT_SUCCESS;
}
