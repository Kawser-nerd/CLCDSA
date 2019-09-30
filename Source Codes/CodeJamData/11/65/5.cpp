#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>
#include <string.h>
#include <cstdio>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define NMAX 25
#define MAGIC 5005
#define EPS 1e-7

int a, m, v;
ld p[NMAX][NMAX][NMAX];

void solve(int test)
{
    printf("Case #%d: ", test);


    memset(p, 0, sizeof(p));

    cin >> a >> m >> v;

    forn(it, MAGIC)
    {


    for1(x, v - 1)
    {
    	forn(b, m + 1)
    	{
    		forn(s, 5)
    		{
    			ld maxp = 0.0;

    			if (b == 0)
    			{
    				if (s) continue;


    				for1(b1, min(m, x))
    				{
    					if (x + b1 >= v)
    					{
    						maxp = max(maxp, 0.5 + 0.5 * p[x][b1][0]);
    					} 	
    					else
    					{
    						maxp = max(maxp, 0.5 * p[x + b1][0][0] + 0.5 * p[x][b1][0]);
    					}
    				}
    			}
    			else
    			{
    				int sub = (b << (s + 1)) - b;

    				if ((b << (s + 1)) > m)
    				{
    					if (x - sub <= 0) maxp = 0;
    					else maxp = p[x - sub][0][0];
    				} 
    				else
    				{
    					if (x - sub <= 0)
    					{
    						if (x + b >= v)
    						{
    							maxp = 0.5 + 0.5 * p[x][b][s + 1];
    						}	
    						else
    						{
    							maxp = 0.5 * p[x + b][0][0] + 0.5 * p[x][b][s + 1];
    						}
    					}	
    					else
    					{
    						if (x + b >= v)
    						{
    							maxp = max(p[x - sub][0][0], 0.5 + 0.5 * p[x][b][s + 1]);
    						}
    						else
    						{
    							maxp = max(p[x - sub][0][0], 0.5 * p[x + b][0][0] + 0.5 * p[x][b][s + 1]);
    						}
    					}
    				}
    			}

    			p[x][b][s] = maxp;
    		}
    	}
    }

    }


    int ans = 0;

    for1(b1, min(m, a))
    {
    	
    	ld maxp;
    	if (a + b1 >= v)
    	{
    		maxp = 0.5 + 0.5 * p[a][b1][0];
    	} 	
    	else
    	{
    		maxp = 0.5 * p[a + b1][0][0] + 0.5 * p[a][b1][0];
    	}

    	if (fabsl(maxp - p[a][0][0]) < EPS)
    	{
    		ans = b1;
    	}
    }
    	
    cout << p[a][0][0] << " " << ans << endl;

}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    cout << fixed;
    cout.precision(9);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);

    return 0;
}