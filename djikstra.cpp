#include "djikstra.h"
#include "minheap.h"

Djikstra::Djikstra() {
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
Djikstra::~Djikstra(){
	delete [] source_distance;
}
int Djikstra::getMin(){
	return q.extractMinIndex();
}
int Djikstra::getMinLinear(){
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
void Djikstra::relax(const int u, const int v){
	int sourceToVWeight = q.getDistance(u) + getWeight(u,v); 
	if (q.getDistance(v) > sourceToVWeight){	
		q.alterDistance(v, sourceToVWeight);
		prev[v] = u;
		if (checkIfTarget(v)){
			cout << "prev[v] : " << prev[v] << ", u : " << u << endl;
		}
		q.decrease_key(v, sourceToVWeight); 
	}
}
int Djikstra::shortest_path(){
	int count = 0;
	while (true){
		int u = getMin();
		if (checkIfTarget(u)){
			printPath(u);
			return q.getDistance(u);
		}
		if (count < neighbourCount(u))
			count = neighbourCount(u);
		for (int i = 0; i < neighbourCount(u); ++i){
			Node * v = &(adj[u].at(i));
			if (q.getDistance(v->value) == -1) continue; //!!!!!!!!!!
			relax(u, v->value);
		}
		q.alterDistance(u, -1);
	}
}
bool Djikstra::checkIfTarget(int u){
	if (u == destination){
		return true;
	}
	return false;
}
void Djikstra::printPath(int u){
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