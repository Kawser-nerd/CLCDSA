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

long double wrong[1024];
long double cnk[1024][1024];
long double cnk2[1024][1024];
long double fact[1024];

long double wf[1024];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    REP (i, 1024)
		REP (j, 1024)
		{
			if (j == 0 || i==j)
				cnk[i][j] = 1;
			else if (i < j)
				cnk[i][j] = 0;
			else
				cnk[i][j] = cnk[i-1][j] + cnk[i-1][j-1];
		}

    REP (i, 1024)
		REP (j, 1024)
    	{
    		if (j == 0 || i==j)
    			cnk2[i][j] = 1;
    		else if (i < j)
    			cnk2[i][j] = 0;
    		else
    			cnk2[i][j] = (cnk2[i-1][j] + cnk2[i-1][j-1])/i;
    	}

    fact[0] = 1;
    FOR (i, 1, 1024)
		fact[i] = fact[i-1]*i;

    wrong[0] = 1;
    wrong[1] = 0;
    FOR (i, 2, 1024)
    {
    	wrong[i] = 0;
    	FOR (j, 2, i+1)
			wrong[i] += fact[j-1]*cnk[i-1][j-1]*wrong[i-j];

    	wf[i] = wrong[i]/fact[i];
    	if (i>150)
    		wf[i] = wf[i-1];
    }

    long double r[1024];

    r[0] = 0;
    r[1] = 0;

    FOR (i, 2, 1024)
    {
    	r[i] = 1;
    	REP(j, i)
    	{
    		r[i] += r[j]*wf[j]/fact[i-j];
    	}
    	r[i] /= (1-wf[i]);
    	//cout << r[i] << endl;
    }

    int tt;
    cin >> tt;

    REP (t, tt)
    {
    	int n;
    	cin >> n;
    	int m = 0;

    	REP (i, n)
    	{
    		int x;
    		cin >> x;
    		x--;
    		if (x!=i)
    			m++;
    	}
    	printf ("Case #%d: %.6lf\n", t+1, (double)r[m]);
    }

    return 0;
}
