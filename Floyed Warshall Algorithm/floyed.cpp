#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
vector <int> result;
void findingThePath(int edge1, int edge2 , vector< vector<int> > path) {
	if (path[edge1][edge2] == edge1 || path[edge1][edge2] == INF) return;
	findingThePath(edge1, path[edge1][edge2], path);
	result.push_back(path[edge1][edge2]);
}
int main(void) {
	int verticesNum, edgesNum;
	cin >> verticesNum >> edgesNum;
	vector< vector<int> > minDist(verticesNum, vector<int>(verticesNum, INF));
	vector< vector<int> > pathTracking(verticesNum, vector<int>(verticesNum, INF));
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2, weight;
		cin >> edge1 >> edge2 >> weight;
		minDist[edge1][edge2] = weight;
		pathTracking[edge1][edge2] = edge1;
	}
	//distance from vertix to itself is zero (Assume no self cycles)
	for (int i = 0; i < verticesNum; i++) minDist[i][i] = 0;
	// finding shortest distance from vertix i to vertix j passing through vertix k
	for (int k = 0; k < verticesNum; k++) {
		for (int i = 0; i < verticesNum; i++) {
			for (int j = 0; j  < verticesNum; j++) {
				if ((minDist[i][j] == minDist[i][k] && minDist[i][j] == INF) || (minDist[i][j] == minDist[k][j] && minDist[i][j] == INF)) continue;
				if (minDist[i][j] > minDist[i][k] + minDist[k][j]) {
					minDist[i][j] = minDist[i][k] + minDist[k][j];
					pathTracking[i][j] = pathTracking[k][j];
				}
			}
		}
	}
	for (int i = 0; i < verticesNum; i++) {
		for (int j = 0; j < verticesNum; j++) {
			if (minDist[i][j] == INF) continue;
			cout << "Min Distance between vertix " << i << " to " << j << " : " << minDist[i][j] << endl;
			findingThePath(i, j, pathTracking);
			cout << "The path is " << i << " --> ";
			for (int k = 0; k < result.size(); k++) {
				cout << result[k] << " --> ";
			}
			cout << j << endl;
			result.clear();
		}
	}

	return 0;
}