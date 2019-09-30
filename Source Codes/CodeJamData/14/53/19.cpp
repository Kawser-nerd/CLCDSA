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

#define N 16
int n,mmm;
int a[N];
bool enter[N];

bool d[N][1<<N];
template<class T> inline int bitcnt(T n){ int res=0;
	for (; n!=0; n&=n-1) res++; return res; }

int brute(int m)
{
	CLEAR(d);
	REP(x,1<<m) d[0][x]=true;
	REP(i,n) REP(x,1<<m) if (d[i][x])
	{
		if (a[i] == -1)
			REP(j,m)
			{
				if (enter[i] && (x&(1<<j))==0)
					d[i+1][x^(1<<j)] = true;
				if (!enter[i] && (x&(1<<j))!=0)
					d[i+1][x^(1<<j)] = true;
			}
		else
		{
			int j = a[i];
			if (enter[i] && (x&(1<<j))==0)
				d[i+1][x^(1<<j)] = true;
			if (!enter[i] && (x&(1<<j))!=0)
				d[i+1][x^(1<<j)] = true;
		}
	}
	int res = INF;
	REP(x,1<<m)
		if (d[n][x])
			res = min(res,bitcnt(x));
	return res;
}


int main(int argc, char **argv)
{
	string FN = "C-small-attempt0";
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
		scanf("%d",&n);
		vector<int> all;
		REP(i,n)
		{
			char c;
			do c = getc(stdin);
			while (!isalpha(c));
			enter[i] = c=='E';
			scanf("%d",&a[i]);
			--a[i];
			if (a[i]>=0)
				all.pb(a[i]);
		}
		UNIQUE(all);
		mmm=SZ(all);
		REP(i,n) if (a[i]!=-1) a[i] = find(ALL(all),a[i])-all.begin();
		int res = brute(n);
		if (res == -1 || res == INF)
		{
			printf("CRIME TIME\n");
		}
		else
		{
			printf("%d\n",res);
		}
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}