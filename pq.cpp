#include "minheap.h"
#include "pq.h"


PriorityQueue::PriorityQueue(int N, int * array) : MinHeap(N, array) {}

int PriorityQueue::extractMinIndex(){ return MinHeap::extractMin_i(); }

void PriorityQueue::decrease_key(int u, int distance_key){
		int index = nodeToHeap(u);
		if (distance_key > heap[index]) {
			cout << "New distance is larger than current distance!" << endl;
		}
		while ( (index > 1) 
			&& (heap[getParent(index)] > heap[index]) ){
				heapSwap(heap, index, getParent(index));
				index = getParent(index);
		}
}
int PriorityQueue::heapToNode(int heap_index){
	return MinHeap::heapToNode[heap_index];
}
int PriorityQueue::nodeToHeap(int u){
	return MinHeap::nodeToHeap[u];
}
