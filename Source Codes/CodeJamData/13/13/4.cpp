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

#define FN "C-small-2-attempt1"
int r,n,m,k;
vector<string> a;
vector<int> w;
vector<map<LL,double>> b;
map<string,int> mapping;
vector<int> dmm;

int dm(LL x)
{
	int divmask = 0;
	if (x%3 == 0)
		divmask |= 1;
	if (x%5 == 0)
		divmask |= 2;
	if (x%7 == 0)
		divmask |= 4;
	return divmask;
}
	
void generate(string s, int weight)
{
	if (SZ(a)%1000 == 0) fprintf(stderr,"*");
	a.pb(s);
	b.pb(map<LL,double>());
	w.pb(weight);
	map<LL,double>& r = b.back();
	dmm.pb(0);
	REP(mask,1<<n)
	{
		LL x = 1;
		REP(i,n) if (mask&(1<<i)) x *= s[i]-'0';
		r[x]+=1.0/(1<<m);
	}
	REP(i,n)
		dmm.back() |= dm(s[i]-'0');
}

int fact[13];

int coef(string s)
{
	int res = fact[n];
	REP(i,m+1)
	{
		int cnt = 0;
		REP(j,n) cnt += s[j]==('0'+i);
		res /= fact[cnt];
	}
	return res;
}

void rec(string s)
{
	if (SZ(s) == n)
	{
		sort(ALL(s));
		if (!mapping.count(s))
		{
			generate(s,1);
			mapping[s] = SZ(a)-1;
		}
		else
			w[mapping[s]]++;
		return;
	}
	FOR(x,2,m)
	{
		rec(s + string(1,'0'+x));
	}
}

void rec2(string s, int mn = 2)
{
	if (SZ(s) == n)
	{
		generate(s,coef(s));
		return;
	}
	FOR(x,mn,m)
	{
		rec2(s + string(1,'0'+x), x);
	}
}

int main()
{
	fact[0]=1;
	FOR(i,1,12)
		fact[i]=fact[i-1]*i;

	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	scanf("%d%d%d%d",&r,&n,&m,&k);
	rec2("");

	/*REP(i,SZ(a))
		if (w[i] != coef(a[i]))
			fprintf(stderr,"bad %s %d %d\n", a[i].data(), w[i], coef(a[i]));*/
	fprintf(stderr,"generation done %d\n", SZ(a));
	//REP(i,SZ(a)) printf("= %s %d\n",a[i].data(),w[i]);

	printf("Case #1:\n");
	REP(step,r)
	{
		if (step%100 == 0) fprintf(stderr,"*");
		LL obs[25];
		int divmask = 0;
		REP(i,k)
		{
			scanf("%lld",obs+i);
			//if (obs[i]>1<<30) fprintf(stderr,"!");
			divmask |= dm(obs[i]);
		}
		double best = -1.0;
		string ans = "";
		REP(i,SZ(a)) if ((divmask&dmm[i]) == divmask)
		{
			double cur = w[i];
			REP(j,k)
			{
				auto it = b[i].find(obs[j]);
				if (it != b[i].end())
					cur *= it->second;
				else
				{
					cur = 0.0;
					break;
				}
			}
			if (cur > best)
			{
				best = cur;
				ans = a[i];
			}
		}
		printf("%s\n",ans.data());
	}
	return 0;
}