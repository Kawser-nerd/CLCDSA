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
    REP (test, tt)
    {
		int t1 = 0;
		int t2 = 0;

		int p1 = 1;
		int p2 = 1;

		int t = 0;

		int n;
		cin >> n;
		while (n--)
		{
			int x;
			string s;
			cin >> s >> x;

			if (s=="O")
			{
				t1 += abs(x-p1) + 1;
				p1 = x;

				t1 = max(t+1, t1);
				t = t1;
			}
			else
			{
				t2 += abs(x-p2) + 1;
				p2 = x;

				t2 = max(t+1, t2);
				t = t2;
			}

			//cout << t1 << " " << t2 << endl;
		}

		cout << "Case #" << test + 1 << ": ";
		cout << t << endl;
    }

    return 0;
}
