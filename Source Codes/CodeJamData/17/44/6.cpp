#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<ll> vd;
bool zero(ll x) { return x == 0; }
ll MinCostMatching(const vector<vd>& cost, vi& L, vi& R) {
	int n = sz(cost), mated = 0;
	vd dist(n), u(n), v(n);
	vi dad(n), seen(n);

	/// construct dual feasible solution
	rep(i,0,n) {
		u[i] = cost[i][0];
		rep(j,1,n) u[i] = min(u[i], cost[i][j]);
	}
	rep(j,0,n) {
		v[j] = cost[0][j] - u[0];
		rep(i,1,n) v[j] = min(v[j], cost[i][j] - u[i]);
	}

	/// find primal solution satisfying complementary slackness
	L = vi(n, -1);
	R = vi(n, -1);
	rep(i,0,n) rep(j,0,n) {
		if (R[j] != -1) continue;
		if (zero(cost[i][j] - u[i] - v[j])) {
			L[i] = j;
			R[j] = i;
			mated++;
			break;
		}
	}

	for (; mated < n; mated++) { // until solution is feasible
		int s = 0;
		while (L[s] != -1) s++;
		fill(all(dad), -1);
		fill(all(seen), 0);
		rep(k,0,n)
			dist[k] = cost[s][k] - u[s] - v[k];

		int j = 0;
		for (;;) { /// find closest
			j = -1;
			rep(k,0,n){
				if (seen[k]) continue;
				if (j == -1 || dist[k] < dist[j]) j = k;
			}
			seen[j] = 1;
			int i = R[j];
			if (i == -1) break;
			rep(k,0,n) { /// relax neighbors
				if (seen[k]) continue;
				auto new_dist = dist[j] + cost[i][k] - u[i] - v[k];
				if (dist[k] > new_dist) {
					dist[k] = new_dist;
					dad[k] = j;
				}
			}
		}

		/// update dual variables
		rep(k,0,n) {
			if (k == j || !seen[k]) continue;
			auto w = dist[k] - dist[j];
			v[k] += w, u[R[k]] -= w;
		}
		u[s] += dist[j];

		/// augment along path
		while (dad[j] >= 0) {
			int d = dad[j];
			R[j] = R[d];
			L[R[j]] = j;
			j = d;
		}
		R[j] = s;
		L[s] = j;
	}

	auto value = vd(1)[0];
	rep(i,0,n) value += cost[i][L[i]];
	return value;
}

int R, C;
vector<string> board;

template<class F>
void forh(int ni, int nj, F f) {
	f(pii(ni, nj));

	pii pa = {ni, nj};
	for (;;) {
		pa.second--;
		if (pa.second < 0 || board[pa.first][pa.second] == '#') break;
		f(pa);
	}

	pa = {ni, nj};
	for (;;) {
		pa.second++;
		if (pa.second >= C || board[pa.first][pa.second] == '#') break;
		f(pa);
	}
}

template<class F>
void forv(int ni, int nj, F f) {
	f(pii(ni, nj));

	pii pa = {ni, nj};
	for (;;) {
		pa.first--;
		if (pa.first < 0 || board[pa.first][pa.second] == '#') break;
		f(pa);
	}

	pa = {ni, nj};
	for (;;) {
		pa.first++;
		if (pa.first >= R || board[pa.first][pa.second] == '#') break;
		f(pa);
	}
}

