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
int n,h,w;
int xx0[N],yy0[N],xx1[N],yy1[N];
int d[N];
bool mark[N];

int dist(int i, int j)
{
	int dist = 0;
	if (xx1[i] < xx0[j])
		dist = max(dist, xx0[j]-xx1[i]-1);
	if (xx1[j] < xx0[i])
		dist = max(dist, xx0[i]-xx1[j]-1);
	if (yy1[i] < yy0[j])
		dist = max(dist, yy0[j]-yy1[i]-1);
	if (yy1[j] < yy0[i])
		dist = max(dist, yy0[i]-yy1[j]-1);
	return dist;
}

int main(int argc, char **argv)
{
	string FN = "C-large";
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
		scanf("%d%d%d",&w,&h,&n);
		REP(i,n)
		{
			scanf("%d%d%d%d",xx0+i,yy0+i,xx1+i,yy1+i);
		}
		CLEAR(mark);
		int res = w;
		REP(i,n)
			d[i] = xx0[i];
		REP(step,n)
		{
			int best = -1;
			REP(i,n) if (!mark[i])
				if (best == -1 || d[i] < d[best])
					best = i;
			if (best == -1)  fprintf(stderr,"hmmm...\n");
			mark[best]=true;
			res = min(res,d[best]+(w-xx1[best]-1));
			REP(i,n)
			{
				int t = d[best]+dist(best,i);
				if (t < d[i])
				{
					if (mark[i]) fprintf(stderr,"hm...\n");
					d[i]=t;
				}
			}
		}
		printf("%d\n", res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}