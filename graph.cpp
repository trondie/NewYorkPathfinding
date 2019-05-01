#include "graph.h"
#include "node.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <assert.h>
#include <string>
#include <unordered_map>

using namespace std;

G::G(){
	adj = unordered_map<int, vector<Node>>();
	readFile(FILENAME);
}
bool G::nodeExists(const int u) const {
	return adj.find(u) != adj.end();
}
void G::addNode(const int u){
	if (!nodeExists(u) && (u >= 0)){
		adj[u] = vector<Node>();
	}
}
// In this case, we don't need to add u as a neighbour for v. The dataset defines the nodes both ways.
void G::addEdge(const int u, const int v, const int weight){
	assertNodeExistence(u,v);
	adj[u].push_back(Node(v, weight));
}

int G::neighbourCount(const int u){
	return adj[u].size();
}
bool G::neighbourExists(const int u, const int v) {
	for (auto it = adj[u].begin(); it != adj[u].end(); ++it){
		if (it->value == v) return true;
	}
	return false;
}
void G::removeEdge(const int u, const int v){
#ifdef ASSERTS
	assertNodeExistence(u,v);
#endif
	for (auto it = adj[u].begin(); it != adj[u].end(); ++it){
		if (it->value == v){ adj[u].erase(it); break; }
	}
	for (auto it = adj[v].begin(); it != adj[v].end(); ++it){
		if (it->value == u) { adj[v].erase(it); break; }
	}
}
int G::getWeight(const int u, const int v) {
#ifdef ASSERTS
	assertNodeExistence(u,v);
#endif
	for (auto it = adj[u].begin(); it != adj[u].end(); ++it){
		if (it->value == v) return it->u_distance;
	}
	return -1;
}
void G::assertNodeExistence(const int u, const int v) const {
	assert(nodeExists(u));
	assert(nodeExists(v));
}

void G::readFile(string filename)
{
	// open input file
	ifstream inputFile("input.txt");
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
			addEdge(nodeA, nodeB, distance);
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
}
