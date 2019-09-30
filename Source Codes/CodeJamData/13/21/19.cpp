#pragma comment (linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 310;


int n, own, other[MAXN];


void read() {
    cin >> own >> n;
    forn(i, n)
        cin >> other[i];
}


int d[MAXN][MAXN];

inline void upd_d(int next, int cans, int nd) {
    if (nd > d[next][cans])
        d[next][cans] = nd;
}

void solve() {
    sort(other, other + n);

    forn(i, MAXN)
        forn(j, MAXN)
            d[i][j] = -INF;

    d[0][0] = own;
    forn(next, n)
        forn(cans, n * 2) {
            int my = d[next][cans];
            if (my <= 1)
                continue;

            int addans = 0;
            while (my <= other[next]) {
                my += my - 1;
                ++addans;
            }

            upd_d(next + 1, cans + addans, my + other[next]);
        }

    int ans = INF;
    forn(next, n + 1)
        forn(cans, n * 2)
            if (d[next][cans] >= 0)
                ans = min(ans, cans + n - next);
    cout << ans << endl;            
}


int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int ts;
    cin >> ts;
    for (int tt = 0; tt < ts; ++tt) {
        printf("Case #%d: ", tt + 1);

        read();
        if (!cin)
            throw;
        solve();
    }
}
