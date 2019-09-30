#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
#define next NEXT64
#define prev PREV64
#define y1 Y164

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr(T x) { return x * x; }

bool a[300][300];
int ma[300];
bool seen[300];
bool u[300];
bool canMove[300];
int n, m;
char f[300][300];
char f0[300][300];

bool dfs(int v) {
    if (u[v]) return false;
    u[v] = true;
    forn(i, n*3) {
        if (!a[v][i]) continue;
        if (!canMove[i]) continue;
        if (ma[i] == -1 || dfs(ma[i])) {
            ma[i] = v;
            return true;
        }
    }
    return false;
}

void solve() {
    seta(a, 0);
    seta(ma, 255);
    seta(seen, 0);
    seta(f, 0);
    seta(canMove, 1);
    cin >> n >> m;
    int score = 0;
    forn(i, n)
        forn(j, n)
            f0[i][j] = '.';
    forn(i, n)
        forn(j, n) {
            a[i][j] = true;
            a[n+i+j][n*2+i-j] = true;
        }
    forn(i, m) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        x--;
        y--;
        f0[x][y] = c;
        if (c == '+') {
            ma[n*2+x-y] = n + x + y;
            score++;
        } else if (c == 'x') {
            ma[y] = x;
            score++;
        } else {
            ma[n*2+x-y] = n + x + y;
            ma[y] = x;
            score += 2;
        }
    }
    forn(i, n*3) {
        if (ma[i] != -1) {
            seen[ma[i]] = 1;
            canMove[i] = false;
        }
    }
    forn(i, n*3) {
        if (seen[i]) continue;
        seta(u, 0);
        if (dfs(i)) {
            score++;
        }
    }
    forn(i, n)
        forn(j, n)
            f[i][j] = '.';
    forn(i, n)
        if (ma[i] != -1) {
            f[ma[i]][i] = 'x';
        }
    for(int i = n; i < n*3; i++) {
        if (ma[i] != -1) {
            int xmy = i - n*2;
            int xpy = ma[i] - n;
            int x = (xpy + xmy) / 2;
            int y = (xpy - xmy) / 2;
            if (f[x][y] == 'x') {
                f[x][y] = 'o';
            } else {
                f[x][y] = '+';
            }
        }
    }
    int cnt = 0;
    forn(i, n)
        forn(j, n)
            if (f[i][j] != f0[i][j]) cnt++;
    cout << score << " " << cnt << endl;
    forn(i, n)
        forn(j, n)
            if (f[i][j] != f0[i][j]) {
                cout << f[i][j] << " " << i+1 << " " << j+1 << endl;
            }
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	forn(i, t) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}

