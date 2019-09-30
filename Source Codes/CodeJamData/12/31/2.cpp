#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		int N, M, x;
		cin >> N;
		vector<vector<int>> edge(N);
		for (int i=0; i<N; i++) {
			cin >> M;
			edge[i].resize(M);
			for (int j=0; j<M; j++) {
				cin >> x;
				edge[i][j] = x-1;
			}
		}
		bool yes = false;
		vector<bool> visited(N);
		queue<int> q;
		for (int i=0; i<N; i++) {
			fill(visited.begin(), visited.end(), false);
			while (!q.empty()) q.pop();
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int x = q.front(); q.pop();
				for (unsigned int j=0; j<edge[x].size(); j++) {
					int y = edge[x][j];
					if (visited[y]) yes = true;
					else {
						visited[y] = true;
						q.push(y);
					}
				}
				if (yes) break;
			}
			if (yes) break;
		}
		cout << "Case #" << t << ": " << (yes?"Yes\n":"No\n");
	}
	return 0;
}
