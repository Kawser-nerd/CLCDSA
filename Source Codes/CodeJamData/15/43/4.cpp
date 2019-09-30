#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

template<class T> void chmax(T& a, T b) { a = max(a, b); }

namespace MF {
#define MAXN 500000
#define MAXM 500000
#define wint long long
#define cint long long
#define cdouble double
int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
wint capa0[MAXM], capa[MAXM], ex[MAXN];
cint cost[MAXM];
cdouble pot[MAXN];
bool vis[MAXN];
int itr[MAXN], lev[MAXN], que[MAXN], *qb, *qe;
void init(int _n) {
	n = _n; m = 0; memset(ptr, ~0, n * 4); memset(ex, 0, n * sizeof(wint));
}
void ae(int u, int v, wint c, cint w) {
	next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa0[m] = capa[m] = w; cost[m] = +c; ++m;
	next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa0[m] = capa[m] = 0; cost[m] = -c; ++m;
} // MAXM should be at least 2 * (num of edges) !!
wint augment(int u, int t, wint flo) {
	if (u == t) return flo;
	wint f;
	for (int &i = itr[u]; ~i; i = next[i]) if (capa[i] > 0 && lev[u] < lev[zu[i]]) {
		if ((f = augment(zu[i], t, min(flo, capa[i]))) > 0) {
			capa[i] -= f; capa[i ^ 1] += f; return f;
		}
	}
	return 0;
}
wint augment(int u, wint flo) {
	wint f;
	if (ex[u] < 0) {
		f = min(flo, -ex[u]); ex[u] += f; return f;
	}
	for (int &i = itr[u]; ~i; i = next[i]) if (capa[i] > 0 && cost[i] + pot[u] - pot[zu[i]] < 0) {
		if ((f = augment(zu[i], min(flo, capa[i]))) > 0) {
			capa[i] -= f; capa[i ^ 1] += f; return f;
		}
	}
	return 0;
}
wint dinic(int s, int t, wint flo) {
	int i, u, v;
	wint tof = 0, f;
	for (; tof < flo;) {
		qb = qe = que; memset(lev, ~0, n * 4); memcpy(itr, ptr, n * 4);
		for (lev[*qe++ = s] = 0; qb != qe;) {
			for (i = ptr[u = *qb++]; ~i; i = next[i]) if (capa[i] > 0 && !~lev[v = zu[i]]) {
				lev[*qe++ = v] = lev[u] + 1;
			}
		}
		if (!~lev[t]) break;
		for (; (f = augment(s, t, flo - tof)) > 0;) tof += f;
	}
	return tof;
}
void dfs(int u) {
	if (vis[u]) return; vis[u] = 1;
	for (int i = ptr[u]; ~i; i = next[i]) if (capa[i] > 0 && cost[i] + pot[u] - pot[zu[i]] < 0) {
		dfs(zu[i]);
	}
}
cint solve() {
	int i, u;
	wint f;
	cdouble eps = 0;
	for (i = 0; i < m; ++i) if (capa[i] > 0) chmax(eps, (cdouble)-cost[i]);
	for (; eps * n >= 1;) {
		eps /= 4;
		for (i = 0; i < m; ++i) if (capa[i] > 0 && cost[i] + pot[zu[i ^ 1]] - pot[zu[i]] < 0) {
			ex[zu[i ^ 1]] -= capa[i]; ex[zu[i]] += capa[i]; capa[i ^ 1] += capa[i]; capa[i] = 0;
		}
		for (;;) {
			memset(vis, 0, n); memcpy(itr, ptr, n * 4);
			for (u = 0; u < n; ++u) if (ex[u] > 0) dfs(u);
			for (u = 0; u < n; ++u) if (vis[u]) pot[u] -= eps;
			for (u = 0; u < n; ++u) for (; ex[u] > 0 && (f = augment(u, ex[u])) > 0;) ex[u] -= f;
			for (u = 0; u < n; ++u) if (ex[u] > 0) break;
			if (u == n) break;
		}
	}
	cint toc = 0;
	for (i = 0; i < m; ++i) if (capa0[i] > capa[i]) toc += (capa0[i] - capa[i]) * cost[i];
	return toc;
}
}


int T;
int N;
char in[20000];
vector<string> words[230];

vector<int> token[230];
map<string, int> M; int id;

int to_id(string &s)
{
	if (M.count(s)) return M[s];
	M.insert(make_pair(s, id++));
	return id - 1;
}

int main()
{
	scanf("%d ", &T);
	for (int t = 0; t++ < T;) {
		scanf("%d ", &N);

		for (int i = 0; i < N; ++i) {
			words[i].clear();

			gets(in);

			string pool;
			for (int j = 0;; ++j) {
				if (in[j] >= 'a' && in[j] <= 'z') {
					pool.push_back(in[j]);
				} else {
					words[i].push_back(pool);
					pool.clear();
					if (in[j] != ' ') break;
				}
			}
		}

		id = 0;
		M.clear();
		for (int i = 0; i < N; ++i) {
			token[i].clear();
			for (int j = 0; j < words[i].size(); ++j) {
				token[i].push_back(to_id(words[i][j]));
			}
		}

		int src = N + id * 2;
		int dest = src + 1;
		MF::init(500000);
		const i64 AUX = 1000000;
		for (int i = 0; i < N; ++i) {
			if (i != 0) MF::ae(src, i, 0, AUX);
			if (i != 1) MF::ae(i, dest, 0, AUX);

			for (int j : token[i]) {
				MF::ae(i, j * 2 + N, 0, AUX);
				MF::ae(j * 2 + 1 + N, i, 0, AUX);
			}
		}
		for (int i = 0; i < id; ++i) {
			MF::ae(i * 2 + N, i * 2 + 1 + N, 0, 1);
		}

		i64 ret = MF::dinic(src, dest, 1LL << 62LL);
		ret %= AUX;

		printf("Case #%d: %lld\n", t, ret);
	}

	return 0;
}
