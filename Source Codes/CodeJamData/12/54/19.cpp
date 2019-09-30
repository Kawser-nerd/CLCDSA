#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
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

#define FN "D-small-attempt0"

#define N 1024
int n,k;
map<char,char> subs;
char s[N];
bool is[256][256];
int in[256],out[256];

int main()
{
	subs['o'] = '0';
	subs['i'] = '1';
	subs['e'] = '3';
	subs['a'] = '4';
	subs['s'] = '5';
	subs['t'] = '7';
	subs['b'] = '8';
	subs['g'] = '9';

	freopen(FN ".in","r",stdin);
	freopen(FN ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	for (int test = 1; test<=tests; test++)
	{
		scanf("%d%s",&k,s);
		n=strlen(s);
		CLEAR(is);
		REP(i,n-1)
		{
			REP(sub1,2) REP(sub2,2)
			{
				char c1 = s[i];
				char c2 = s[i+1];
				if (sub1) if (subs.count(c1)) c1 = subs[c1]; else continue;
				if (sub2) if (subs.count(c2)) c2 = subs[c2]; else continue;
				is[c1][c2] = true;
			}
		}
		CLEAR(in);
		CLEAR(out);
		REP(i,256) REP(j,256) if (is[i][j]) ++in[j],++out[i];
		int res = 1;
		REP(i,256) res += max(in[i],out[i]);
		REP(i,256) if (in[i]!=out[i])
		{
			--res;
			break;
		}

		printf("Case #%d: %d\n",test,res);
	}
	return 0;
}