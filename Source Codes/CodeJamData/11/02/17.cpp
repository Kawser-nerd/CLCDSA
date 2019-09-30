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
    	string s;
    	int c, d, n;
    	cin >> c;
    	vector <string> a(c);
    	REP (i, c)
			cin >> a[i];
    	cin >> d;
    	vector <string> b(d);
    	REP (i, d)
			cin >> b[i];
    	cin >> n >> s;

    	vector <char> res;

    	REP (i, n)
    	{
    		res.pb (s[i]);

    		if (res.size()>1)
    			REP (j, a.size())
					if ((res.back() == a[j][0] && res[res.size()-2] == a[j][1]) ||
					    (res.back() == a[j][1] && res[res.size()-2] == a[j][0]))
					{
						res.pop_back();
						res.pop_back();
						res.pb(a[j][2]);
					}

    		REP (j, b.size())
				REP (k, res.size()-1)
				if ((res.back() == b[j][0] && res[k] == b[j][1]) ||
    				(res.back() == b[j][1] && res[k] == b[j][0]))
					res.clear();
    	}


    	cout << "Case #" << t+1 << ": [";
    	REP (i, res.size())
    	{
    		if (i)
    			cout << ", ";
    		cout << res[i];
    	}
    	cout << "]" << endl;
    }

    return 0;
}
