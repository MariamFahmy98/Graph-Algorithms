//topological sort
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
int verticesNum, edgesNum;
vector<int> table[2000];
vector <bool> visited(2000, false);
void DFS(int vertix , stack <int> &result) {
	visited[vertix] = true;
	for (int i = 0; i < table[vertix].size(); i++) {
	if (visited[table[vertix][i]]) continue;
	DFS(table[vertix][i], result);
	}
	result.push(vertix);
}
int main(void) {
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2;
		cin >> edge1 >> edge2;
		// indicats an exist edge from edge1 to edge2
		table[edge1].push_back(edge2);
	}
	stack <int> result;
	for (int i = 0; i < verticesNum; i++) {
		if (!visited[i]) DFS(i, result);
	}
	vector <int> output, output1;
	while(! result.empty()) {
		output.push_back(result.top());
		result.pop();
	}
	for(int j = output.size()-1 ; j >= 0 ; j--) output1.push_back(output[j]);
	for(int j = 0 ; j < output1.size() ; j++) cout << output1[j] <<" ";
	cout << endl;
	return 0;
}