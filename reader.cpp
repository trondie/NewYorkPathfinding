// C++ skeleton for Problem 1

#include <iostream>
#include <fstream>
#include <limits>
#include <assert.h>
#include <string>
#include "graph.h"
using namespace std;


//void Reader::readFile(string filename)
//{
	// open input file
/*	ifstream inputFile("input.txt");
	string code;
	int nodeA, nodeB, V, distance;
	while (inputFile >> code) {
		if (!code.compare("c")){ // Skip comments
			inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (!code.compare("p")) { // Read number of nodes into V
			inputFile >> V;
			N = V;
			continue;
		}
		if (!code.compare("a")) { // Read nodes and distance into nodeA (source), nodeB (destination), and distance
			inputFile >> nodeA >> nodeB >> distance;
			// Your code to generate the graph here
			addNode(nodeA);
			addNode(nodeB);
			createEdge(nodeA, nodeB, distance);
			continue;
		}
		if (!code.compare("q")) { // Read a request, (source, destination) into (nodeA and nodeB)
			inputFile >> nodeA >> nodeB;
			// Your code to find the solution to this request and print the sequence of nodes preceded by "s "
			source = nodeA;
			destination = nodeB;
			continue;
		}
		assert(false); // Should never get here with a correct input
	}

	//return 0; */
//}
