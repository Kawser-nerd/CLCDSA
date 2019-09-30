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

const string name = "C-small-attempt3";

int n, m;
int c[256], s[256], t[256];

int main() {
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
	int T;
	cin >> T;
	FOR (test, 1, T+1) {
        cin >> n;
        REP (i, n)
            cin >> c[i] >> s[i] >> t[i];
        cin >> m;
        REP (i, m)
            cin >> c[i+n] >> s[i+n] >> t[i+n];
            
        int T = 1;
        int S = 0;
        int C = 0;
        vector<int> c0;
        vector<int> c1;
        REP (i, n)
            if (t[i] > 0) {
                T += t[i]-1;
                S += s[i];
                C += c[i];
            } else {
                if (c[i] == 0)
                    c0.pb(s[i]);
                else
                    c1.pb(s[i]);
            }
        int res = S;
        
        vector<int> total = c0;
        REP (i, sz(c1)) total.pb(c1[i]);
        sort(all(total));
        reverse(all(total));
        REP (i, min(sz(total), T))
            res += total[i];
            
        FOR (i, n, n+m) {
            if (!T) break;
            if (C == 0) {
                if (!sz(c1)) break;
                sort(all(c1));
                S += c1.back();
                c1.pop_back();
                ++C;
                --T;
            }   
            if (T) {                     
                --C;
                if (t[i] > 0) {
                    T += t[i]-1;
                    S += s[i];
                    C += c[i];
                } else {
                    if (c[i] == 0)
                        c0.pb(s[i]);
                    else
                        c1.pb(s[i]);
                }
            }
            
            vector<int> total = c0;
            REP (i, sz(c1)) total.pb(c1[i]);
            sort(all(total));
            reverse(all(total));
            int ans = S;
            REP (i, min(sz(total), T))
                ans += total[i];
            res = max(res, ans);
        }
        cout << "Case #" << test << ": ";
        cout << res << endl;
    }
	return 0;
}
