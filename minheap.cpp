#include "minheap.h"

using namespace std;
 
MinHeap::MinHeap(int N, int * array) : N(N) {

	heap = array;
	heapToNode = new int[N];
	nodeToHeap = new int[N];

	// The nodes are going from 0 to N, thus, the "mappings" are initially the same. 
	for (int i = 0; i < N; ++i){
		heapToNode[i] = i;
		nodeToHeap[i] = i;
	}
	buildHeap();
}

int MinHeap::extractMin_i(){

	if (N < 1){
		cout << "HEAP UNDERFLOW!" << endl;
		return -1;
	}

	heapSwap(heap, 0, N-1);
	--N; heapify(0);
	return heapToNode[N]; 
}

int MinHeap::getMinValue(){
	if (N < 1){
		cout << "HEAP UNDERFLOW!" << endl;
	}
	return heap[0];
}

void MinHeap::heapSwap(int * heap, const int i_1, const int i_2){
	
	swap(&heap[i_1], &heap[i_2]); 

	int temp = heapToNode[i_1];
	//Heap to node 
	heapToNode[i_1] = heapToNode[i_2]; 
	heapToNode[i_2] = temp; 
	//Node to heap 
	nodeToHeap[heapToNode[i_1]] = i_1; 
	nodeToHeap[heapToNode[i_2]] = i_2; 
}
int MinHeap::getLeftChild(const int index) const {
	return (2 * index) + 1; 
}
int MinHeap::getRightChild(const int index) const {
	return (2 * index) + 2; 
}
int MinHeap::getParent(const int index) const {
	return (index - 1) / 2;
}
/*
	Heapifies the heap by recursively comparing nodes and exchanging them.
*/
void MinHeap::heapify(const int index){

	int l = getLeftChild(index);
	int r = getRightChild(index);
	
	int smallest;
	if ((l < N) && (heap[l] < heap[index])){
		smallest = l;
	}
	else{
		smallest = index;
	}
	if ((r < N) && (heap[r] < heap[smallest])){
		smallest = r;
	}
	if (smallest != index){
		//swap(&heap[index], &heap[smallest]);
		heapSwap(heap, index, smallest);
		heapify(smallest);
	}
}
void MinHeap::buildHeap(){
	for (int i = N/2; i >= 0; --i){
		heapify(i);
	}
}
void MinHeap::swap(int * n, int * m){
	int temp = *n;
	*n = *m;
	*m = temp;
}
 
