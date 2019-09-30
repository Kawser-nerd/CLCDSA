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


const int MAXN = 3100;


int n, x, y;


void read() {
    cin >> n >> x >> y;
    x = abs(x);
}


double d[MAXN][MAXN];


double solve() {
    int side = 1;
    for (;;) {
        int cnt = side * 2 - 1;
        if (n < cnt)
            break;
        n -= cnt;
        side += 2;
    }
    --side;

    if (n >= MAXN - 10)
        throw;

    memset(d, 0, sizeof d);
    d[0][0] = 1;
    forn(left, MAXN)
        forn(right, MAXN) {
            if (left + right >= n)
                break;

            double my = d[left][right];
            if (my == 0)
                continue;

            if (left == side && right == side)
                throw;
            if (left > side || right > side)
                throw;

            if (left == side)
                d[left][right + 1] += my;
            else if (right == side)
                d[left + 1][right] += my;
            else {
                d[left + 1][right] += my * 0.5;
                d[left][right + 1] += my * 0.5;
            }
        }

    if (x + y <= side - 2)
        return 1;
    if (x + y >= side + 2)
        return 0;

    double ans = 0;
    forn(left, n + 1) {
        double prob = d[left][n - left];
        if (left > y)
            ans += prob;
    }
    return ans;
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
        printf("%.20lf\n", solve());
    }
}
