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

#define N 11000

int n;
int a[N];
bool own[N];

template<class T> inline int bitcnt(T n){ int res=0;
	for (; n!=0; n&=n-1) res++; return res; }

LL fact[N],res;

void go(int mask,int bit)
{
	int dis = 0;
	int sz = 1<<(n-1-bit);
	int mod = sz*2;
	VI bl;
	REP(i,1<<n) if (a[i]%mod!=i%mod)
	{
		int x = i%sz;
		if (bl.empty() || bl.back()!=x) bl.push_back(x);
		if (SZ(bl) > 2) return;
	}
	if (dis > sz*2) return;
	int dd = 0;
	mod/=2;
	REP(i,1<<n) if (a[i]%mod!=i%mod) return;
	if (bit == -1)
	{
		bool ok = true;
		REP(i,1<<n) if (a[i] != i) {
			ok=false;
			break;
		}
		if (ok)
			res += fact[bitcnt(mask)];
		return;
	}
	if (mask & (1<<bit))
	{
		if (!bl.empty() && false){

		//for (int i = 0; i < (1<<n); i+=sz)
			//for (int j = i+sz; j < (1<<n); j+=sz)
		REP(ii,SZ(bl)) REP(jj,ii)
			{
				int i = bl[ii] * sz;
				int j = bl[jj] * sz;
				REP(t,sz)
					swap(a[i+t],a[j+t]);
				go(mask,bit-1);
				REP(t,sz)
					swap(a[i+t],a[j+t]);
			}
		}
		else {
			for (int i = 0; i < (1<<n); i+=sz)
				for (int j = i+sz; j < (1<<n); j+=sz)
				{
					REP(t,sz)
						swap(a[i+t],a[j+t]);
					go(mask,bit-1);
					REP(t,sz)
						swap(a[i+t],a[j+t]);
				}
		}
	}
	else
		go(mask,bit-1);
}

void gen(int nn)
{
	n=nn;
	REP(i,1<<n) a[i]=i;
	//random_shuffle(a,a+(1<<n));
	REP(i,n)
	{
		if (rand()%5 < 0) continue;
		int x = rand()%(2<<i), y;
		do y = rand()%(2<<i);
		while (x==y);
		//fprintf(stderr,"%d %d %d\n",x,y,1<<i);
		x<<=n-i-1;
		y<<=n-i-1;
		REP(t,1<<(n-i-1))
		{
			if (x+t>=(1<<n)) fprintf(stderr,"BAD\n");
			if (y+t>=(1<<n)) fprintf(stderr,"BAD\n");
			swap(a[x+t],a[y+t]);
		}
	}
	fprintf(stderr,"genned\n");
}

bool cond(const VI&a,VI& r)
{
	r.clear();
	r.reserve(SZ(a)/2);
	for (int i = 0; i < SZ(a); i+=2)
	{
		if (a[i]%2 == 0 && a[i+1]==a[i]+1)
			r.push_back(a[i]/2);
		else
			return false;
	}
	return true;
}

void sss(VI a,int cnt)
{
	if (SZ(a) == 1)
	{
		res += fact[cnt];
		return;
	}
	VI bad;
	for (int i = 0; i < SZ(a); i+=2)
		if (!(a[i+1] == a[i]+1 && a[i]%2 == 0))
		{
			bad.pb(i);
			bad.pb(i+1);
		}
	if (SZ(bad) > 4) return;
	if (bad.empty())
	{
		VI aa;
		if (!cond(a,aa)) { fprintf(stderr,"HMMM\n"); }
		sss(aa,cnt);
	}
	REP(i,SZ(bad)) REP(j,i)
	{
		swap(a[bad[i]],a[bad[j]]);
		VI aa;
		if (cond(a,aa))
		{
			sss(aa, cnt+1);
		}
		swap(a[bad[i]],a[bad[j]]);
	}
}

int main(int argc, char **argv)
{
	string FN = "B-large";
	string FNO = FN;
	int test_beg = 0;
	int test_end = 100000;
	if (argc>1) sscanf(argv[1],"%d",&test_beg);
	if (argc>2) sscanf(argv[2],"%d",&test_end);
	if (argc>3) FN = string(argv[3]);
	if (argc>4) FNO = string(argv[4]);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FNO+".out").c_str(),"w",stdout);

	fact[0]=1;
	FOR(i,1,100) fact[i]=fact[i-1]*i;

	int tests;
	cin >> tests;
	for (int test = 0; test<tests; test++)
	{
		////////////////////////////////////////////////////////////
		scanf("%d", &n); REP(i,1<<n) scanf("%d",a+i),--a[i];
		//gen(12);
		////////////////////////////////////////////////////////////
		if (test < test_beg || test >= test_end) continue;
		////////////////////////////////////////////////////////////
		fprintf(stderr,"=== %s : %d -- %d\n", FN.c_str(), test+1, 1<<n);
		printf("Case #%d: ",test+1);
		////////////////////////////////////////////////////////////
		res = 0;
		sss(VI(a,a+(1<<n)),0);
		//REP(mask,1<<n) go(mask,n-1);
		printf("%lld\n",res);
	}
	fprintf(stderr,"=== %s DONE\n%.6lf\n", FN.c_str(), clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}