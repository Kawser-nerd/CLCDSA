#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

int mod=10007;

int mdiv (int x, int y)
{
	REP (i, mod)
	{
		if (i*y % mod == x)
			return i;
	}
	return 0;
}

int f[80000001];

int cnk (int n, int k)
{
	if (k>n || k<0)
		return 0;
	int res = f[n];
	res = mdiv (res, f[k]);
	res = mdiv (res, f[n-k]);
	return res;
}

int ways (int x1, int y1, int x2, int y2)
{
	int x = x2-x1;
	int y = y2-y1;
	
	if (x<0 || y<0)
		return 0;
	
	int c1 = 0;
	while (x>=0 && y>=0)
	{
		if (x>y*2)
			break;
		if (x==y*2)
		{
			return cnk (c1+y, y);
		}
		x-=1;
		y-=2;
		c1++;
	}
	return 0;
}

int main()
{
	f[0] = 1;
	FOR (i, 1, 80000001) //don't forget
	{
		f[i] = f[i-1]*i%mod;
	}
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	
	int tt;
	cin >> tt;
	REP (t, tt)
	{
		cout << "Case #"<<t+1 << ": ";  
		int d[16][16];
		VPII a;
		
		int n, m;
		cin >> n >> m;
		a.pb (PII (1, 1));
		a.pb (PII (n, m));
		
		int c;
		cin >> c;
		REP (i, c)
		{
			int x, y;
			cin >> x >> y;
			a.pb ( PII (x, y));
		}
		
		SORT (a);
		
		n = a.size ();
		
		REP (i, n)
			REP (j, n)
			{
				d[i][j] = ways (a[i].X , a[i].Y, a[j].X, a[j].Y);
				//cout << a[i].X << " " << a[i].Y << "    " <<a[j].X << " " << a[j].Y << "    " << d[i][j] << endl; 
			}
		
		int res [1<<12];
		
		int r = 0;
		
		REP (m, 1<< (n-2))
		{
			VI b;
			
			b.pb (0);
			REP (i, n-2)
				if (m & (1<<i))
					b.pb (i+1);
			
			b.pb (n-1);
			
			res[m] = 1;
			
			REP (i, b.size ()-1)
			{
				res[m]*=d[b[i]][b[i+1]];
				res[m]%=mod;
			}
			
			if (b.size ()%2 == 0)
				r+=res[m];
			else
				r-=res[m];
			r+=mod;
			r%=mod;
		}		
		
		cout << r << endl;
	}
	
	return 0;
}
