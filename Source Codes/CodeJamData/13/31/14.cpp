#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define INF 1000000000
#define X first
#define Y second
#define pb push_back

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

bool iscons(char c) {
    if (c == 'a' || c == 'o' || c=='i' || c=='u' || c == 'e')
    return false;
    return true;
}

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t) {
        std::cout << "Case #" << tt+1 << ": ";

        string s;
        cin >> s;
        int n;
        cin >> n;

        long long res = 0;

        int ind = -1;
        int nv = 0;

        REP (i, s.size()) {
            if (iscons(s[i]))
                nv++;
            else
                nv = 0;
            if (nv >= n)
                ind = i-n+1;

            if (ind > -1)
                res += ind+1;
        }

        cout << res << endl;
    }

    return 0;
}
