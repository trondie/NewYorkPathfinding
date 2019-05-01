#pragma once

#include "minheap.h"
#include <iostream>

class PriorityQueue : MinHeap {
private:
	int heapToNode(int heap_index);
	int nodeToHeap(int u);
public:
	PriorityQueue() {}
	PriorityQueue(int N, int * array);

	void decrease_key(int u, int distance_key);
	int extractMinIndex();
	void alterDistance(int u, int distance) { heap[nodeToHeap(u)] = distance; }
	int getDistance(int u) { return heap[nodeToHeap(u)]; }
};


