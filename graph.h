#pragma once
#include <unordered_map>
#include <vector>
#include "reader.h"
#include "node.h"
#include <limits.h>

using namespace std;

const int VEC_PREALLOC = 50;
const string FILENAME = "input.txt";
const int MAX_NODE_VAL = INT_MAX;

class G {
protected:
	int N;
	int source;
	int destination;
	unordered_map<int, vector<Node>> adj;
	void readInput();
	void assertNodeExistence(const int u, const int v) const;

	G();
	bool nodeExists(const int k) const;
	bool neighbourExists(const int u, const int v);
	int getWeight(const int u, const int v);
	void addNode(const int u);
	void addEdge(const int u, const int v, const int weight);
	void removeEdge(const int u, const int v);
	int neighbourCount(const int u);
	void readFile(const string filename);

};
