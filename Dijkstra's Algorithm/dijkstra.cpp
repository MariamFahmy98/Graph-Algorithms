#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define INFINITY 0x3f3f3f3f
int verticesNum, edgesNum, source;
vector < pair<int, int> > table[2000];
void dijkstraAlgo(int sourceV, vector<int>& minDist ,vector<int> &parent) {
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> >> pq;
	pq.push(make_pair(0, sourceV));
	minDist[sourceV] = 0;
	parent[sourceV] = 0;
	while (!pq.empty()) {
		int minV = pq.top().second;
		pq.pop();
		for (int i = 0; i < table[minV].size(); i++) {
			int vertix = table[minV][i].first;
			int weight = table[minV][i].second;
			if (minDist[vertix] > weight + minDist[minV]) {
				minDist[vertix] = weight + minDist[minV];
				pq.push(make_pair(minDist[vertix], vertix));
				parent[vertix] = minV;
			}
		}
	}
}
int main(void) {
	cin >> verticesNum >> edgesNum >> source;
	for (int i = 0; i < edgesNum; i++) {
		int edge1, edge2, weight;
		cin >> edge1 >> edge2 >> weight;
		table[edge1].push_back(make_pair(edge2, weight));
		table[edge2].push_back(make_pair(edge1, weight));
	}
	vector <int> minDist(verticesNum,INFINITY);
	vector <int> parent(verticesNum);
	dijkstraAlgo(source, minDist, parent);
	for (int i = 0; i < verticesNum; i++) {
		if (i == source) continue;
		cout << "Min Distance from " << source << " to " << i << " is " << minDist[i] << endl;
	}
    
	return 0;
}