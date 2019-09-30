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

int res[32][32];
int u[32][32];
int n, m;
string a[32];

int d[32][32];

void go (int x, int y, int v)
{
	if (x<0 || y<0 || x>=n || y>=m)
		return;
	
	if (a[x][y]=='#')
		return;
	
	res[x][y]<?=v;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
	
	int tt;
	cin >> tt;
	REP (t, tt)
	{
		cout << "Case #" << t+1 << ": ";
		
		cin >> n >> m;
		
		n+=2;
		m+=2;
		
		memset (u, 0, sizeof (u));
		
		REP (i, n)
			REP (j, m)
			{
				d[i][j] = INF;
				res[i][j] = INF;
			}
		
		a[0] = "##########################";
		a[n-1] = "##########################";
		
		FOR (i, 1, n-1)
		{
			cin >> a[i];
			a[i] = "#"+a[i]+"#";
		}
		
		REP (i, n)
			REP (j, m)
				if (a[i][j]=='O')
				{
					res[i][j] = 0;
				}
		
		REP (i, n)
			REP (j, m)
				REP (ii, n)
					REP (jj, m)
						if (a[ii][jj]=='#')
							d[i][j]<?=abs (i-ii)+abs (j-jj);
		
		while (1)
		{
			int x = 0;
			int y = 0;
			
			int rr = INF;
			
			REP (i, n)
				REP (j, m)
					if (res[i][j]<rr && !u[i][j])
					{
						x = i;
						y = j;
						
						rr = res[i][j];
					}
			
			if (rr==INF)
				break;
			
			u[x][y] = 1;
			
			go (x-1, y, rr+1);
			go (x+1, y, rr+1);
			go (x, y-1, rr+1);
			go (x, y+1, rr+1);
			
			int xx = x;
			while (xx>0 && a[xx-1][y]!='#')
				xx--;
			if (xx>0)
				go (xx, y, rr+d[x][y]);
			
			xx = x;
			while (xx<n-1 && a[xx+1][y]!='#')
				xx++;
			if (xx<n-1)
				go (xx, y, rr+d[x][y]);
						
			int yy = y;
			while (yy>0 && a[x][yy-1]!='#')
				yy--;
			if (yy>0)
				go (x, yy, rr+d[x][y]);
				
			yy = y;
			while (yy<m-1 && a[x][yy+1]!='#')
				yy++;
			if (yy<m-1)
				go (x, yy, rr+d[x][y]);
						
		}
		
		int r = INF;
		
		REP (i, n)
			REP (j, m)
				if (a[i][j]=='X')
					r = res[i][j];
		
		if (r<INF)
			cout << r << endl;
		else
			cout << "THE CAKE IS A LIE" << endl; 
	}
	
	return 0;
}
