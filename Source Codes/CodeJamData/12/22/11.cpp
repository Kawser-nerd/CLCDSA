#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)
#define FOReach(it,V) for(__typeof((V).begin()) it=(V).begin();it!=(V).end();++it)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int stmp;
#define scanf stmp=scanf


const int MAX = 110;
const int INF = 1000000001;

#define ok(x,n) (0 <= x && x < n)

int dis[MAX][MAX];
int c[MAX][MAX];
int f[MAX][MAX];

int n, m, h;


void solve() {
	REP(i,n)
		REP(j,m)
			dis[i][j] = -1;
	priority_queue< pair<int,PII>, vector< pair<int,PII> >, greater< pair<int,PII> > > Q;
	VPII S;
	dis[0][0] = 0;
	S.PB(MP(0, 0));
	REP(foo,SIZE(S))
	{
		PII v = S[foo];
		FOR(i,v.ST-1,v.ST+1)
			FOR(j,v.ND-1,v.ND+1)
				if(abs(v.ST-i) + abs(v.ND-j) == 1 && ok(i, n) && ok(j, m) && dis[i][j] == -1) {
					if(f[v.ST][v.ND] + 50 <= c[i][j] && f[i][j] + 50 <= c[v.ST][v.ND] && f[i][j] + 50 <= c[i][j] && h + 50 <= c[i][j]) {
						S.PB(MP(i, j));
						dis[i][j] = 0;
					}
				}
	}
	
	FOReach(it,S)
	{
		Q.push(MP(0, MP(it->ST, it->ND)));
		dis[it->ST][it->ND] = -1;
	}
	while(!Q.empty())
	{
		int d = Q.top().ST;
		PII v = Q.top().ND;
		Q.pop();
		if(dis[v.ST][v.ND] != -1)
			continue;
		dis[v.ST][v.ND] = d;
		FOR(i,v.ST-1,v.ST+1)
			FOR(j,v.ND-1,v.ND+1)
				if(abs(v.ST-i) + abs(v.ND-j) == 1 && ok(i, n) && ok(j, m)) {
					if(f[v.ST][v.ND] + 50 <= c[i][j] && f[i][j] + 50 <= c[v.ST][v.ND] && f[i][j] + 50 <= c[i][j]) {
						int w = 0;
						if(h-d + 50 > c[i][j])
							w = h-d+50 - c[i][j];
						if(h-d-w >= f[v.ST][v.ND] + 20)
							w += 10;
						else
							w += 100;
						Q.push(MP(d+w, MP(i, j)));
					}
				}
	}
}

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		scanf("%d %d %d", &h, &n, &m);
		REP(i,n)
			REP(j,m)
				scanf("%d", &c[i][j]);
		REP(i,n)
			REP(j,m)
				scanf("%d", &f[i][j]);
		solve();
		printf("%d.%d\n", dis[n-1][m-1]/10, dis[n-1][m-1]%10);
	}
	return 0;
}

