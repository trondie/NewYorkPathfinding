#include <iostream>
#include "djikstra.h"
#include "bellmanMT.h"
#include "pq.h"
using namespace std;

int main(){
	Djikstra djikstra = Djikstra();
	int distance = djikstra.shortest_path();
	cout << "Shortest path : " << distance;

	/*Bellman bellman = Bellman();
	int ret = bellman.shortest_path();*/

	
	/*int * source = new int[10];
	for (int i = 0; i < 10; ++i){
		source[i] = 10-i;
	}
	cout << endl;
	source[1] = 22;
	source[8] = 13;
	source[9] = 19;
	//cout << "BEFORE : " << endl;
	//for (int i = 0; i < 10; ++i) cout << source[i] << endl;
	//cout << "AFTER : " << endl;
	cout << "SOURCE BEFORE : " ;
	for (int i = 0; i < 10; ++i) cout << source[i] << " ";
	cout << endl;
	PriorityQueue q = PriorityQueue(10, source);
	cout << "INITIAL HEAP : " ;
	for (int i = 0; i < 10; ++i) cout << source[i] << " ";

	cout << endl;
	for (int i = 0; i < 10; ++i){
		int index = q.extractMinIndex();
		cout << "index : " << index << ", Value : " << source[index] << endl;
	}*/
	return 0;
}



