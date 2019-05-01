#pragma once
#include "graph.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include "pq.h"

class Bellman : G {
	int * source_distance;
	int * prev;
	PriorityQueue q;

	int getMinLinear();
	int getMin();
	void relax(const int u, const int v);
	void printPath(int u);

	void incrementPath();
	void updatePath(int v);
	bool checkIfTarget(int u);
public:
	Bellman();
	~Bellman();
	int shortest_path();
};