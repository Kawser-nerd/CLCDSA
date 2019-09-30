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

#define N 1024000
int n,p,q,r,s;
LL a[N];
LL ssum[N];

LL solve(int beg)
{
	int left = beg;
	int right = n-1;
	while (left < right)
	{
		int mid = (left+right)/2;
		if (ssum[n]-ssum[mid+1] > ssum[mid+1]-ssum[beg])
			left = mid+1;
		else
			right = mid;
	}
	LL res = ssum[n];
	FOR(dlt,-20,+20)
	{
		int x = left+dlt;
		if (x>=beg && x<n)
			res = min(res,max(ssum[n]-ssum[x+1], ssum[x+1]-ssum[beg]));
	}
	return res;
}

int main(int argc, char **argv)
{
	string FN = "A-large";
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
		scanf("%d%d%d%d%d",&n,&p,&q,&r,&s);
		REP(i,n) a[i] = ((i * (LL)p + q) % r + s);
		ssum[0]=0;
		REP(i,n) ssum[i+1] = ssum[i]+a[i];
		LL res = ssum[n];
		REP(i,n)
		{
			res = min(res,max(ssum[i],solve(i)));
		}
		printf("%.12lf\n",1.0-(res*1.0/ssum[n]));
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}