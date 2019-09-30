#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:32000000")
#include <algorithm>
#include <numeric>
#include <string>
#include <list>
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
#include <unordered_map>

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

#define N 1024000
#define KK 200
int n;
char a[N];

int bfin[KK][N];
int bst[KK][N];

#define BIG 1000000

int main(int argc, char **argv)
{
	string FN = "A-large";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%s",a);
		n=strlen(a);
		REP(i,n) a[i] -= '0';

		/////
		//int mult = 100;
		//REP(d,mult) REP(i,n) a[n*d+i] = a[i];
		//n*=mult;
		/////

		int res = BIG;
		REP(cost,KK)
		{
			REP(i,n+1) bfin[cost][i]=i;
			REP(i,n+1) bst[cost][i]=i;
			REP(i,n)
			{
				if (a[i] > cost) continue;
				int st = bst[cost-a[i]][i];
				int fin = bfin[cost-a[i]][i+1];
				if (st == 0 && fin == n)
					res = min(res,cost);
				bfin[cost][st] = max(bfin[cost][st],fin);
				bst[cost][fin] = min(bst[cost][fin],st);
			}
			REP(i,n+1) if (i)
				bfin[cost][i] = max(bfin[cost][i],bfin[cost][i-1]);
			REPD(i,n)
				bst[cost][i] = min(bst[cost][i],bst[cost][i+1]);
		}
		if (res == BIG) fprintf(stderr,"BAD!\n");
		printf("%d\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}