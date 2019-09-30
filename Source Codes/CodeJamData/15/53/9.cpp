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
#define eps 1.0e-9
const double pi = acos(-1.0);

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;

#define N 32
int n,y,p[N],s[N];

int sgn(int x) { if (x==0)return 0; return x>0?1:-1; }


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
		scanf("%d%d",&y,&n);
		REP(i,n) scanf("%d",p+i);
		REP(i,n) scanf("%d",s+i);

		s[n]=0;
		p[n]=0;

		set<pair<double,PII>> q;
		map<PII,double> d;
		d[PII(0,n)] = 0;
		q.insert(make_pair(0.0, PII(0,n)));
		double res = 1.0e30;
		while (!q.empty())
		{
			int mask = q.begin()->second.first;
			int last = q.begin()->second.second;
			double tm = d[PII(mask,last)];
			if (mask == (1<<n)-1) res = min(res,tm);
			q.erase(q.begin());
			double pos = p[last] + sgn(p[last])*s[last]*tm;
			REP(next,n) if ((mask&(1<<next)) == 0)
			{
				double curp = p[next] + sgn(p[next])*s[next]*tm;
				if (curp >= 0 && curp <= pos+eps || curp <= 0 && curp >= pos-eps) continue; //ate
				double delta = fabs(curp-pos);
				double extra = delta/(y-s[next]);
				double newtm = tm+extra;

				double newp = p[next] + sgn(p[next])*s[next]*newtm;
				int newmask = mask;
				REP(ii,n)
				{
					double ppp = p[ii] + sgn(p[ii])*s[ii]*newtm;
					if (ppp >= 0 && ppp <= newp+eps || ppp <= 0 && ppp >= newp-eps)
						newmask |= 1<<ii;
				}
				assert(newmask&(1<<next));
				auto st = PII(newmask,next);
				if (!d.count(st) || d[st] > newtm)
				{
					q.erase(make_pair(d[st],st));
					d[st] = newtm;
					q.insert(make_pair(d[st],st));
				}
			}
		}
		printf("%.12lf\n",res);
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}