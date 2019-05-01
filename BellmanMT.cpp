#include "bellmanMT.h"
#include "minheap.h"

Bellman::Bellman() {
	vector<int> path = vector<int>();
	source_distance = new int[N];
	prev = new int[N];
	for (int i = 0; i < N; ++i){
		source_distance[i] = INT_MAX / 2;
		prev[i] = -1;
	}
	source_distance[source] = 0;
	q = PriorityQueue(N, source_distance);
	q.decrease_key(source, 0);
}
Bellman::~Bellman(){
	delete [] source_distance;
}
int Bellman::getMin(){
	return q.extractMinIndex();
}
int Bellman::getMinLinear(){
	int min = INT_MAX;
	int min_node = -1;

	for (int i = 0; i < N; ++i){
		if (source_distance[i] == -1) continue;
		if (source_distance[i] < min){
			min = source_distance[i];
			min_node = i;
		}
	}
	assert(min_node > -1);
	return min_node;
}
void Bellman::relax(const int u, const int v){
	int sourceToVWeight = q.getDistance(u) + getWeight(u,v); // GETDISTANCE!
	if (q.getDistance(v) > sourceToVWeight){	
		q.alterDistance(v, sourceToVWeight);
		prev[v] = u;
		if (checkIfTarget(v)){
			cout << "prev[v] : " << prev[v] << ", u : " << u << endl;
		}
		q.decrease_key(v, sourceToVWeight); //!!!!!!!!!!!!! PRIORITY VS DISTANCE ? !!!!!!!!!!!!!!!!!
	}
}
int Bellman::shortest_path(){
	for (int u = 0; u < N; ++u){
		for (int k = 0; k < neighbourCount(u); ++k){
			Node * v = &(adj[u].at(k));
			if (q.getDistance(v->value) == -1) continue;
			relax(u, v->value);
		}
	}
	printPath(destination);
	return 0;
}
bool Bellman::checkIfTarget(int u){
	if (u == destination){
		return true;
	}
	return false;
}
void Bellman::printPath(int u){
	stack<int> path = stack<int>();
	int next_node = u;
	path.push(next_node);
	int previous_node = -1;
	int count = 0;
	while (previous_node != source){
		previous_node = prev[next_node];
		++count;
		if (previous_node == -1){
			cout << "ERROR : PATH DOES NOT EXIST! - OR SOMETHING WENT WRONG : " << count << endl;
			return;
		}
		path.push(previous_node);
		next_node = previous_node;
	}
	while (!path.empty()){
		cout << path.top() << " ";
		path.pop();
	}
}
