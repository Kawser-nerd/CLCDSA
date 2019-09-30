#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int trans[101][101];
double ex[101][101];
int best[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int T;
    cin >> T;
    forn(ttt, T) {
        int K, L, S;
        string s, t;
        cin >> K >> L >> S >> s >> t;
        int n = s.size(), m = t.size();
        forn(i, S + 1) forn(j, m + 1) ex[i][j] = 0.0, best[i][j] = 0;
        forn(i, m + 1) forn(j, n) {
            string u = string(t.begin(), t.begin() + i) + s[j];
            ford(l, min(m, (int)u.size()) + 1) {
                if (string(t.begin(), t.begin() + l) == string(u.end() - l, u.end())) {
                    trans[i][j] = l;
                    break;
                }
            }
        }
        ex[0][m] = 1.0;
        best[0][m] = 1;
        forn(i, S) forn(j, m + 1) forn(k, n) {
            int jj = trans[j][k];
            ex[i + 1][j] += (ex[i][jj] + (j == m)) * (1.0 / n);
            uax(best[i + 1][j], best[i][jj] + (j == m));
        }
        printf("Case #%d: %.10lf\n", ttt + 1, best[S][0] - ex[S][0]);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
