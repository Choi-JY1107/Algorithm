#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
const int MAX = 101;
const int INF = 987654321;

int main() {
	int n, m, a, b, c;
	int arr[MAX][MAX];
	cin >> n >> m;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(i!=j) arr[i][j] = INF;
			else arr[i][j] = 0;
		}
	}
			
	for(int i=0; i<m; ++i){
		cin >> a >> b >> c;
		arr[a][b] = min(c, arr[a][b]);
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			for(int k=1; k<=n; ++k)
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(arr[i][j] == INF) cout << "0";
			else cout << arr[i][j];
			cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}
