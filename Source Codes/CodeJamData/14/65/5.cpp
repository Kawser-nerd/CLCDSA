#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:16000000")
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
#include <ctime>
#include <unordered_map>
#include <unordered_set>

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

#define MX 123000
LL d[MX];

int main(int argc, char **argv)
{
	string FN = "E-small-attempt0";
	string FNO = FN;
	int test_beg = 0;
	int test_end = 100000;
	if (argc>1) sscanf(argv[1],"%d",&test_beg);
	if (argc>2) sscanf(argv[2],"%d",&test_end);
	if (argc>3) FN = string(argv[3]);
	if (argc>4) FNO = string(argv[4]);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FNO+".out").c_str(),"w",stdout);




	int tests;
	cin >> tests;
	for (int test = 0; test<tests; test++)
	{
		////////////////////////////////////////////////////////////
		LL n;
		int a,b;
		scanf("%lld%d%d", &n,&a,&b);
		fprintf(stderr,"%lld %d %d\n",n,a,b);
		////////////////////////////////////////////////////////////
		if (test < test_beg || test >= test_end) continue;
		////////////////////////////////////////////////////////////
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+1);
		printf("Case #%d: ",test+1);
		////////////////////////////////////////////////////////////
		REP(i,MX)
		{
			d[i] = 1;
			if (i >= a) d[i] = max(d[i],d[i-a]+1);
			if (i >= b) d[i] = max(d[i],d[i-a]+d[i-b]);
			if (d[i]>=n)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	fprintf(stderr,"=== %s DONE\n%.6lf\n", FN.c_str(), clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}