#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
vector <int> edges[4000];
void DFS(int vertix, set <int>& notVisited, set<int>& partiallyVisited, set<int>& totallyVisited) {
	if (notVisited.find(vertix) != notVisited.end()) notVisited.erase(vertix);
	if (partiallyVisited.find(vertix) == partiallyVisited.end()) partiallyVisited.insert(vertix);
	for (int i = 0; i < edges[vertix].size(); i++) {
		if (notVisited.find(edges[vertix][i]) != notVisited.end()) {
			DFS(edges[vertix][i], notVisited, partiallyVisited, totallyVisited);
		}
		if (partiallyVisited.find(edges[vertix][i]) != partiallyVisited.end())	return;
	}
	if (partiallyVisited.find(vertix) != partiallyVisited.end()) {
		partiallyVisited.erase(vertix);
		totallyVisited.insert(vertix);
	}
}

int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2;
		cin >> edge1 >> edge2;
		edges[edge1].push_back(edge2);
	}
	set <int> notVisited;
	set <int> partiallyVisited;
	set <int> totallyVisited;
	for (int i = 0; i < verticesNum; i++) notVisited.insert(i);
	for (int i = 0; i < verticesNum; i++) {
		if (notVisited.find(i) != notVisited.end()) DFS(i, notVisited, partiallyVisited, totallyVisited);
	}
	if (partiallyVisited.empty()) cout << "No Cycles Found" << endl;
	else {
		cout << "A cycle is detected" << endl;
	}
	return 0;
}