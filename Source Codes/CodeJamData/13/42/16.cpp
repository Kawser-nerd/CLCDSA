#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
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
//typedef double old_double;
//#define double long double
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


int n;
int64 p;


void read() {
    cin >> n >> p;
}


int64 worst_pos(int64 who, int n) {
    if (who == 0)
        return 0;
    if (who >= (1ll << n))
        throw;
    return worst_pos((who - 1) / 2, n - 1) + (1ll << (n - 1));
}

int64 best_pos(int64 who, int n) {
    who = (1ll << n) - who - 1;
    int64 res = worst_pos(who, n);
    return (1ll << n) - res - 1;
}


int64 solve_guarantee(int n, int64 p) {
    int64 l = 0, r = (1ll << n) - 1;
    while (l < r) {
        int64 m = (l + r + 1) >> 1;
        if (worst_pos(m, n) >= p)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

int64 solve_possible(int n, int64 p) {
    int64 l = 0, r = (1ll << n) - 1;
    while (l < r) {
        int64 m = (l + r + 1) >> 1;
        if (best_pos(m, n) >= p)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

void solve() {
    cout << solve_guarantee(n, p) << ' ' << solve_possible(n, p) << endl;
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	forn(tt, ts) {
		read();
		if (!cin)  throw;
		printf("Case #%d: ", tt + 1);
		solve();
	}
}
