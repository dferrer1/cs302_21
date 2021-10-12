// Challenge 7: Minimum Spanning Tree
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

// Main Execution

struct Node {
	int row = 0;
	int col = 0;
	int backedge = 0;
	int dist = -1;
	bool visited = false;
};

struct Graph {
	vector<Node> graph;
	map<char, int> edge_weights;
	int n;
};


int main(int argc, char *argv[]) {

	vector<vector<int>> ag; // double vector to store edge weights
	//map<int,int> aMST; // final MST; update as you go through the multimap
	//vector<pair<int,int>> aMST;
	multiset<pair<char,char>> apath; // used to prevent duplicate paths
	multimap<int, pair<int,int>> aedges; // used for Prim's
	

	//vector<Node> graph;
	multimap<int,int> edges;
	vector<int> dm;
	string nvertices, row;
	int nvert;
	//int distance;
	int gnum = 0;

	// read in nvertices
	// while(getline(cin, nvertices)) {
	
	while(cin >> nvert)	{
		vector<pair<int,int>> aMST;
		// DEBUG: loop check
		//cout << "LOOP: " << gnum << endl;

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
				//cin >> distance;
				//v[i][j] = distance;
			}
		}

		//// Use Prim's Algorithm
		// add the first node's edges to aedges
		//aedges.insert({ag[0][0],{0, 0}});
		for (size_t j = 0; j < ag[0].size(); j++) {
			if (ag[0][j] != -1) {
				//DEBUG: check edge adds !!!
				//printf("initial node adding {%d:{0, %d}} to aedges \n", ag[0][j], j);

				aedges.insert({ag[0][j],{0, j}});
			}
		}

		// add the first node's smallest adjacent edge to the MST
		//aMST.insert({aedges.begin()->second.first, aedges.begin()->second.second});
		//aMST.insert({0,0});

		//DEBUG: check values
		//printf("aedges.begin->second.second: %d\n", aedges.begin()->second.second);
		
		/*
		// add the edges of the second node
		for (size_t j = 0; j < ag[aedges.begin()->second.second].size(); j++) {
			if (ag[aedges.begin()->second.second][j] != -1) {
				//DEBUG: check edge adds
				printf("second node adding {%d:{%d, %d}} to aedges \n", ag[aedges.begin()->second.second][j], j);

				aedges.insert({ag[aedges.begin()->second.second][j],{aedges.begin()->second.second, j}});
			}
		}
		*/

		// remove the first edge after adding it
		//aedges.erase(aedges.begin());

		int total_weight = 0;
		int weight;
		int cnode;
		int nnode;

		// set the first node as visited
		set<int> visited;
		visited.insert(0);

		// go through each edge
		while(aedges.size() != 0) {
			//DEBUG: check values !!!
			//printf("aedges.begin()->second.first: %d\n", aedges.begin()->second.first);
			//printf("aedges.begin()->second.second: %d\n", aedges.begin()->second.second);

			weight = aedges.begin()->first;
			cnode = aedges.begin()->second.first;
			nnode = aedges.begin()->second.second;

			// remove the first edge from the multimap
			aedges.erase(aedges.begin());
			
			// check that the current node isn't visited
			if (visited.find(nnode) == visited.end()) {
			// if it isn't visited
				//DEBUG: check MST adds !!!
				//printf("adding {%d, %d} to MST \n", cnode, nnode);
				
				// add the smallest edge adjacent to the current node to the MST
				//aMST.insert({cnode, nnode});
				aMST.push_back({cnode, nnode});

				// add the weight to total weight
				total_weight += weight;
				
				// add the current node to visited
				visited.insert(nnode);
				
				// add the next edges to check
				for (size_t j = 0; j < ag[nnode].size(); j++) {
					
					if (ag[nnode][j] != -1) {
						//DEBUG: check edge adds !!!
						//printf("adding {%d:{%d, %d}} to aedges \n", ag[nnode][j], nnode, j);
						
						aedges.insert({ag[nnode][j],{nnode, j}});
					}
				}
			}
		}

		//DEBUG: check all edges added to MST !!!
		for (size_t i = 0; i < aMST.size(); i++) {
			//printf("First Node: %d; Second Node: %d\n", aMST[i].first, aMST[i].second);
		}

		//// output
		// print the total weight
		printf("%d\n", total_weight);
		// print each path
		for (size_t i = 0; i < aMST.size(); i++) {
			printf("%c%c\n", char(aMST[i].first+65), char(aMST[i].second+65));
		}

		/*
		//DEBUG: check all edges added to MST
		for (map<int,int>::iterator msti = aMST.begin(); msti != aMST.end(); msti++) {
			printf("First Node: %d; Second Node: %d\n", msti->first, msti->second);
		}
		*/

		/*
		//// read in distance matrix
		// read in each row
		for(int i = 0; i < stoi(nvertices); i++) {
			getline(cin, row);
			stringstream rss(row);

			// read in each column value and store it in the distance matrix
			for (int j = 0; j < stoi(nvertices); j++) {
				rss >> distance;
				
				//DEBUG: check distance
				//cout << distance;

				dm.push_back(distance);
			}

			//DEBUG: output formatting
			//cout << endl;
		}

		//DEBUG: check input
		for (int i = 0; i < stoi(nvertices); i++) {
			for (int j = 0; j < stoi(nvertices); j++) {
				cout << dm[i*stoi(nvertices) + j] << " ";
			}
			cout << endl;
		}
		*/
		
		// output formatting
		gnum++;
	}

	return 0;

}

