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

#define N 111000
#define D 4
int reslen,resx;
int d;
int limit=100;

void check(int st, int len)
{
	if (len > reslen || len==reslen && st < resx)
	{
		reslen=len;
		resx=st;
	}
}

inline bool fff(int v[], int x) {
	return find((v),(v)+d,x)!=(v)+d;
}
int done[N];

void solveblock(int n, int k, int a[][D], int before[], int ind[])
{
	if (k==0)
	{
		REP(i,n+1)
			check(ind[i],before[i]);
		return;
	}
	REP(i,n) done[i]=0;
	REP(st,n) {
	REP(ind1,d) if (!(done[st]&(1<<ind1)))
	{
		int val1 = a[st][ind1];
		int sum = before[st]+1;
		int p = st+1;
		while ((p-st < limit || k == 1) && p < n)
		{
			int qq = find(a[p],a[p]+d,val1)-a[p];
			if (qq >= d) break;
			done[p] |= 1<<qq;
			sum += before[p]+1;
			++p;
		}
		check(ind[st],sum+before[p]);
		if (p<n && k >= 2)
		{
			REP(ind2,d)
			{
				int val2 = a[p][ind2];
				int sum2 = sum + before[p]+1;

				int pp = p+1;
				while (pp-st < limit && pp < n && (fff(a[pp], val1) || fff(a[pp], val2)))
				{
					sum2 += before[pp]+1;
					pp++;
				}
				check(ind[st],sum2+before[pp]);
				if (pp < n && k >= 3)
				{
					REP(ind3,d)
					{
						int val3 = a[pp][ind3];
						int sum3 = sum2 + before[pp]+1;

						int ppp = pp+1;
						while (ppp-st < limit && ppp < n && (fff(a[ppp], val1) || fff(a[ppp], val2) || fff(a[ppp], val3)))
						{
							sum3 += before[ppp]+1;
							ppp++;
						}
						check(ind[st],sum3+before[ppp]);
					}
				}
			}
		}
	}
	}
}

int n,k;
int a[N][D];
map<int,int> seen;

bool hh[N];
int aa[N][4],nn,before[N],ind[N];

void fltr(int val1 = -1, int val2 = -1)
{
	nn = 0;
	FILL(ind,-1);
	CLEAR(before);
	REP(i,n)
	{
		if (ind[nn] == -1)
			ind[nn] = i;
		if (fff(a[i],val1) || fff(a[i],val2))
		{
			++before[nn];
			continue;
		}
		REP(j,d) aa[nn][j] = a[i][j];
		++nn;
	}
	if (nn == 0) check(0,n);
}

int main(int argc, char **argv)
{
	auto start = clock();

	string FN = "d-large3";
	if (argc>1) FN = string(argv[1]);
	int shift = 0;
	if (argc>2) sscanf(argv[2],"%d",&shift);
	freopen((FN+".in").c_str(),"r",stdin);
	freopen((FN+".out").c_str(),"w",stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test<=tests; test++)
	{
		//fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+shift);
		printf("Case #%d: ",test+shift);
		////////////////////////////////////////////////////////////
		scanf("%d%d%d",&n,&d,&k);

		seen.clear();
		REP(i,n) REP(j,d)
		{
			scanf("%d",&a[i][j]);
			++seen[a[i][j]];
		}
		//if (n>1000) { printf("---\n"); continue; }

		reslen=0;
		//fprintf(stderr,"READ\n");
		CLEAR(before);
		REP(i,n) ind[i]=i;
		solveblock(n,k,a,before,ind);
		VI big;
		for (const auto& it : seen) {
			if (it.second*k < limit) continue;
			big.pb(it.first);
		}
		for (int val1 : big) {
			fltr(val1);
			solveblock(nn,k-1,aa,before,ind);
		}
		fprintf(stderr,"? %d\n",big.size());
		REP(i1,SZ(big))
		{
			fprintf(stderr,"*");
			REP(i2,i1)
			{
				fltr(big[i1],big[i2]);
				solveblock(nn,k-2,aa,before,ind);
			}
		}
		printf("%d %d\n",resx,resx+reslen-1);
	}
	fprintf(stderr,"\n=== %s DONE --- %.12lf\n", FN.c_str(), (clock()-start)*1.0/CLOCKS_PER_SEC);
	return 0;
}