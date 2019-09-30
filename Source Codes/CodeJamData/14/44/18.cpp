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

#define N 1024
char buf[N];
int n,m;
string a[N];
vector<string> b[N];
#define MOD 1000000007
LL best,res;

void go(int step)
{
	if (step == m)
	{
		int cur = 0;
		REP(i,n)
		{
			vector<string> q;
			REP(j,SZ(b[i]))
				REP(t,SZ(b[i][j])+1)
					q.push_back(b[i][j].substr(0,t));
			UNIQUE(q);
			cur += SZ(q);
		}
		if (cur > best)
		{
			best=cur;
			res=0;
		}
		if (cur == best)
			++res;
		return;
	}
	REP(i,n)
	{
		b[i].push_back(a[step]);
		go(step+1);
		b[i].pop_back();
	}
}

int g[N][N];

int pref(const string& a, const string& b)
{
	int k = min(SZ(a),SZ(b));
	REP(i,k)
		if (a[i]!=b[i])
			return i;
	return k;
}

pair<LL,LL> solve(int n)
{
	LL best = n;
	LL res = 1;
	vector<int> top(n,m);
	vector<int> choice(m,0);
	REP(i,m)
	{
		/*if (SZ(top) < n)
		{
			best += SZ(a[i]);
			res = (res*(n-SZ(top)))%MOD;
			top.pb(a[i]);
			continue;
		}*/
		int mn = INF, last = -1;
		REP(j,SZ(top))
		{
			int t = g[top[j]][i];
			if (t < mn)
				mn=t,choice[i]=0,last=j;
			if (t==mn)
				++choice[i];
		}
		if (mn == SZ(a[top[last]]) && top[last] != m)
			choice[top[last]] = n;
		best += SZ(a[i])-mn;
		//res = (res*choice)%MOD;
		top[last]=i;
	}
	REP(i,m)
		res = (res*choice[i])%MOD;
	return make_pair(best,res);
}

LL cnk[N][N];

struct Node {
	int cnt,end;
	map<char,Node*> a;
	Node() : cnt(0), end(0) {}
	int getans(int n) {
		int res = 0;
		for (map<char,Node*>::iterator it = a.begin(); it!=a.end(); ++it)
		{
			int t = min(n,it->second->cnt);
			res += t;
			res += it->second->getans(t);
		}
		return res;
	}
	LL getcnt(int n) {
		LL res = 1;
		//REP(i,end) res = (res*n)%MOD;
		VI q;
		if (end) q.pb(1);
		for (map<char,Node*>::iterator it = a.begin(); it!=a.end(); ++it)
		{
			int t = min(n,it->second->cnt);
			res = (res * it->second->getcnt(t)) %MOD;
			q.pb(t);
		}
		SORT(q);
		int sgn = 1;
		LL term = 0;
		for (int k = n; k >= q.back(); k--)
		{
			LL cur = 1;
			REP(i,SZ(q))
				cur = (cur*cnk[k][q[i]])%MOD;
			term = (term+MOD+sgn*(cur*cnk[n][k])%MOD)%MOD;
			sgn = -sgn;
		}
		res = (res*term)%MOD;
		return res;
	}
};

int main(int argc, char **argv)
{
	CLEAR(cnk);
	cnk[0][0]=1;
	REP(i,N) if (i)
	{
		cnk[i][0]=1;
		REP(j,N) if (j)
			cnk[i][j] = (cnk[i-1][j-1]+cnk[i-1][j])%MOD;
	}

	string FN = "D-large";
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
		scanf("%d%d",&m,&n);
		REP(i,m)
		{
			scanf("%s",buf);
			a[i]=string(buf);
		}
		best=-1,res=0;
		//go(0);
		sort(a,a+m);
		/*CLEAR(g);
		REP(i,m) REP(j,m)
			g[i][j] = pref(a[i],a[j]);
		pair<LL,LL> q = solve(n);
		int sgn = 1;
		for (int k = n-1; k > 0; --k)
		{
			sgn=-sgn;
			pair<LL,LL> p = solve(k);
			p.first += n-k;
			if (q.first != p.first) continue;
			q.second = (q.second+MOD+sgn*(cnk[n][k]*p.second)%MOD)%MOD;
		}
		*/
		Node root;
		REP(i,m)
		{
			Node*v = &root;
			++v->cnt;
			REP(j,SZ(a[i]))
			{
				if (!v->a[a[i][j]])
				{
					v->a[a[i][j]] = new Node();
				}
				v = v->a[a[i][j]];
				++v->cnt;
			}
			++v->end;
		}
		best = root.getans(n)+n;
		res = root.getcnt(n);
		/*int sgn = 1;
		for (int k = n-1; k > 0; --k)
		{
			sgn=-sgn;
			int cur = root.getans(k)+n;
			if (cur == best)
				res = (res+MOD+sgn*(cnk[n][k]*root.getcnt(k))%MOD)%MOD;
		}*/
		printf("%lld %lld\n", best, (LL)(res%MOD));
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}