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
#include <cstring>

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
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 1024
#define M 102
int d[M][202][N];
int n,p,q;
int h[N],g[N];
int res;

void add(int mon, int x, int extra, int gg)
{
	d[mon][x][extra] = max(d[mon][x][extra],gg);
	res = max(res,gg);
}

int main(int argc, char **argv)
{
	string FN = "B-large";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d%d%d",&p,&q,&n);
		REP(i,n) scanf("%d%d",h+i,g+i);
		h[n]=0;
		//REP(i,N) REP(j,n) REP(x,202) d[i][j][x].clear();
		//d[0][0][h[0]].push_back(PII(0,0));
		FILL(d,-1);
		d[0][h[0]][0] = 0;
		res=0;
		REP(mon,n) REPD(xxx,h[mon]+1) REP(extra,N) if (d[mon][xxx][extra] != -1)
		{
			int curg = d[mon][xxx][extra];
			if (extra > 0)
			{
				if (xxx > p)
					add(mon,xxx-p,extra-1,curg);
				else
					add(mon+1,h[mon+1],extra-1,curg+g[mon]);
			}
			if (xxx > q)
				add(mon,xxx-q,extra+1,curg);
			else
				add(mon+1,h[mon+1],extra+1,curg);
			int mon111 = mon;
			int xxx111 = xxx;
			if (xxx111 > p)
				xxx111 -= p;
			else
			{
				curg += g[mon111];
				mon111++;
				xxx111 = h[mon111];
			}
			if (mon111 < n)
				if (xxx111 > q)
					xxx111 -= q;
				else
				{
					mon111++;
					xxx111 = h[mon111];
				}
			add(mon111,xxx111,extra,curg);
		}
		printf("%d\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}