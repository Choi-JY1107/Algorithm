#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define endl '\n'
typedef pair<int, int> p;
const int MAX = 20010;
const int INF = 987654321;

int vertex, edge;
int dist[MAX];
vector <pair <int, int> > v[MAX];

int main() {
	int start;
	priority_queue<p, vector<p>, greater<p> > pq;
	cin >> vertex >> edge;
	cin >> start;
	for(int i=1; i<=vertex; ++i) dist[i] = INF; 
	pq.push({0, start});
	dist[start] = 0;
	
	for(int i=0; i<edge; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b,c});
	}
	
	while(!pq.empty()){
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		int vSize = v[now].size();
		for(int i=0; i<vSize; ++i){
			int next = v[now][i].first;
			int nCost = v[now][i].second;
			if(dist[next] > nCost + cost){
				dist[next] = nCost + cost;
				pq.push({dist[next], next});
			}
		}
	}
	
	for(int i=1; i<=vertex; ++i) {
		if(dist[i] == INF) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
	
	return 0;
}
