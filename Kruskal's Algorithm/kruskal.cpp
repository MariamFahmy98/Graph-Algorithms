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
vector <pair <int, pair<int, int>> > edges;
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
	vector <int> vertices;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2, weight;
		cin >> edge1 >> edge2 >> weight;
		vertices.push_back(edge1);
		vertices.push_back(edge2);
		edges.push_back(make_pair(weight, make_pair(edge1, edge2)));
	}
	sort(edges.begin(), edges.end());
	sort(vertices.begin(), vertices.end());
	vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
	for (int i = 0; i < vertices.size(); i++) makeSet(vertices[i]);
	vector < pair<int, int> > result;
	int minWeight = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (unionSet(edges[i].second.first, edges[i].second.second)) {
			result.push_back(make_pair(edges[i].second.first, edges[i].second.second));
			minWeight += edges[i].first;
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i].first << " " << result[i].second << endl;
	}
	cout << minWeight << endl;
	return 0;
} 