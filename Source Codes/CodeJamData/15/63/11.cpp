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

#define N 555000
#define DENOM 1000000

int n,f;
char a[N];

template<class T> inline T gcd(T a,T b) {
	if (a<0)a=-a; if (b<0)b=-b; if (a<b)swap(a,b);
	while (b) { T t = b; b=a%b; a=t; } return a;
}

struct Fr {
	LL a,b;
	Fr(LL a=0,LL b=1) { LL d=gcd(a,b);a/=d;b/=d;if (b<0) a=-a,b=-b;this->a=a;this->b=b; }
	string toString() { ostringstream sout;sout<<a<<"/"<<b;return sout.str(); }
};
Fr operator+(Fr p,Fr q) { return Fr(p.a*q.b+q.a*p.b,p.b*q.b); }
Fr operator-(Fr p,Fr q) { return Fr(p.a*q.b-q.a*p.b,p.b*q.b); }
Fr operator*(Fr p,Fr q) { return Fr(p.a*q.a,p.b*q.b); }
Fr operator/(Fr p,Fr q) { return Fr(p.a*q.b,p.b*q.a); }
bool operator<(Fr p,Fr q) { return p.a*q.b<q.a*p.b; }
bool operator==(Fr p,Fr q) { return p.a*q.b==q.a*p.b; }
bool operator!=(Fr p,Fr q) { return p.a*q.b!=q.a*p.b; }
bool operator<=(Fr p,Fr q) { return p.a*q.b<=q.a*p.b; }

int main(int argc, char **argv)
{
	string FN = "C-small-attempt0";
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
		double ff;
		scanf("%d%lf",&n,&ff);
		f = (int)(ff*DENOM+0.1);
		scanf("%s",a);
		REP(i,n) a[i]-='0';

		Fr best = Fr(2);
		int res = -1;
		REP(i,n)
		{
			int s=0;
			FOR(len,1,n)
			{
				if (i+len > n) break;
				s += a[i+len-1];
				Fr q = Fr(f,DENOM)-Fr(s,len);
				if (q.a < 0) q.a = -q.a;
				if (q < best)
				{
					res = i;
					best = q;
				}
			}
		}
		printf("%d\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}