#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
stack <int> finalVertices;
vector <int> originalGraph[3000];
vector <int> reversedGraph[3000];
vector <int> result;
vector < vector<int> > connectedComp;
void DFS(int vertix , vector<bool> &visited , vector<int> graph[]) {
	visited[vertix] = true;
	for (int i = 0; i < graph[vertix].size(); i++) {
		if (!visited[graph[vertix][i]]) {
			DFS(graph[vertix][i], visited, graph);
		}
	}
	if(graph == originalGraph) finalVertices.push(vertix);
	else {
		result.push_back(vertix);
	}
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2;
		cin >> edge1 >> edge2;
		originalGraph[edge1].push_back(edge2);
		reversedGraph[edge2].push_back(edge1);
	}
	vector <bool> originalVisited(verticesNum, false);
	vector <bool> reversedVisited(verticesNum, false);
	for (int i = 0; i < verticesNum; i++) {
		if (!originalVisited[i]) DFS(i, originalVisited, originalGraph);
	}
	while (!finalVertices.empty()) {
		if (!reversedVisited[finalVertices.top()]) {
			result.clear();
			DFS(finalVertices.top(), reversedVisited, reversedGraph);
			connectedComp.push_back(result);
		}
		finalVertices.pop();
	}
	for (int i = 0; i < connectedComp.size(); i++) {
		cout << "Strongly Connected Component: ";
		for (int j = 0; j < connectedComp[i].size(); j++) {
			cout << connectedComp[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}