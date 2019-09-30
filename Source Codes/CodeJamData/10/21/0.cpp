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

    int t;
    cin >> t;
    REP (tt, t)
    {
        cout << "Case #" << (tt+1) << ": ";

        int n, m;
        cin >> n >> m;
        set <string> S;
        REP (i, n)
        {
            string s;
            cin >> s;
            S.insert(s);
        }

        int res =0 ;

        REP (i, m)
        {
            string s;
            cin >> s;
            vector <string> ss;
            REP (j, s.size())
                if(s[j] == '/')
                    s[j] = ' ';
            istringstream iss (s);
            while (iss >> s) {
                ss.pb (s);
            }

            s = "";
            REP (i, ss.size ())
            {
                s = s+"/"+ss[i];
                if (S.find(s) == S.end())
                {
                    res ++;
                    S.insert(s);
                }
            }
        }
        cout << res << endl;
    }

	return 0;
}
