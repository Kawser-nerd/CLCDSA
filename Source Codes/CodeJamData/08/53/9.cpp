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

string s[100];

VVI e;
VI ee;

int n1;
int n2;

VPII a, b;

VI u1;
VI u2;
VI r;

int go2 (int x);

int go1 (int x)
{
	//cout << "go1 "<< x << endl; 
	
	if (u1[x])
		return 0;
	
	u1[x] = 1;

	REP (i, e[x].size ())
	{
		int y = e[x][i];
		
		if (go2 (y))
		{
			ee[y] = x;
					
			return 1;
		}
	}
	return 0;
}

int go2 (int x)
{
	//cout << "go2 " << x << endl;
	if (u2[x])
		return 0;
	u2[x] = 1;
	if (ee[x]==-1)
		return 1;
	
	return go1 (ee[x]);	
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	
	int tt;
	cin >> tt;
	REP (t, tt)
	{
		cout << "Case #"<< t+1 << ": ";
		a.clear ();
		b.clear ();
		int n, m;
		cin >> n >> m;
		
		REP (i, n)
			cin >> s[i];
		
		int res = 0;
		
		REP (i, n)
			REP (j, m)
				if (s[i][j]=='.')
				{
					if (j%2)
						a.pb (PII (i, j));
					else
						b.pb (PII (i, j));
					res++;
				}
		
		n1 = a.size ();
		n2 = b.size ();
		//cout << n1 << " " << n2 << " " << res << endl;
		
		e = VVI (n1);
		ee = VI (n2, -1);
		
		REP (i, n1)
			REP (j, n2)
				if (abs (a[i].X-b[j].X)<=1 && abs(a[i].Y-b[j].Y)<=1)
				{
					e[i].pb (j);
					//cout << i << " " << j << endl;
				}
		
		r = VI (n1);
		
		while (1)
		{
			u1 = VI (n1);
			u2 = VI (n2);
			
			bool changed = false;
			
			REP (i, n1)
				if (!r[i])
				{
					r[i] = go1(i);
					
					if (r[i])
					{
						changed = true;
						res--;
					}
				}
			if (!changed)
				break;
		}
		
		cout<< res << endl;
	}
	
	return 0;
}
