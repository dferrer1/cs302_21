// Author: Diego Ferrer
// Challenge 09: sequence alignment
// Overview: Takes in two sequences and uses Needleman-Wunsch to calculate their alignment scores 

#include <iostream>
#include <vector>
using namespace std;

int score(char c1, char c2);
int max(int l, int a, int d);

int main(int argc, char *argv[]) {
    int left, above, diag;
	int r, c;
	string s1, s2;
	vector<int> grid;

	// take sequences from stdin
	cin >> s1 >> s2;

	// insert "lambda" value to strings
	s1.insert(0, "~");
	s2.insert(0, "~");

	// resize grid to the proper size (M+1)*(N+1)
	grid.resize(s1.size() * s2.size());

	// initialize values
	c = s1.size();
	r = s2.size();
	grid[0] = 0;
	for (int i = 1; i < c; i++) {
		grid[i] = grid[i-1] - 1;
	}
	for (int i = c; i < r*c; i+=c) {
		grid[i] = grid[i-c] - 1;
	}

	// loop through and fill all cells
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			left =  grid[i*c + j - 1] - 1;
			above = grid[(i-1)*c + j] - 1;
			diag =  grid[(i-1)*c + j- 1] + score(s2[i], s1[j]);
			grid[i*c + j] = max(left, above, diag);
		}
	}
	
	// output score
	cout << grid[r*c - 1] << endl;

	return 0;
}

int score(char c1, char c2) {
	if (c1 == c2) {
		return 1;
	} else {
		return -1;
	}
}
int max(int l, int a, int d) {
	if (l > a && l > d) {
		return l;
	} else if (a >= l && a > d) {
		return a;
	} else if (d > l && d > a) {
		return d;
	}
	return d;
}
