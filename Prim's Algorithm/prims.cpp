#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define INFINITY 0x3f3f3f3f
int verticesNum, edgesNum;
vector < pair<int, int> > table[2000];
void PrimsAlgo(int vertix, vector <int> & result) {
	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> pq;
	vector <int> keys(verticesNum, INFINITY);
	vector <bool> inPRIMS(verticesNum, false);
	pq.push(make_pair(0, vertix));
	keys[vertix] = 0;
	while (!pq.empty()) {
		int minV = pq.top().second;
		pq.pop();
		inPRIMS[minV] = true;
		for (int i = 0; i < table[minV].size(); i++) {
			int v = table[minV][i].first;
			int weight = table[minV][i].second;
			if (keys[v] > weight && !inPRIMS[v]) {
				keys[v] = weight;
				pq.push(make_pair(keys[v], v));
				result[v] = minV;
			}
		}
	}
}
int main(void) {
	cin >> verticesNum >> edgesNum;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2, weight;
		cin >> edge1 >> edge2 >> weight;
		table[edge1].push_back(make_pair(edge2, weight));
		table[edge2].push_back(make_pair(edge1, weight));
	}
	vector <int> result(verticesNum);
	PrimsAlgo(0,result);
	for (int i = 1; i < verticesNum; i++) {
		cout << result[i] << " " << i << endl;
	}
	return 0;
}