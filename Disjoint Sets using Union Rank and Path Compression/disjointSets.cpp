#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
struct node {
	int rank;
	int parent;
};
map <int, node> mapping;

void makeSet(int data) {
	node newNode;
	newNode.rank = 0;
	newNode.parent = data;
	mapping[data] = newNode;
}
//finding the representative node for this data and applying path compression
node findData(int data) {
	if (mapping[data].parent == data) return mapping[data];
	return findData(mapping[data].parent);
}
void unionSets(int data1, int data2) {
	node nodeData1 = findData(data1);
	node nodeData2 = findData(data2);
	//checking if they are in the same set
	if (nodeData1.parent == nodeData2.parent) return;

	if (nodeData1.rank >= nodeData2.rank) {
		if (nodeData1.rank == nodeData2.rank) {
			mapping[nodeData1.parent].rank++;
		}
		mapping[nodeData2.parent].parent = nodeData1.parent;
	}
	else {
		mapping[nodeData1.parent].parent = nodeData2.parent;
	}
}

int main(void) {
	makeSet(1);
	makeSet(2);
	makeSet(3);
	makeSet(4);
	makeSet(5);
	makeSet(6);
	makeSet(7);

	unionSets(1, 2);
	unionSets(2, 3);
	unionSets(4, 5);
	unionSets(6, 7);
	unionSets(5, 6);
	unionSets(3, 7);

	for (int i = 1; i <= 7; i++) {
		node output = findData(i);
		cout << output.parent << " ";
	}
	cout << endl;
	return 0;
}