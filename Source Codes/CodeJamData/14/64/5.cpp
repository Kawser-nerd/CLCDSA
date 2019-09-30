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

#define N 128

int n,sel;
bool g[N][N];
bool fix[N];
int ind[N],id[N];
bool gg[N][N];

int gkkk;

bool stupid()
{
	int a[N];
	REP(i,n) a[i]=i;
	do {
		int x = a[0];
		REP(i,n) if (i)
		{
			if (g[a[i]][x])
				x = a[i];
		}
		if (x == sel)
		{
			REP(i,n)
				printf(" %d"+(i==0),a[i]);
			printf("\n");
			return true;
		}
	}
	while (next_permutation(a,a+n));
	return false;
}

bool check(int start)
{
	int k=0;
	bool seen = false;
	REP(i,n) if (!fix[i] || i==start)
	{
		ind[i] = k;
		id[k] = i;
		++k;
		if (i == sel) seen=true;
	}
	if (!seen) return false;
	REP(i,k) REP(j,k)
		gg[i][j] = g[id[i]][id[j]];
	++gkkk;
	REP(t,k) if (t!=ind[start]) REP(i,k) REP(j,k)
		gg[i][j] |= gg[i][t] && gg[t][j];
	if (!gg[ind[start]][ind[sel]]) return false;
	REP(i,k)
	{
		if (!g[id[i]][start])
		{
			if (start != sel)
			{
				if (!(gg[i][ind[sel]]) || !gg[ind[start]][i])
					return false;
			}
			else
				return false;
		}
	}
	return true;
}

void solve()
{
	CLEAR(fix);
	int cur = -1;
	REP(p,n)
	{
		bool ok = false;
		REP(i,n) if (!fix[i])
		{
			int ncur = (cur == -1 || g[cur][i]) ? i : cur;
			fix[i]=true;
			if (check(ncur))
			{
				ok = true;
				printf(" %d"+(p==0),i);
				fix[i]=true;
				cur=ncur;
				break;
			}
			fix[i]=false;
		}
		if (!ok)
		{
			if (p == 0)
			{
				printf("IMPOSSIBLE\n");
				return;
			}
			fprintf(stderr,"BAD\n");
			printf("\n");
			return;
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	string FN = "D-large";
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
		if (true) {
			scanf("%d%d", &n, &sel);
			REP(i,n) REP(j,n)
			{
				char c;
				do c = getc(stdin); while (c!='Y'&&c!='N'&&c!='-');
				g[i][j] = c=='N'||c=='-';
			}
		}
		else {
			n=100;
			REP(i,n)g[i][i]=true;
			REP(i,n)REP(j,i)
			{
				g[j][i] = !(g[i][j]=rand()%2);
			}
			sel=rand()%n;
		}
		////////////////////////////////////////////////////////////
		if (test < test_beg || test >= test_end) continue;
		////////////////////////////////////////////////////////////
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+1);
		printf("Case #%d: ",test+1);
		////////////////////////////////////////////////////////////
		gkkk=0;
		solve();
		fprintf(stderr,"%d\n",gkkk);
	}
	fprintf(stderr,"=== %s DONE\n%.6lf\n", FN.c_str(), clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}