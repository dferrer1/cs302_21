// Author: Diego Ferrer
// Challenge 05: Graph Paths
// Overview: This challenge was to take in a set of edges and a set of paths to search in a graph. To accomplish this, I ran a BFS the nodes
//			 that I found while I was taking in the edges, checking to see if the a path existed.
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


// Main Execution

int main(int argc, char *argv[]) {
	string snedges, snpaths;
	int nedges, npaths;
	string edges, paths;
	char n1, n2;
	int graph = 1;

	// start each iteration by taking the number of edges from standard input
	while(getline(cin, snedges)) {
		unordered_map<char, set<char>> al;
		vector<pair<char,char>> pv;
		nedges = stoi(snedges);

		// format for next iteration
		if (graph != 1) {
			printf("\n");
		}
		// take each edge from standard input
		for (int i = 0; i < nedges; i++) {
			getline(cin, edges);
			stringstream ess(edges);
			ess >> n1 >> n2;
			
			// check that n1 is in the adjacency list. If not, add a new node with an empty set
			if (al.find(n1) == al.end()) {
				set<char> nn;
				al.insert({n1, nn});
			}
			
			// check that n2 is in the adjacency list. If not, add a new node with an empty set
			if (al.find(n2) == al.end()) {
				set<char> nn;
				al.insert({n2, nn});
			}

			// insert edges to a node
			al.at(n1).insert(n2);
		}
	
		// take the number of paths to search for
		getline(cin, snpaths);
		npaths = stoi(snpaths);

		// take each searched path from standard input
		for (int i = 0; i < npaths; i++) {
			getline(cin, paths);
			stringstream ess(paths);
			ess >> n1 >> n2;
			pv.push_back({n1, n2});
		}

		// Do BFS to search for each path
		for (size_t i = 0; i < pv.size(); i++) {
			bool PATH = false;

			queue<char> frontier;
			set<char> visited;
			frontier.push(pv[i].first);
			visited.insert(pv[i].second);
			while (frontier.size() != 0) {
				// get the first element in frontier
				char a = frontier.front();
				frontier.pop();

				// check if the end node has been found
				if (a == pv[i].second) {
					PATH = true;
					break;
				}

				// push nodes onto queue from adjacency list
				for (set<char>::iterator i = al.at(a).begin(); i != al.at(a).end(); i++) {
					// check that the first element in frontier hasn't already been visited
					if (visited.find(a) == visited.end()) {
						// add each edge from the current node to frontier
						frontier.push(*i);
					}
				}
				// add the current node to the visited set
				visited.insert(a);
			}

			// output paths for each graph
			if (PATH) {
				printf("In Graph %d there is a path from %c to %c\n", graph, pv[i].first, pv[i].second);
			} else {
				printf("In Graph %d there is no path from %c to %c\n", graph, pv[i].first, pv[i].second);
			}
		}

		// increment graph count
		graph++;
	}

	return 0;
}


