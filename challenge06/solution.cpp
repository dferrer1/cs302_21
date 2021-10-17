// Author: Diego Ferrer
// Challenge 7: Minimum Spanning Tree
// Overview: This challenge was to take in the number of nodes and an adjacency graph that had the weights of paths. To accomplish this, I ran a 
//			 read in the paths from input and used Prim's algorithm to go through the graph, taking the smallest weighted path to nodes that 
//			 hadn't been added to the MST
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

// Main Execution
int main(int argc, char *argv[]) {
	vector<vector<int>> ag; // double vector to store edge weights
	multimap<int, pair<int,int>> aedges; // used for Prim's
	multimap<int,int> edges;
	vector<int> dm;
	string nvertices, row;
	int nvert;
	int gnum = 0;

	while(cin >> nvert)	{
		map<int,set<int>> aMST; // final MST; update as you go through the multimap

		// output formatting
		if (gnum != 0) {
			printf("\n");
		}

		//// read in distance matrix
		// resize rows in double matrix
		ag.resize(nvert);
		for (int i = 0; i < nvert; i++) {
			// resize cols in double matrix
			ag[i].resize(nvert);

			// read in each distance value
			for (int j = 0; j < nvert; j++) {
				cin >> ag[i][j];
			}
		}

		//// Use Prim's Algorithm
		// add the first node's edges to aedges
		for (size_t j = 0; j < ag[0].size(); j++) {
			if (ag[0][j] != -1) {
				aedges.insert({ag[0][j],{0, j}});
			}
		}

		int total_weight = 0;
		int weight;
		int cnode;
		int nnode;

		// set the first node as visited
		set<int> visited;
		visited.insert(0);

		// go through each edge
		while(aedges.size() != 0) {

			weight = aedges.begin()->first;
			cnode = aedges.begin()->second.first;
			nnode = aedges.begin()->second.second;

			// remove the first edge from the multimap
			aedges.erase(aedges.begin());
			
			// check that the current node isn't visited
			if (visited.find(nnode) == visited.end()) {
				// add the smallest edge adjacent to the current node to the MST in the right order
				if (cnode < nnode) {
					if (aMST.find(cnode) == aMST.end()) {
						set<int> nset;
						nset.insert(nnode);
						aMST.insert({cnode, nset});
					} else {
						aMST.at(cnode).insert(nnode);
					}
				} else {
					if (aMST.find(nnode) == aMST.end()) {
						set<int> nset;
						nset.insert(cnode);
						aMST.insert({nnode, nset});
					} else {
						aMST.at(nnode).insert(cnode);
					}
				}

				// add the weight to total weight
				total_weight += weight;
				
				// add the current node to visited
				visited.insert(nnode);
				
				// add the next edges to check
				for (size_t j = 0; j < ag[nnode].size(); j++) {
					
					if (ag[nnode][j] != -1) {
						aedges.insert({ag[nnode][j],{nnode, j}});
					}
				}
			}
		}

		//// output
		// print the total weight
		printf("%d\n", total_weight);
		
		// print each path
		for (size_t i = 0; i <= aMST.size(); i++) {
			if (aMST.find(i) != aMST.end()) {
				for (set<int>::iterator si = aMST.at(i).begin(); si != aMST.at(i).end(); si++) {
					printf("%c%c\n", char(i+65), char((*si)+65));
				}
			}
		}
		
		// output formatting
		gnum++;
	}

	return 0;

}

