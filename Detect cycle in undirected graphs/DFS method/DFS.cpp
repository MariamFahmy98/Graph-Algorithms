#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

vector <int> table[2000];
bool detectCylceDFS(int vertix, int parent , vector <bool> &visited) {
	visited[vertix] = true;
	for (int i = 0; i < table[vertix].size(); i++) {
		if (!visited[table[vertix][i]]) {
			if (detectCylceDFS(table[vertix][i], vertix, visited)) return true;
		}
		else if (table[vertix][i] != parent) return true;
	}
	return false;
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	vector <bool> visited(verticesNum, false);
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2;
		cin >> edge1 >> edge2;
		table[edge1].push_back(edge2);
		table[edge2].push_back(edge1);
	}
	bool flag = true;
	for (int i = 0; i < verticesNum; i++) {
		if (!visited[i]) {
			if (detectCylceDFS(i, -1, visited)) {
				flag = false;
				break;
			}
		}
	}
	if (! flag) cout << "A Cycle is detected" << endl;
	else cout << "No cycle is detected" << endl;
	return 0;
}