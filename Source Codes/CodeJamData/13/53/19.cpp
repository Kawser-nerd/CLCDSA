#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
#define N 22
using namespace std;

struct node{
	int x, s, b;
	bool operator < (node const &T) const{return s > T.s;}
};

priority_queue<node> q;
int n, m, P;
int x, y, lo, hi;
int l[N], qd[N], qn[N], qa[N], qb[N];
int v[N], u[N], a[N];

void solve(int tc){
	printf("Case #%d: ", tc);
	scanf("%d%d%d", &n, &m, &P);
	CLR(l, 0);
	FOE(i,1,m){
		scanf("%d%d%d%d", &x, &y, &lo, &hi);
		qd[i] = y, qa[i] = lo, qb[i] = hi;
		qn[i] = l[x], l[x] = i;
	}
	
	int U = 0;
	FOR(i,0,(1<<m)){
		CLR(v, -1);
		CLR(u, 0);
		while (!q.empty()) q.pop();
		q.push((node){1, 0, 0});
		while (!q.empty()){
			node t = q.top();
			q.pop();
			if (t.s > v[2] && v[2] != -1) break;
			if (v[t.x] == -1){
				v[t.x] = t.s;
				u[t.x] = t.b;
			}
			else if (v[t.x] == t.s){
				u[t.x] |= t.b;
				continue;
			}
			else if (t.s > v[t.x]) continue;
			EXP(j,l[t.x]) q.push((node){qd[j], t.s + ((i & (1<<(j-1))) ? qa[j] : qb[j]), u[t.x] | (1<<(j-1))});
		}
		U |= u[2];
	}

	FOR(i,0,P) scanf("%d", &a[i]);
	FOR(i,0,P) if (((1<<(a[i]-1)) & U) == 0){
		printf("%d\n", a[i]);
		return;
	}
	puts("Looks Good To Me");
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
