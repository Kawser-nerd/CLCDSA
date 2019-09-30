#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long i64;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)) % MOD)
#define DBG(...) (fprintf(stderr, "[line %d]: ", __LINE__), fprintf(stderr, __VA_ARGS__))
namespace MF {
	#define MAXN 500
	#define MAXM 100000
	#define wint int
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
	wint capa[MAXM], tof;
	int lev[MAXN], see[MAXN], que[MAXN], *qb, *qe;
	void init(int _n) {
		n = _n; m = 0; memset(ptr, ~0, n * 4);
	}
	void ae(int u, int v, wint w0, wint w1 = 0) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w0; ++m;
		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = w1; ++m;
	}
	wint augment(int src, int ink, wint flo) {
		if (src == ink) return flo;
		wint f;
		for (int &i = see[src]; ~i; i = next[i]) if (capa[i] > wEPS && lev[src] < lev[zu[i]]) {
			if ((f = augment(zu[i], ink, min(flo, capa[i]))) > wEPS) {
				capa[i] -= f; capa[i ^ 1] += f; return f;
			}
		}
		return 0;
	}
	bool solve(int src, int ink, wint flo = wINF) {
		wint f;
		int i, u, v;
		for (tof = 0; tof + wEPS < flo; ) {
			qb = qe = que;
			memset(lev, ~0, n * 4);
			for (lev[*qe++ = src] = 0, see[src] = ptr[src]; qb != qe; ) {
				for (i = ptr[u = *qb++]; ~i; i = next[i]) if (capa[i] > wEPS && !~lev[v = zu[i]]) {
					lev[*qe++ = v] = lev[u] + 1; see[v] = ptr[v];
					if (v == ink) goto au;
				}
			}
			return 0;
		au:	for (; (f = augment(src, ink, flo - tof)) > wEPS; tof += f);
		}
		return 1;
	}
}

int N, M, K;
vector<int> graph[101];

int dist[101][101];
int U[10101], V[10101];

int main()
{
	int n_testcase;
	scanf("%d", &n_testcase);
	
	for (int testcase_id = 0; testcase_id++ < n_testcase; ) {
		// input and solve the problem
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 0; i < N; ++i) graph[i].clear();
		for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) {
			dist[i][j] = (i == j) ? 0 : 10000;
		}
		for (int i = 0; i < M; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
			
			dist[a][b] = dist[b][a] = 1;
			U[i * 2] = a; V[i * 2] = b;
			U[i * 2 + 1] = b; V[i * 2 + 1] = a;
		}
		
		for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) for(int k = 0; k < N; ++k) 
			dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
		
		MF::init(2 * N);
		for (int i = 0; i < M * 2; ++i) {
			if (dist[0][U[i]] + dist[V[i]][N - 1] + 1 == dist[0][N - 1]) {
				MF::ae(U[i] * 2 + 1, V[i] * 2, 123456);
			}
		}
		for(int i = 0; i < N; ++i) MF::ae(i * 2, i * 2 + 1, 1);
		
		int ret = 1 + dist[0][N - 1];
		--K;
		MF::solve(0 * 2 + 1, (N - 1) * 2);
		int sol = MF::tof;
		if (sol <= K) ++ret;
		printf("Case #%d: %d\n", testcase_id, ret);
		// print answer here
	}
	return 0;
}

