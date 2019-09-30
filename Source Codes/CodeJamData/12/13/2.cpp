#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cassert>

using namespace std;

#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define REPD(i,n) for (int i=(n)-1; i >= 0; i--)
#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset(x,0,sizeof x);
#define CLEARA(x) memset(&x,0,sizeof x);
#define FILL(x,v) memset(x,v,sizeof x);
#define FILLA(x,v) memset(&x,v,sizeof x);

#define VAR(a,b) __typeof(b) a=(b)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define FN "C-large"

#define N 64
int n;
bool g[N][N];
int side[N];
int var[N],vark,gid[N];
int p[N],s[N];

template<class T> inline T gcd(T a,T b) {
	if(a<0)a=-a; if(b<0)b=-b; if(a<b)swap(a,b);
	while (b) {T t = b; b=a%b; a=t;} return a; }

struct Fr{LL a,b;
	Fr::Fr(LL a=0,LL b=1){LL d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b;}
	string toString(){ostringstream sout;sout<<a<<"/"<<b;return sout.str();}
	double asd() { return a/(double)b;}
};
Fr operator+(Fr p,Fr q){return Fr(p.a*q.b+q.a*p.b,p.b*q.b);}
Fr operator-(Fr p,Fr q){return Fr(p.a*q.b-q.a*p.b,p.b*q.b);}
Fr operator*(Fr p,Fr q){return Fr(p.a*q.a,p.b*q.b);}
Fr operator/(Fr p,Fr q){return Fr(p.a*q.b,p.b*q.a);}
bool operator<(Fr p,Fr q){return p.a*q.b<q.a*p.b;}
bool operator==(Fr p,Fr q){return p.a*q.b==q.a*p.b;}
bool operator!=(Fr p,Fr q){return p.a*q.b!=q.a*p.b;}
bool operator<=(Fr p,Fr q){return p.a*q.b<=q.a*p.b;}	

void collectUnbound()
{
	REP(i,n)
	{
		bool ok = true;
		REP(j,n) if (g[i][j]) ok = false;
		if (!ok) continue;
		var[i] = vark++;
	}
}

void dfs(int v, int mark)
{
	if (gid[v] != -1) return;
	gid[v] = mark;
	REP(i,n) if (g[v][i]) dfs(i,mark);
}

void regroup()
{
	FILL(gid,-1);
	REP(i,n) if (gid[i]==-1)
		dfs(i,i);
}

void flipWithVar(int v)
{
	REP(i,n)
		if (var[i]==v)
			side[i]^=1;
}

void replaceVar(int from, int to)
{
	REP(i,n)
		if (var[i] == from)
			var[i] = to;
}

void replaceG(int from, int to)
{
	REP(i,n)
		if (gid[i] == from)
			gid[i] = to;
}

void merge(int x, int y, Fr tmm)
{
	if (gid[x] == gid[y])
	{
		if (side[x] == side[y]) throw tmm;
		return;
	}
	if (side[x] == side[y])
	{
		//swap!
		if (var[x] == var[y]) throw tmm;
		flipWithVar(var[y]);
		if(side[x]==side[y]) fprintf(stderr,"BAD!\n");
	}
	replaceVar(var[y],var[x]);
	replaceG(gid[y],gid[x]);
	g[x][y]=g[y][x]=true;
}

bool collide(int i, int j, Fr t)
{
	Fr st_i = p[i]+s[i]*t;
	Fr st_j = p[j]+s[j]*t;
	if (st_j.asd() < st_i.asd()) swap(st_i,st_j);
	Fr fn_i = st_i + 5;
	return st_j.asd() < fn_i.asd();
}

int main()
{
	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"* %d\n",test);
		scanf("%d",&n);
		vark=1;
		REP(i,n)
		{
			char c;
			do c = getc(stdin);
			while (c!='L'&&c!='R');
			side[i] = c=='R'?1:0;
			var[i]=0;
			gid[i]=i;
			scanf("%d%d",s+i,p+i);
		}
		vector<Fr> events;
		events.pb(0);
		REP(i,n) REP(j,n) if (i!=j && s[i]!=s[j])
		{
			Fr t1(p[i]-p[j]-5, s[j]-s[i]);
			Fr t2(p[i]-p[j]+5, s[j]-s[i]);
			if (0 <= t1) events.pb(t1);
			if (0 <= t2) events.pb(t2);
		}
		CLEAR(g);
		Fr eps(1,1000LL*1000*1000);
		UNIQUE(events);
		printf("Case #%d: ",test);
		try {
			REP(i,n) REP(j,i) if (collide(i,j,Fr(0)))
			{
				merge(i,j,0);
			}
		} catch (Fr f) {
			fprintf(stderr,"BAD DATA\n");
		}
		try {
			REP(step,SZ(events))
			{
				Fr tmm = events[step];
				if (0 < tmm)
				{
					REP(i,n) REP(j,i) if (collide(i,j,tmm-eps) && !collide(i,j,tmm))
					{
						g[i][j]=g[j][i]=false;
					}
				}
				regroup();
				collectUnbound();
				REP(i,n) REP(j,i) if (collide(i,j,tmm+eps) && !collide(i,j,tmm))
				{
					merge(i,j,tmm);
				}
			}

			printf("Possible\n");
		} catch (Fr f) {
			printf("%.12lf\n",f.a/(double)f.b);
		}

	}
	return 0;
}