#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
int verticesNum, edgesNum, sourceV;
vector < pair<int, int> > edges[3000];
bool bellmanFord(int u, int v, int weight , vector<pair<int, int>>& minD) {
	if (minD[v].first == INF && minD[u].first == INF) return false;
	if (minD[v].first > minD[u].first + weight) {
		minD[v].first = minD[u].first + weight;
		minD[v].second = u;
		return true;
	}
	return false;
}
int main(void) {
	cin >> verticesNum >> edgesNum;
	cin >> sourceV;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2, weight;
		cin >> edge1 >> edge2 >> weight;
		edges[edge1].push_back(make_pair(edge2, weight));
	}
	// mapping each vertix to its min distance from source vertix and its parent
	vector< pair<int, int>> minD(verticesNum, make_pair(INF,INF));
	minD[sourceV].first = 0;
	bool flag = false;
	for (int i = 0; i < verticesNum - 1; i++) {
		for (int j = 0; j < verticesNum; j++) {
			for (int k = 0; k < edges[j].size(); k++) bool f = bellmanFord(j, edges[j][k].first, edges[j][k].second, minD);
		}	
	}
	// checking if there if a negative weight cycle
	for (int j = 0; j < verticesNum; j++) {
		for (int k = 0; k < edges[j].size(); k++) {
			flag = bellmanFord(j, edges[j][k].first, edges[j][k].second, minD);
			if (flag) break;
		}
	}
	if (flag) cout << "A negative Weight Cycle is detected" << endl;
	else {
		for (int i = 0; i < minD.size(); i++) {
			cout << "Min Distance from " << sourceV << " to " << i << " : " << minD[i].first << endl;
		}
		// finding the shortest path for each vertix
		for (int i = 0; i < minD.size(); i++) {
			if (i == sourceV) continue;
			int parent = minD[i].second;
			cout << i ;
			while (parent != INF) {
				cout << " <-- " << parent;
				parent = minD[parent].second;
			}
			cout << endl;
		}
	}
	return 0;
}