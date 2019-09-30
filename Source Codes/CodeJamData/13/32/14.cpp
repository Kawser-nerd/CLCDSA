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

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w+", stdout);

    int t;
    cin >> t;
    REP (tt, t) {
        std::cout << "Case #" << tt+1 << ": ";

        int x, y;
        cin >> x >> y;

        if (x < 0)
            REP(i, abs(x))
                cout << "EW";
        else REP (i, x)
            cout << "WE";

        if (y<0)
            REP(i, abs(y))
                cout << "NS";
        else
            REP (i, y)
                cout << "SN";

        cout << endl;
    }

    return 0;
}
