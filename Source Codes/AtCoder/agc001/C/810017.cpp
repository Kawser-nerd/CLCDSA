#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>

using namespace std;

typedef long long ll;

int N, K;
vector<vector<int>> graph;


int bfs1(int root)
{
	vector<int> used(N);
	vector<int> dist(N);
	
	queue<int> que;
	que.push(root);
	used[root] = 1;
	dist[root] = 0;

	int cnt = 1;
	while(!que.empty()) {
		int x = que.front(); que.pop();

		for(int to : graph[x]) {
			if(!used[to] && dist[x] < K / 2) {
				used[to] = 1;
				dist[to] = dist[x] + 1;
				que.push(to);
				cnt++;
			}
		}
	}

	return N - cnt;
}

int bfs2(int root1, int root2)
{
	vector<int> used(N);
	vector<int> dist(N);
	
	queue<int> que;
	que.push(root1);
	que.push(root2);
	used[root1] = 1;
	dist[root1] = 0;
	used[root2] = 1;
	dist[root2] = 0;
	
	int cnt = 2;
	while(!que.empty()) {
		int x = que.front(); que.pop();

		for(int to : graph[x]) {
			if(!used[to] && dist[x] < K / 2) {
				used[to] = 1;
				dist[to] = dist[x] + 1;
				que.push(to);
				cnt++;
			}
		}
	}

	return N - cnt;
}

int main()
{
	cin >> N >> K;

	graph = vector<vector<int>>(N);

	for(int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	int ans = N;
	if(K % 2 == 0) {
		for(int i = 0 ; i < N; ++i) {
			ans = min(ans, bfs1(i));
		}
	} else {
		for(int i = 0; i < N; ++i) {
			for(int to : graph[i]) {
				ans = min(ans, bfs2(i, to));
			}
		}
	}

	cout << ans << endl;
}