#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <iostream>
#include <queue>
#include <set>
#include <map>

#define ABS(x) ((x)<0?-(x):(x))
#define SQR(x) ((x)*(x))
#define PB push_back
#define MP make_pair
#define SS stringstream
#define LL long long
#define LD long double
#define SZ(x) int(x.size())
#define ALL(x) x.begin(),x.end()
#define FOR(a,b) for(int a=0;a<b;a++)
#define DFOR(a,b) for(int a=b-1;a>=0;a--)
#define CLR(a,b) memset(a,b,sizeof(a))


using namespace std;

#define maxn 505
#define mod 1000000009

int n, k;
vector<int> e[maxn], E[maxn];
int dp[maxn];
int dp1[maxn][maxn];

int calc1(int v, int s);

int calc(int v) {
	int &res = dp[v];
	if (res == -1) {
		res = 1;
		int q = SZ(E[v]);
		for (int i = 0; i < q; i++) res = ((LL)res * (k-i)) % mod;
		for (int i = 0; i < q; i++) res = ((LL)res * calc1(E[v][i], q-1)) % mod;
	}
	return res;
}

int calc1(int v, int s) {
	int &res = dp1[v][s];
	if (res == -1) {
		res = 1;
		int q = SZ(E[v]);
		for (int i = 0; i < q; i++) {
			int t = k - i - s - 1;
			if (t < 0) res= 0; else res = ((LL)res * t) % mod;
		}
		for (int i = 0; i < q; i++) {
			res = ((LL)res * calc1(E[v][i], q)) % mod;
		}
	}
	return res;
}

void dfs(int v, int p) {
	for (int i = 0; i < SZ(e[v]); i++)
		if (e[v][i] != p) {
			E[v].PB(e[v][i]);
			dfs(e[v][i], v);
		}
}

void solvecase() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		e[i].clear();
		E[i].clear();
	}
	for (int i = 0; i < n-1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		e[u].PB(v);
		e[v].PB(u);
	}
	dfs(0, -1);
	CLR(dp, -1);
	CLR(dp1, -1);
	printf("%d", calc(0));
}

void solve() {
	int n;
	scanf("%d\n", &n);
	FOR(i, n) {
		printf("Case #%d: ", i+1);
		solvecase();
		printf("\n");
	}
}

int main() {
	freopen("y", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	solve();
	return 0;
}