#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<unordered_map>
#define int long long
#define rep(i,a,n) for (int (i)=(a);(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef long double ld;
int a[200001];
vector<int>e[200001];
signed  main() {
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	queue<int>q;
	q.push(s);
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
	}
	a[s] = s;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int i = 0; i < e[t].size(); i++) {
			if (a[e[t][i]] < min(t, min(a[t], e[t][i]))) {
				a[e[t][i]] = min(t, min(a[t], e[t][i]));
				q.push(e[t][i]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] >= i)
			cout << i << endl;
	}
	getchar(); getchar();
}