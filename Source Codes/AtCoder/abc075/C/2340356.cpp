#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;
using ll = long long;
const int NMAX = 50;
bool graph[NMAX][NMAX];

int dfs(int v, int N, bool visited[NMAX]); 

int main() {
	int N,M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		graph[a - 1][b - 1] = true;
		graph[b - 1][a - 1] = true;
	}

	int ans = 0;
	bool visited[NMAX];
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	visited[0] = true;

	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (graph[i][j]) {
				graph[i][j] = false;
				graph[j][i] = false;
				if (!dfs(0,N,visited)) {
					ans++;
				}
				for (int i = 0; i < N; i++) {
					visited[i] = false;
				}
				visited[0] = true;
				graph[i][j] = true;
				graph[j][i] = true;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

int dfs(int v, int N, bool visited[NMAX]) {

	bool all_visited = true;
	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			all_visited = false;
		}
	}

	if (all_visited) {
		return true;
	}

	bool ret = false;

	for (int i = 0; i < N; i++) {
		if (graph[v][i] && !visited[i]) {
			visited[i] = true;
			ret = dfs(i,N,visited);
		}
	}

	return ret;

}