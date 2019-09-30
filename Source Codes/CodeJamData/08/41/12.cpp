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
		cout << "Case #"<<(t+1) <<": ";
		int n, v;
		cin >> n >> v;

		VI type (n);
		VI c(n);

		VI r0(n, INF);
		VI r1(n, INF);

		REP (i, (n-1)/2)
			cin >> type[i] >> c[i];

		REP (i, (n+1)/2)
		{
			int x;
			cin >> x;
			if (x==0)
				r0[(n-1)/2+i] = 0;
			else
				r1[(n-1)/2+i] = 0;
		}

		FORD (i, (n-1)/2-1, 0)
		{
			int c1 = (i+1)*2-1;
			int c2 = (i+1)*2;

			//cout << i << " " << c1 << " " << c2 << " " << r0[c1] << " " << r1[c1] << " " << r0[c2] << " " << r1[c2] << endl;

			if (type[i]==1)
			{
				r0[i] <?= min(r0[c1], r0[c2]);
				r1[i] <?= r1[c1]+r1[c2];

				if (c[i])
				{
					r0[i] <?= 1 + r0[c1]+r0[c2];
					r1[i] <?= 1 + min (r1[c1], r1[c2]);
				}
			}
			else
			{
				r0[i] <?= r0[c1]+r0[c2];
				r1[i] <?= min (r1[c1], r1[c2]);

				if (c[i])
				{
					r0[i] <?= 1 + min(r0[c1], r0[c2]);
					r1[i] <?= 1 + r1[c1]+r1[c2];
				}
			}
		}
		int res = 0;
		if (v == 0)
			res = r0[0];
		else
			res = r1[0];

		if (res==INF)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << res << endl;
	}

	return 0;
}
