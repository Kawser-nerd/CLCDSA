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
#include <ctime>

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

#define K 11000
int n,k;
LL e[K],f[K];

int get(LL x)
{
	int i = lower_bound(e,e+k,x) - e;
	if (i == k || e[i] != x) return -1;
	return i;
}

int getf(LL x)
{
	int i = get(x);
	assert(i!=-1);
	return i;
}

bool check(LL x, vector<LL> a)
{
	if (a[getf(0)] <= 0) return false;
	a[getf(0)]--;
	if (a[getf(x)] <= 0) return false;
	a[getf(x)]--;
	if (x>=0)
		REP(it,k)
		{
			if (a[it] == 0) continue;
			LL val = a[it];
			if (x == 0)
			{
				if (val %2 != 0) return false;
				val/=2;
			}
			a[it] -= val;
			int pp = get(e[it] + x);
			if (pp == -1) return false;
			LL t = (a[pp] -= val);
			if (t < 0) return false;
			if (a[it] != 0) return false;
		}
	else
		REPD(it,k)
		{
			if (a[it] == 0) continue;
			LL val = a[it];
			if (x == 0)
			{
				if (val %2 != 0) return false;
				val/=2;
			}
			a[it] -= val;
			int pp = get(e[it] + x);
			if (pp == -1) return false;
			LL t = (a[pp] -= val);
			if (t < 0) return false;
			if (a[it] != 0) return false;
		}
	return true;
}

int main(int argc, char **argv)
{
	string FN = "D-large";
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
		auto start = clock();
		////////////////////////////////////////////////////////////
		scanf("%d",&k);
		LL sum = 0;
		REP(i,k) scanf("%lld",e+i);
		REP(i,k) scanf("%lld",f+i);
		REP(i,k) sum += f[i];
		if (sum&(sum-1)) fprintf(stderr,"not power!\n");
		n = 0;
		while ((1LL << n) != sum) ++n;

		vector<LL> a(f+0,f+k);

		vector<LL> cand;
		REP(i,k)
			if (check(e[i],a))
				cand.push_back(e[i]);
		UNIQUE(cand);

		vector<LL> res;
		REP(step,n)
		{
			LL x;
			bool found = false;
			REP(i,SZ(cand)) if (check(cand[i],a))
			{
				x=cand[i];
				found=true;
				break;
			}
			assert(found);
			//fprintf(stderr,"%d... sel %lld\n",step,x);
			vector<LL> b(k,0LL);
			res.pb(x);
			if (x>=0)
				REP(it,k)
				{
					if (a[it] == 0) continue;
					LL val = a[it];
					if (x == 0)
					{
						assert(val %2 == 0);
						val/=2;
					}
					a[it] -= val;
					a[getf(e[it] + x)] -= val;
					b[it] = val;
					assert(a[it] == 0);
				}
			else
				REPD(it,k)
				{
					if (a[it] == 0) continue;
					LL val = a[it];
					if (x == 0)
					{
						assert(val %2 == 0);
						val/=2;
					}
					a[it] -= val;
					a[getf(e[it] + x)] -= val;
					b[it] = val;
					assert(a[it] == 0);
				}
			b.swap(a);
		}
		REP(it,k)
			if (a[it] != 0) assert(e[it] == 0 && a[it] == 1);
		SORT(res);
		REP(i,SZ(res)) printf(" %lld"+(i==0),res[i]);
		printf("\n");

		fprintf(stderr, "= %.3lf cand %d n %d len %d\n", (clock()-start)*(double)1000.0/CLOCKS_PER_SEC, SZ(cand), n, k);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}