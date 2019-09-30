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
#define N 1005
using namespace std;

int n;
LLD T, m, st[N], ed[N], tm[N];
int v[15][15], u[15][15], ent[15][15], out[15][15];

void solve(int tc){
	scanf("%d", &n);
	scanf("%lld%lld", &T, &m);

	CLR(v, 0);
	CLR(u, 0);
	CLR(ent, 0);
	CLR(out, 0);
	FOR(i,0,n){
		scanf("%lld%lld%lld", &st[i], &ed[i], &tm[i]);
		st[i]--, ed[i]--;

		int x = st[i];
		int t = tm[i];
		ent[x][t] = 1 + i;
		while (x != ed[i]){
			v[x][t] = 1 + i;		
			u[x][t] = 1 + i;
			x = (x + 1) % m;
			++t;
		}
		v[x][t] = 1;
		out[x][t] = 1 + i;
	}

	int ret = 0;
	FOE(i,0,T) FOR(j,0,m){
		int x = j, y;
		int t = i;
		int cnt = 0;
		if (v[x][t]) continue;
		if (out[x][t]) continue;
		while (t < T){
			y = (x + m - 1) % m;
			if (v[x][t]) break;
			if (v[y][t+1]) break;
			if (u[y][t]) break;
			++cnt;
			if (!ent[y][t+1] && !out[y][t+1]) ret = max(ret, cnt);
			x = y;
			++t;
		}
	}

	printf("Case #%d: %d\n", tc, ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
