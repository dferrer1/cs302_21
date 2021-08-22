#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Challenge 01: Rotating Arrays; null solution

/*

Author: Diego Ferrer
Dates: 8/19/21 - 8/27/21
Collaborators:
Description:

*/

int main(int argc, char *argv[]) {
	vector<int> values;
	string inst, vals;
	int val;
	
	int size;
	int rotations;
	char direction;

	int fpos;
	int k;

	// begin loop
	while (getline(cin, inst)) {
	
		// store input values
		stringstream ss(inst);
		ss >> size;
		ss >> rotations;
		ss >> direction;

		// store values
		getline(cin, vals);
		stringstream vs(vals);
		values.clear();
		while(vs >> val) {
			values.push_back(val);
		}
		
		// calculate final position of '1'
		fpos = rotations % size;
		k = 0;

		// left rotation
		if (direction == 'L') {
		
			// print new array
			for (int i=0; i < size; i++) {
				if ((i+fpos) < size) {
				
					// print element
					cout << values[i+fpos];

					// increment counter
					k++;
				}
				else {
					// print element
					cout << values[i-k];
				}
		
				// print spaces
				if (i < (size-1)) {
					cout << ' ';
				}
			}
		}

		// right rotation
		else if (direction == 'R') {
			// print new array
			for (int i=0; i < size; i++) {
				if (i < fpos) {
				
					// print element
					cout << values[i+size-fpos];

					// increment counter
					k++;
				}
				else {
					// print element
					cout << values[i-k];
				}
		
				// print spaces
				if (i < (size-1)) {
					cout << ' ';
				}
			}
			
		}
	}
 
	return 0;
}

