
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

bool e[7500][7500];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	
	VPII d;
	d.pb (PII (-1, 0));
	d.pb (PII (0, -1));
	d.pb (PII (1, 0));
	d.pb (PII (0, 1));
	
	int tt;
	cin >> tt;
	
	
	REP (t, tt)
	{
		cout << "Case #" << t+1 << ": ";
		
		int res = 0;
		
		int x = 0;
		int y = 0;
		int dd = 3;
		
		VVI a (7500);
		VVI b (7500);
		
		int n;
		cin >> n;
		while (n--)
		{
			string s;
			int m;
			cin >> s >> m;
			
			while (m--)
			{
				REP (i, s.size ())
				{ 
					if (s[i]=='L')
						dd = (dd+1)%4;
					if (s[i]=='R')
						dd = (dd+3)%4;
					if (s[i]=='F')
					{
						if (dd==0)
						{
							a[x+3500-1].pb (y+3500);
							//cout << x << " " << y << endl;
						}
						if (dd==1)
						{
							b[y+3500-1].pb (x+3500);
						}
						x+=d[dd].X;
						y+=d[dd].Y;
						if (dd==2)
						{
							a[x+3500-1].pb (y+3500);
							//cout << x << " " << y << endl;
						}
						if (dd==3)
						{
							b[y+3500-1].pb (x+3500);
						}
					}
				}
			}			 
		}
		
		memset (e, 0, sizeof (e));
		REP (i, a.size ())
		{
			SORT(a[i]);
			
			REP (j, a[i].size ()/2-1)
			{
				int y1 = a[i][j*2+1];
				int y2 = a[i][j*2+2];
				
				FOR (y, y1, y2)
				{
					if (!e[i][y])
					{
						//cout << i << " " << y << endl;
						res++;
						e[i][y]=true;
					}
				}
			}
		}

		REP (i, b.size ())
		{
			SORT(b[i]);
					
			REP (j, b[i].size ()/2-1)
			{
				int x1 = b[i][j*2+1];
				int x2 = b[i][j*2+2];
						
				FOR (x, x1, x2)
				{
					if (!e[x][i])
					{
						//cout << x << " " << i << endl;
						
						res++;
						e[x][i]=true;
					}
				}
			}
		}
		
		cout << res << endl;
	}
	
	return 0;
}
