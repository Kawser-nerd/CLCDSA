#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int maxn = 1e5 + 9;
pair<int, int> arr[maxn];
vector<int> adj[maxn];
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	int ans = 0;
	set<int> st;
	for (int i = 1; i <= n; i++) {
		if (st.find(i) != st.end()) { 
			st.clear();
			ans++;
		}
		for (auto v : adj[i]) {
			st.insert(v);
		}
	}
	cout << ans << '\n';
	return 0;
}