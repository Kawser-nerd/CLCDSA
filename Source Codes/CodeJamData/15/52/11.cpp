#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:32000000")
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
#define eps 1.0e-11
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 1024
int n,k,s[N],d[N],s0;
int mnd[N],mxd[N];

bool check(int ddd) {
	LL smn=0,smx=0;
	REP(i,k)
	{
		int l = -mnd[i];
		int r = ddd-mxd[i];
		if (l>r) return false;
		smn += l;
		smx += r;
	}
	int cnt = 0;
	for (LL x = smn; x <= smx; x++)
	{
		if ((x%k+k)%k == (s0%k+k)%k)
			return true;
		if (++cnt > 3*k) return false;
	}
	return false;
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
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d%d",&n,&k);
		REP(i,n) if (i>=k-1) scanf("%d",s+i);
		s0 = s[k-1];
		CLEAR(d);
		REP(i,n) if (i>=k)
			d[i] = s[i]-s[i-1]+d[i-k];
		CLEAR(mnd);
		CLEAR(mxd);
		REP(i,n) {
			mnd[i%k] = min(mnd[i%k],d[i]);
			mxd[i%k] = max(mxd[i%k],d[i]);
		}
		int left = 0, right = 1000000000;
		while (left < right) {
			int mid = (left+right)/2;
			if (check(mid))
				right = mid;
			else
				left = mid+1;
		}
		if (left != right) fprintf(stderr,"BAD!\n");
		printf("%d\n",left);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}