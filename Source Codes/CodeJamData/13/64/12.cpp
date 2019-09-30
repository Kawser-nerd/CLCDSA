#include <cstdio>
#include <cstdlib>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#define INF (1<<30)
#define EPS 1e-8
#define LLD long long int
#define PB push_back
#define VI vector<int>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
using namespace std;

int n, d, m, rx, ry, c1, c2;
int a[100005][4];
vector<int> Occur[100005];
vector<int> Occur2[10000081];
int MOD = 10000079;

inline int contains(int i, int k){
	FOR(j,0,d) if (a[i][j] == k) return 1;
	return 0;
}



int maxGo(int pos, int value){
	int ret = pos;
	int x, y;
	for (int i=pos, j=n-1, k; j>=i;){
		k = (i + j) >> 1;				
		x = lower_bound(Occur[value].begin(), Occur[value].end(), pos) - Occur[value].begin();
		y = upper_bound(Occur[value].begin(), Occur[value].end(), k) - Occur[value].begin();
		if (y - x == k - pos + 1) ret = k, i = k + 1;
		else j = k - 1;
	}
	return ret;
}


int hash(int v1, int v2){
	if (v1 > v2) swap(v1, v2);
	return (v1 * 10000019LL + v2) % MOD;
}


int maxGo(int pos, int value1, int value2){
	int ret = pos;
	int x, y;
	for (int i=pos, j=n-1, k; j>=i;){
		k = (i + j) >> 1;				
		int cnt = 0;
		cnt -= lower_bound(Occur[value1].begin(), Occur[value1].end(), pos) - Occur[value1].begin();
		cnt += upper_bound(Occur[value1].begin(), Occur[value1].end(), k) - Occur[value1].begin();
		cnt -= lower_bound(Occur[value2].begin(), Occur[value2].end(), pos) - Occur[value2].begin();
		cnt += upper_bound(Occur[value2].begin(), Occur[value2].end(), k) - Occur[value2].begin();
		int v = hash(value1, value2);
		cnt += lower_bound(Occur2[v].begin(), Occur2[v].end(), pos) - Occur2[v].begin();
		cnt -= upper_bound(Occur2[v].begin(), Occur2[v].end(), k) - Occur2[v].begin();
		if (cnt == k - pos + 1) ret = k, i = k + 1;
		else j = k - 1;
	}
	return ret;
}


void dfs(int x, int y, int c1, int c2){
	if (n - 1 - x <= ry - rx) return;
	if (c2 != -1){
		FOR(itr,0,10){
			int r = rand() % (n - y);
			int t = min(n-1, y + r);
			if (!contains(t, c1) && !contains(t, c2)){
				if (t - 1 - x <= ry - rx) return;
			}
		}
	}
	if (!contains(y, c1) && !contains(y, c2)){
		if (c2 != -1) return;
		FOR(j,0,d) dfs(x, y, c1, a[y][j]);		
		return;
	}
	if (y - x > ry - rx) rx = x, ry = y;
	if (y + 1 < n) dfs(x, y+1, c1, c2);
}

void solve2(int tc){
	FOR(i,0,n){
		FOR(j,0,d) scanf("%d", &a[i][j]);
		random_shuffle(a[i], a[i] + d);
	}
	rx = -1;
	ry = -2;
	FOR(i,0,n) FOR(j,0,d){
		dfs(i, i, a[i][j], -1);
	}
	
	printf("Case #%d: %d %d\n", tc, rx, ry);
}

void solve(int tc){
	scanf("%d%d%d", &n, &d, &m);
	if (n <= 1000){
		solve2(tc);
		return;
	}

	
	FOE(i,0,100000) Occur[i].clear();
	FOR(i,0,MOD) Occur2[i].clear();
	FOR(i,0,n){
		int b[4], t;
		FOR(j,0,d) scanf("%d", &a[i][j]), b[j] = a[i][j];
		sort(b, b + d);
		t = unique(b, b + d) - b;
		FOR(j,0,t) Occur[b[j]].PB(i);		
		FOR(j,0,t) FOR(k,0,j) Occur2[hash(b[j], b[k])].PB(i);
	}

	rx = -1, ry = -2;
	FOR(i,0,n) FOR(j,0,d){
		if (n - 1 - i <= ry - rx) break;		
		c1 = a[i][j];
		int P = maxGo(i, c1);
		FOR(k,0,d){
			int p = P;
			c2 = a[p+1][k];
			p = maxGo(i, c1, c2);
			if (p - i + 1 > ry - rx + 1){
				rx = i, ry = p;
			}
		}		
	}
	
	printf("Case #%d: %d %d\n", tc, rx, ry);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
