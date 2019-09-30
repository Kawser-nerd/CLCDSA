#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> g[100001];
int col[100001], fd[100001], n, m, q, a, b, c, qa[100001], qb[100001], qc[100001],sz[100001];

void dfs(int cp, int dis, int c) {
	if (!col[cp]) col[cp] = c;
	if (fd[cp] >= dis || dis == 0) return;
	fd[cp] = dis;
	REP(i,sz[cp])
		dfs(g[cp][i], dis - 1, c);
};

signed main() {
	scnaf("%d %d", &n, &m);
	REP(i, m) {
		scanf("%d %d", &a, &b);
		sz[--a]++;
		sz[--b]++;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	scanf("%d", &q);
	REP(i, q) {
		scanf("%d %d %d", &qa[q-i-1], &qb[q - i - 1], &qc[q - i - 1]);
	}
	
	REP(i, q) {
		dfs(--qa[i],qb[i],qc[i]);
	}

	REP(i, n) {
		printf("%d\n", col[i]);
	}
	return 0;
}