#include<bits/stdc++.h>
using namespace std;

const int MAXV = 4000;

map<string, int> mp;
int V;

vector<int> adj[MAXV];
int prv[MAXV];
int vis[MAXV];

bool dfs(int a) {
	if(vis[a]) return false;
	vis[a] = true;
	
	if(prv[a] != -1) {
		if(dfs(prv[a])) {
			prv[a] = -1;
			return true;
		}
	}

	for(int b : adj[a]) {

		if(b == 1) return true;

		if(prv[b] == a) continue;

		if(dfs(prv[b] == -1 ? b : prv[b])) {
			prv[b] = a;
			return true;
		}
	}

	return false;
}

int mincut() {

	memset(prv, -1, sizeof(prv));
	int res = 0;

	memset(vis, 0, sizeof(vis));

	while(dfs(0)) {
		memset(vis, 0, sizeof(vis));
		res++;
	}

	return res;
}

int get_ind(const string &s) {
	if(mp.count(s)) return mp[s];
	return mp[s] = V++;
}

int go() {
	mp.clear();
	int N; cin >> N;
	// read N + 2 lines
	string s; getline(cin, s); // eat up the last line
	V = 2;
	for(int l = 0; l < N; l++) {
		getline(cin, s);
		istringstream in(s);
		vector<int> w;
		while(in >> s) {
			w.push_back(get_ind(s));
		}

		if(l == 0) {
			for(int i = 0; i < int(w.size()); i++) {
				int a = w[i];
				adj[0].push_back(a);
			}
		} else if(l == 1) {
			for(int i = 0; i < int(w.size()); i++) {
				int a = w[i];
				adj[a].push_back(1);
			}
		} else {
			for(int i = 0; i < int(w.size()); i++) {
				for(int j = i + 1; j < int(w.size()); j++) {
					int a = w[i], b = w[j];
					adj[a].push_back(b);
					adj[b].push_back(a);
				}
			}
		}
	}
	
	int res = mincut();

	for(int i = 0; i < V; i++) { adj[i].clear(); }

	return res;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		int res = go();
		cout << "Case #" << t << ": " << res << '\n';
	}
	return 0;
}
