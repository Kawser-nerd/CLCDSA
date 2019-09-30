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


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int tt;
	cin >> tt;

	REP (t, tt)
	{
		printf ("Case #%d: ", t+1);

		int n;
		cin >> n;

		VI x(n), y(n), z(n);

		vector <long double> p(n);

		VI cc11(n), cc12(n), cc21(n), cc22(n), cc31(n), cc32(n), cc41(n), cc42(n);

		REP (i, n)
		{
			cin >> x[i] >> y[i] >> z[i] >> p[i];
		}

		long double r1 = 0;
		long double r2 = 1e9;

		REP (c, 100)
		{
			long double r = (r1+r2)/2;

			//cout <<"r = "<< r << endl;

			long double c11 = -1e10;
			long double c12 = 1e10;
			long double c21 = -1e10;
			long double c22 = 1e10;
			long double c31 = -1e10;
			long double c32 = 1e10;
			long double c41 = -1e10;
			long double c42 = 1e10;

			REP (i, n)
			{

				c11 >?= -r*p[i] +(x[i]+y[i]+z[i]);
				c12 <?= r*p[i] +(x[i]+y[i]+z[i]);

				c21 >?= -r*p[i] + (x[i]+y[i]-z[i]);
				c22 <?= r*p[i] + (x[i]+y[i]-z[i]);

				c31 >?= -r*p[i] + (x[i]-y[i]+z[i]);
				c32 <?= r*p[i] + (x[i]-y[i]+z[i]);

				c41 >?= -r*p[i] + (x[i]-y[i]-z[i]);
				c42 <?= r*p[i] + (x[i]-y[i]-z[i]);
			}

			if (c11<=c12 && c21<=c22 && c31<=c32 && c41<=c42)
				r2 = r;
			else
				r1 = r;
		}
		printf ("%.6lf\n", (double)r1);
	}

	return 0;
}
