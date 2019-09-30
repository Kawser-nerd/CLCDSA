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

#define N 1024000

char a[N];
int m;
LL n,tmm;

bool dd[32][32];
bool dd2[32][32];

int main(int argc, char **argv)
{
	string FN = "A-small-attempt1";
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
		cin >> m >> tmm >> n;
		CLEAR(dd);
		CLEAR(dd2);
		REP(i,m)
		{
			LL t,s,e;
			cin >> s >> e >> t;
			--s;--e;
			LL len = (e-s+n)%n;
			//s = ((s-t)%n+n)%n;
			REP(i,len+1)
				dd[(s+i)%n][i+t]=true;
			REP(i,len)
				dd2[(s+i)%n][i+t]=true;
		}
		LL res = 0;
		REP(x,n) REP(stt,tmm+1) if (!dd[x][stt])
		{
			LL t = stt;
			LL p = x;
			while (t+1 <= tmm && !dd[(n+p-1)%n][t+1] && !dd2[(n+p-1)%n][t])
			{
				++t;
				p = (p-1+n)%n;
			}
			res = max(res,t-stt);
		}
		cout << res << endl;
	}
	fprintf(stderr,"=== %s DONE\n", FN.c_str());
	return 0;
}