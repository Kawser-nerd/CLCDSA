#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define Min(...) min({__VA_ARGS__})
#define Max(...) max({__VA_ARGS__})
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
static inline ll sgn(ll x) { return (x>0)-(x<0); }
static inline bool vowel(char c) { c = (char)tolower(c); return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y'; }
static inline vi rvi(int N) { vi res(N); rep(i,0,N) cin >> res[i]; return res; }
static inline int ri() { int N; cin >> N; return N; }
static inline void pvi(const vi& r) { trav(it,r) cout << it << " "; cout << endl; }
template<class S, class T> static inline void smax(S& s, const T& t) { if (t > s) s = t; }
template<class S, class T> static inline void smin(S& s, const T& t) { if (t < s) s = t; }
template<class S> static inline void in(S& s) { cin >> s; }
template<class S> static inline void ut(const S& s) { cout << s << " "; }
static inline void nl() { cout << endl; }

bool hopcroftKarp_dfs(int a, int layer, const vector<vector<int> >& AtoB, vector<int>& BtoA, vector<int>& layerA, vector<int>& layerB) {
	if(layerA[a] != layer) return false;
	layerA[a] = -1;
	int layerNextB = layer + 1, layerNextA = layer + 2;
	for(int i = 0; i < (int)AtoB[a].size(); ++i) {
		int b = AtoB[a][i];
		if(layerB[b] != layerNextB) continue;
		layerB[b] = -1;
		if(BtoA[b] == -1 || hopcroftKarp_dfs(BtoA[b], layerNextA, AtoB, BtoA, layerA, layerB))
			return BtoA[b] = a, true;
	}
	return false;
}

int hopcroftKarp(const vector<vector<int> >& AtoB, vector<int>& BtoA) {
	int incrMatching = 0, bfsAEnd, bfsANextEnd;
	vector<int> layerA(AtoB.size()), layerB(BtoA.size()), bfsA(AtoB.size()), bfsANext(AtoB.size());
	while(true) {
		fill(layerA.begin(), layerA.end(), 0);
		fill(layerB.begin(), layerB.end(), -1);
		// Find the starting nodes for BFS (i.e. layer 0).
		for(int b = 0; b < (int)BtoA.size(); ++b)
			if(BtoA[b] != -1) layerA[BtoA[b]] = -1;
		bfsAEnd = 0;
		for(int a = 0; a < (int)AtoB.size(); ++a)
			if(layerA[a] == 0) bfsA[bfsAEnd++] = a;
		// Find all layers using bfs.
		for(int layerNext = 1;; ++layerNext) {
			bool layerIsLast = false;
			bfsANextEnd = 0;
			for(int bfsAPos = 0; bfsAPos < bfsAEnd; ++bfsAPos) {
				int a = bfsA[bfsAPos];
				for(int i = 0; i < (int)AtoB[a].size(); ++i) {
					int b = AtoB[a][i];
					if(BtoA[b] == -1) {
						layerB[b] = layerNext;
						layerIsLast = true;
					}
					else if(BtoA[b] != a && layerB[b] == -1) {
						layerB[b] = layerNext;
						bfsANext[bfsANextEnd++] = BtoA[b];
					}
				}
			}
			if(layerIsLast) break;
			if(bfsANextEnd == 0) return incrMatching;
			++layerNext;
			for(int bfsANextPos = 0; bfsANextPos < bfsANextEnd; ++bfsANextPos) {
				int a = bfsANext[bfsANextPos];
				layerA[a] = layerNext;
			}
			bfsAEnd = bfsANextEnd;
			bfsA.swap(bfsANext);
		}
		// Use DFS to scan for augmenting paths.
		for(int a = 0; a < (int)AtoB.size(); ++a) {
			if(hopcroftKarp_dfs(a, 0, AtoB, BtoA, layerA, layerB))
				++incrMatching;
		}
	}
}

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

void solve() {
	int R, C, M;
	cin >> C >> R >> M;

	vector<string> G(R);
	rep(i,0,R) cin >> G[i];

	vector<vector<vector<pii>>> los(R, vector<vector<pii>>(C));

	set<pii> dead;
	map<pii, int> tToId;
	auto markbfs = [&](int r, int c) {
		int cur = sz(tToId);
		tToId[pii(r, c)] = cur;
		los[r][c].emplace_back(r, c);
		rep(i,0,4) {
			int nr = r;
			int nc = c;
			while (true) {
				nr += dr[i];
				nc += dc[i];
				if (nr >= 0 && nc >= 0 && nr < R && nc < C && G[nr][nc] != '#') {
					los[nr][nc].emplace_back(r, c);
				} else break;
			}
		}
	};

	rep(i,0,R) rep(j,0,C) {
		if (G[i][j] == 'T') {
			markbfs(i, j);
		}
	}

	vector<vector<vector<pii>>> cansee(R, vector<vector<pii>>(C));

	set<pii> isused;
	map<pii, int> sToId;
	auto bfs = [&](int r, int c) {
		int cur = sz(sToId);
		sToId[pii(r, c)] = cur;
		map<pii, int> seen;
		queue<pii> q;
		q.emplace(r, c);
		seen[pii(r, c)] = 0;
		set<pii> sees;
		while (!q.empty()) {
			pii nx = q.front(); q.pop();
			int d = seen[nx];
			sees.insert(all(los[nx.first][nx.second]));
			if (d + 1 <= M) {
				rep(i,0,4) {
					int nr = nx.first + dr[i];
					int nc = nx.second + dc[i];
					if (nr >= 0 && nc >= 0 && nr < R && nc < C && G[nr][nc] != '#' && seen.find(pii(nr, nc)) == seen.end()) {
						seen[pii(nr, nc)] = d + 1;
						q.emplace(nr, nc);
					}
				}
			}
		}
		cansee[r][c] = vector<pii>(all(sees));
	};

	rep(i,0,R) rep(j,0,C) {
		if (G[i][j] == 'S') {
			bfs(i, j);
		}
	}

	auto bfs3 = [&](int r, int c) {
		map<pii, int> seen;
		queue<pii> q;
		q.emplace(r, c);
		seen[pii(r, c)] = 0;
		set<pii> sees;
		while (!q.empty()) {
			pii nx = q.front(); q.pop();
			int d = seen[nx];
			bool skip = false;
			trav(it, los[nx.first][nx.second]) {
				if (dead.find(it) != dead.end()) continue;
				sees.emplace(it);
				skip = true;
			}
			if (skip) continue;
			if (d + 1 <= M) {
				rep(i,0,4) {
					int nr = nx.first + dr[i];
					int nc = nx.second + dc[i];
					if (nr >= 0 && nc >= 0 && nr < R && nc < C && G[nr][nc] != '#' && seen.find(pii(nr, nc)) == seen.end()) {
						seen[pii(nr, nc)] = d + 1;
						q.emplace(nr, nc);
					}
				}
			}
		}
		return vector<pii>(all(sees));
	};

	auto whatismax = [&](){
		vector<vi> AtoB(sz(sToId));
		vi BtoA(sz(tToId), -1);
		trav(it, sToId) {
			if (isused.find(it.first) != isused.end()) continue;
			trav(it2, cansee[it.first.first][it.first.second]) {
				if (dead.find(it2) != dead.end()) continue;
				AtoB[it.second].push_back(tToId[it2]);
			}
		}
		return hopcroftKarp(AtoB, BtoA);
	};

	int cur = whatismax();
	cout << cur << endl;
	rep(i,0,cur) {
		int alive = cur - i;
		trav(it, sToId) {
			if (isused.find(it.first) != isused.end()) continue;
			vector<pii> canreach = bfs3(it.first.first, it.first.second);

			isused.insert(it.first);
			trav(it2, canreach) {
				dead.insert(it2);
				if (whatismax() == alive - 1) {
					cout << (it.second+1) << " " << (tToId[it2]+1) << endl;
					goto done;
				}
				dead.erase(it2);
			}
			isused.erase(it.first);
		}
		assert(false);
done:;
	}
}

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int TC;
	cin >> TC;
	rep(i,0,TC) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
