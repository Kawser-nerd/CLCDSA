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
char color[N];
VI g[N];

struct StringHash {
	typedef string T;
	static string combine(int v, const vector<T>& a)
	{
		string s;
		s.push_back(color[v]);
		s.push_back('(');
		REP(i,SZ(a))
			s+=a[i];
		s.push_back(')');
		return s;
	}
};

typedef StringHash Hash;

map<PII, Hash::T> memhash;

Hash::T gethash(int v,int par)
{
	if (memhash.count(PII(v,par))) return memhash[PII(v,par)];
	vector<Hash::T> q;
	REP(i,SZ(g[v])) if (g[v][i] != par)
	{
		q.push_back(gethash(g[v][i],v));
	}
	SORT(q);
	return memhash[PII(v,par)]=Hash::combine(v,q);
}

bool simm(int v, int par)
{
	vector<pair<Hash::T,int>> q;
	REP(i,SZ(g[v])) if (g[v][i] != par)
	{
		q.push_back(make_pair(gethash(g[v][i],v),g[v][i]));
	}
	SORT(q);
	int center = -1;
	REP(i,SZ(q))
	{
		if (i+1 == SZ(q) || q[i].first != q[i+1].first)
		{
			if (center != -1) return false;
			center = q[i].second;
		}
		else
			++i;
	}
	return center==-1 || simm(center,v);
}

bool solve() {
	memhash.clear();
	REP(i,n) if (simm(i,-1)) return true;
	REP(v,n) REP(j,SZ(g[v]))
	{
		int vv = g[v][j];
		if (gethash(v,vv) == gethash(vv,v)) return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	string FN = "C-small-attempt1";
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
		scanf("%d", &n);
		REP(i,n) {
			char c;
			do c = getc(stdin); while (!isalpha(c));
			color[i]=c;
			g[i].clear();
		}
		REP(i,n-1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			--x,--y;
			g[x].pb(y);
			g[y].pb(x);
		}
		////////////////////////////////////////////////////////////
		if (test < test_beg || test >= test_end) continue;
		////////////////////////////////////////////////////////////
		fprintf(stderr,"=== %s : %d\n", FN.c_str(), test+1);
		printf("Case #%d: ",test+1);
		////////////////////////////////////////////////////////////
		printf(solve()?"SYMMETRIC\n":"NOT SYMMETRIC\n");
	}
	fprintf(stderr,"=== %s DONE\n%.6lf\n", FN.c_str(), clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}