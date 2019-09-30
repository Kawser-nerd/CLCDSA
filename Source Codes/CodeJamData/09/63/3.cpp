#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <string>
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

#define FOR(i,a,b) for (int _b=(b), i=(a); i <= _b; i++)
#define REP(i,n) for (int i=0,_n=(n); i < _n; i++)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)

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
#define PB push_back
#define M_PI       3.14159265358979323846
#define eps 1.0e-11

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;


#define NAME "C-small-attempt0"

int n,m;
char a[16][16];
vector<LL> states;

void genstate(int step, int mx, int mask)
{
	if (step==m)
	{
		states.push_back(mask);
		return ;
	}
	for (int i = mx; i < 26; i++)
		genstate(step+1, i, (mask*26)+i);
}

int d[16][1024000],prev[16],curval,row;
#define MOD 10007

void rec(int col, int mx, int mask)
{
	if (col==m)
	{
		d[row+1][mask] = (d[row+1][mask]+curval)%MOD;
		return;
	}
	mx=max(mx,prev[col]);
	if (a[row][col] != -1)
	{
		if (mx>a[row][col])
			return;
		rec(col+1,a[row][col],(mask*26)+a[row][col]);
		return;
	}
	for (int i = mx; i < 26; i++)
		rec(col+1, i, (mask*26)+i);
}

void unpack(int mask, int * arr)
{
	REP(i,m)
	{
		arr[m-1-i] = mask%26;
		mask/=26;
	}
}

int main()
{
	freopen(NAME ".in","r",stdin);
	freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d",&tests);
	REP(tst,tests)
	{
		fprintf(stderr,"Test #%d\n",tst+1);
		scanf("%d%d",&n,&m);
		states.clear();
		REP(i,n) REP(j,m)
		{
			do a[i][j]=getc(stdin);
			while (a[i][j]<=' ');
			if (a[i][j]=='.')
				a[i][j]=-1;
			else
				a[i][j]-='a';
		}
		genstate(0,0,0);
		//fprintf(stderr,"%d\n",SZ(states));

		CLEAR(d);
		d[0][0]=1;
		REP(i,n)
		{
			REP(is,SZ(states))
			{
				int state = states[is];
				if (d[i][state]==0)
					continue;
				curval=d[i][state];
				row=i;
				unpack(state,prev);
				rec(0,0,0);
			}
		}
		int res=0;
		REP(is,SZ(states))
			res = (res+d[n][states[is]])%MOD;
		printf("Case #%d: %d\n",tst+1,res);
	}
	return 0;
}