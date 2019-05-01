#pragma once

class Node {
public:
	int value;
	int u_distance;
	Node(int value, int u_distance) : value(value), u_distance(u_distance) {}
};