void solve(int cs) {
	int M;
	cin >> C >> R >> M;
	board.assign(R, string());
	rep(i,0,R) cin >> board[i];
	int solid = 0, turid = 0;
	vector<vi> sols(R, vi(C, -1));
	vector<vi> turs(R, vi(C, -1));
	vector<pii> solpa, turpa;
	rep(i,0,R) rep(j,0,C) {
		char c = board[i][j];
		if (c == 'S') sols[i][j] = solid++, solpa.emplace_back(i, j);
		if (c == 'T') turs[i][j] = turid++, turpa.emplace_back(i, j);
	}

	ll inf = 1LL << 29;
	vector<vd> mat(max(solid, turid), vd(max(solid, turid), inf));
	vector<vector<pii>> match(solid, vector<pii>(turid, pii(-3, -3)));

	rep(i,0,R) rep(j,0,C) {
		if (board[i][j] == 'S') {
			int sol = sols[i][j];
			queue<pii> q;
			vector<vi> dists(R, vi(C, INT_MAX));
			dists[i][j] = 0;
			q.push({i,j});
			while (!q.empty()) {
				pii pa = q.front();
				q.pop();
				int d = dists[pa.first][pa.second];
				const int DX[4] = {-1,1,0,0};
				const int DY[4] = {0,0,1,-1};
				rep(D,0,4) {
					int ni = pa.first + DX[D];
					int nj = pa.second + DY[D];
					if (ni < 0 || nj < 0 || ni >= R || nj >= C) continue;
					if (board[ni][nj] == '#') continue;
					if (dists[ni][nj] != INT_MAX) continue;
					if (d + 1 > M) continue;
					dists[ni][nj] = d + 1;
					q.push({ni, nj});
				}
			}

			vector<vector<pair<int, pii>>> besth(R, vector<pair<int, pii>>(C, make_pair(-1, pii(-1, -1)))), bestv = besth;
			rep(ni,0,R) rep(nj,0,C) if (board[ni][nj] == 'T') {
				if (besth[ni][nj].first == -1) {
					pair<int, pii> best{INT_MAX, pii(-1, -1)};
					forh(ni, nj, [&](pii pa) {
						best = min(best, pair<int, pii>{dists[pa.first][pa.second], pa});
					});
					// besth[ni][nj] = best;
					forh(ni, nj, [&](pii pa) {
						besth[pa.first][pa.second] = best;
					});
				}
				if (bestv[ni][nj].first == -1) {
					pair<int, pii> best{INT_MAX, pii(-1, -1)};
					forv(ni, nj, [&](pii pa) {
						best = min(best, pair<int, pii>{dists[pa.first][pa.second], pa});
					});
					// bestv[ni][nj] = best;
					forv(ni, nj, [&](pii pa) {
						bestv[pa.first][pa.second] = best;
					});
				}

				pair<int, pii> di = min(besth[ni][nj], bestv[ni][nj]);
				if (di.first != INT_MAX) {
					int tur = turs[ni][nj];
					mat[sol][tur] = di.first;
					match[sol][tur] = di.second;
					// edge from sol to tur of weight di
					// cerr << "edge " << sol << ' ' << tur << ' ' << di << endl;
				}
			}
		}
	}

	vi L, R_;
	ll cost = MinCostMatching(mat, L, R_);
	int bad = (int)(cost >> 29);
	int valid = max(solid, turid) - bad;
	cost &= (1 << 29) - 1;
	// vector<pii> ev;
	// rep(i,0,solid) if (mat[i][L[i]] < (1 << 29)) {
		// cerr << i+1 << ' ' << L[i]+1 << ' ' << mat[i][L[i]] << endl;
		// ev.emplace_back(mat[i][L[i]], i);
	// }
	// sort(all(ev));

	vector<vector<pii>> paths;
	rep(i,0,R) rep(j,0,C) {
		if (board[i][j] == 'S') {
			int sol = sols[i][j];
			if (mat[sol][L[sol]] >= (1 << 29)) continue;

			queue<pii> q;
			vector<vi> dists(R, vi(C, INT_MAX));
			vector<vector<pii>> pars(R, vector<pii>(C, pii(-2, -2)));
			dists[i][j] = 0;
			pars[i][j] = pii(-1, -1);
			q.push({i,j});
			while (!q.empty()) {
				pii pa = q.front();
				q.pop();
				int d = dists[pa.first][pa.second];
				const int DX[4] = {-1,1,0,0};
				const int DY[4] = {0,0,1,-1};
				rep(D,0,4) {
					int ni = pa.first + DX[D];
					int nj = pa.second + DY[D];
					if (ni < 0 || nj < 0 || ni >= R || nj >= C) continue;
					if (board[ni][nj] == '#') continue;
					if (dists[ni][nj] != INT_MAX) continue;
					if (d + 1 > M) continue;
					dists[ni][nj] = d + 1;
					pars[ni][nj] = pa;
					q.push({ni, nj});
				}
			}

			pii at = match[sol][L[sol]];
			vector<pii> path;
			while (at != pii(i, j)) {
				path.push_back(at);
				at = pars[at.first][at.second];
			}
			// reverse(all(path));
			// cerr << sz(path) << ' ' << mat[sol][L[sol]] << endl;
			assert(sz(path) == mat[sol][L[sol]]);
			paths.push_back(path);
		}
	}

	vi ids;
	rep(i,0,solid) {
		if (mat[i][L[i]] < (1 << 29))
			ids.push_back(i);
	}
	assert(sz(ids) == valid);

	vector<pii> positions;
	trav(i, ids) {
		positions.push_back(solpa[i]);
	}

	vi out;
	vector<vi> threat(R, vi(C,0));
	rep(tur,0,turid) {
		forh(turpa[tur].first, turpa[tur].second, [&](pii p) {
			threat[p.first][p.second]++;
		});
		forv(turpa[tur].first, turpa[tur].second, [&](pii p) {
			threat[p.first][p.second]++;
		});
		threat[turpa[tur].first][turpa[tur].second]--;
	}

	int rem = valid;
	auto done = [&](int i) {
		int tur = L[ids[i]];
		forh(turpa[tur].first, turpa[tur].second, [&](pii p) {
			threat[p.first][p.second]--;
		});
		forv(turpa[tur].first, turpa[tur].second, [&](pii p) {
			threat[p.first][p.second]--;
		});
		threat[turpa[tur].first][turpa[tur].second]++;
		--rem;
		out.push_back(ids[i]);
	};
	auto threatened = [&](pii p) {
		return threat[p.first][p.second] > 0;
	};

	rep(i,0,valid) {
		if (paths[i].empty()) done(i);
	}

	while (rem > 0) {
		bool hap = 0;
		rep(i,0,valid) {
			if (paths[i].empty()) continue;
			if (threatened(positions[i])) continue;
			positions[i] = paths[i].back();
			paths[i].pop_back();
			hap = 1;
			if (paths[i].empty()) done(i);
		}

		if (!hap) {
			cerr << "WARNING!" << ' ' << cs << endl;
			rep(i,0,valid) {
				if (!paths[i].empty()) done(i);
			}
			break;
		}
		// assert(hap);
	}

	cout << valid << endl;
	trav(id, out) {
		cout << id+1 << ' ' << L[id]+1 << endl;
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit | cin.eofbit | cin.badbit);
	cin.tie(0);
	int T;
	cin >> T;
	rep(i,0,T) {
		cout << "Case #" << i+1 << ": ";
		solve(i+1);
	}
}
