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

node findSet(int data) {
	if (mapping[data].parent == data) return mapping[data];
	return findSet(mapping[data].parent);
}

bool unionSet(int data1, int data2) {
	node newData1 = findSet(data1);
	node newData2 = findSet(data2);
	if (newData1.parent == newData2.parent) return false;
	
	if (newData1.rank >= newData2.rank) {
		newData1.rank == newData2.rank ? mapping[newData1.parent].rank++ : mapping[newData1.parent].rank;
		mapping[newData2.parent].parent = newData1.parent;
	}
	else mapping[newData1.parent].parent = newData2.parent;
	return true;
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	vector < pair<int, int> > edges(edgesNum);
	vector <int> vertices;
	for (int i = 0; i < edgesNum; i++) {
		cin >> edges[i].first >> edges[i].second;
		vertices.push_back(edges[i].first);
		vertices.push_back(edges[i].second);
	}
	sort(vertices.begin(), vertices.end());
	vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
	for (int i = 0; i < vertices.size(); i++) makeSet(vertices[i]);
	for (int i = 0; i < edges.size(); i++) {
		if (!unionSet(edges[i].first, edges[i].second)) {
			cout << "Edge " << edges[i].first << "->" << edges[i].second << " form a cycle" << endl;
			return 0;
		}
	}
	cout << "No Cycles are detected" << endl;
	return 0;
}