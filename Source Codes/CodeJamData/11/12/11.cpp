#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset((a),(b),sizeof(a))

#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const string name = "B-large";
string order;

vector <string> dict;

pii ans;

void solve(vector <int> a, int p, int lose) {
    if (p == 26) {
        pair<int, int> res;
        res.X = lose;
        res.Y = -a[0];
        ans = max(ans, res);
        return;
    }
    map<int, vector<int> > h;
    REP (i, sz (a)) {
        int mask = 0;
        REP (j, sz (dict[a[i]]))
            if (dict[a[i]][j] == order[p])
                mask |= 1<<j;
        h[mask].pb(a[i]);
    }
    for(map<int, vector<int> >::iterator it = h.begin(); it != h.end(); ++it) {
        solve(it->Y, p+1, lose+(it->X == 0 && sz(it->Y) != sz(a)));
    }
}

int main() {
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
	int T;
	cin >> T;
	int n, m;
	FOR (test, 1, T+1) {
        cin >> n >> m;
        
        dict.clear();
        map<int, vector<int> > h;
        REP (i, n) {
            string s;
            cin >> s;
            dict.pb(s);
            h[sz(s)].pb(i);
        }
        cout << "Case #" << test << ":";        
        REP (j, m) {
            cin >> order;
            ans.X = -1;
            for(map<int, vector<int> >::iterator it = h.begin(); it != h.end(); ++it) {
                solve(it->Y, 0, 0);
            }
            cout << ' ' << dict[-ans.Y];
        }
        cout << endl;
    }
	return 0;
}
