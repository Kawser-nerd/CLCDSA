#include <iostream>
#include <vector>
using namespace std;
const int MAXn = 1e5 + 10;
vector<int> g[MAXn];
int n, odd[MAXn], even[MAXn];

int dfs(int v, int par) {
	if (g[v].size() == 1 && par != 0)
		return 1;
	int cnt = 0;
	for (int i = 0; i < g[v].size(); i++)
		if (g[v][i] != par) {
			cnt += dfs(g[v][i], v);
			
		}
	if (cnt > 1) {
		cout << "First";
		exit(0);
	}
	if (cnt == 1) 
		return 0;
	if (par == 0) {
		cout << "First";
		exit(0);
	}
		
	return 1;
}


int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u>> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	
	cout << "Second";
	
}