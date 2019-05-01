#pragma once
#include <iostream>

using namespace std;

class MinHeap {

public:
	int * heap;
	int * heapToNode;
	int * nodeToHeap;
	int N; 
	
	int getLeftChild(const int index) const;
	int getRightChild(const int index) const;
	int getParent(const int index) const;
	void heapSwap(int * heap, const int i_1, const int i_2);
	MinHeap() : heap(NULL), N(0) {}
	MinHeap(int N, int * array);

	int extractMin_i();
	int getMinValue();
		void heapify(int index);
	void buildHeap();
	void swap(int * n, int * m);
};



