#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <unordered_set>
#include <cmath>
#include <climits>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 201

using namespace std;
int N, M, R;
vector<int> r;
bool visited[NCONS];
ll dist[NCONS][NCONS];
vector<ll> result;

ll dfs(int cur_node)
{
	ll ret = LLONG_MAX;
	if (result.size() >= (R - 1))
	{
		ret = 0;
		for (int i = 0; i < result.size(); i++)
			ret += result[i];
		return ret;
	}

	for (int i = 0; i < r.size(); i++)
	{
		auto cand = r[i];
		if (visited[cand]) continue;
		visited[cand] = true;

		result.push_back(dist[cur_node][cand]);

		ret = min(ret, dfs(cand));

		visited[cand] = false;
		result.pop_back();
		
	}
	return ret;

}


int main(void)
{
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> M >> R;
	for (int i = 0; i < R; i++) { int temp; cin >> temp; r.push_back(temp); }
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) dist[i][j] = LLONG_MAX / 2;
	for (int i = 1; i <= N; i++) dist[i][i] = 0;
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	ll ret = LLONG_MAX;
	for (int i = 0; i < r.size(); i++)
	{
		auto cur_node = r[i];
		visited[cur_node] = true;
		ret = min(ret, dfs(cur_node));
		visited[cur_node] = false;
	}

	cout << ret << endl;
	return 0;
}