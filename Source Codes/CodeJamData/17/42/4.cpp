#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
#define mt make_tuple
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
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 1001;
vi t[maxn];
int bc[maxn], pc[maxn];
int bt[maxn][maxn], pt[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    for1(tc, T) {
        cerr << tc << '\n';
        int n, c, m;
        cin >> n >> c >> m;
        forn(i, m) {
            int p, b;
            cin >> p >> b;
            --p; --b;
            t[p].pb(b);
            ++bc[b];
            ++pc[p];
        }

        int ans = 0;
        forn(i, c) uax(ans, bc[i]);
        int s = 0;
        forn(i, n) {
            s += pc[i];
            uax(ans, (s + i) / (i + 1));
        }


        int pen = 0;
        forn(i, n) pen += max(0, pc[i] - ans);

/*        forn(i, n) {
            for (int b: t[i]) {
                pii best = {-1, -1};
                forn(j, ans) {
                    if (bt[b][j]) continue;
                    int k = i;
                    while (k >= 0 && pt[k][j]) --k;
                    uax(best, mp(k, j));
                }
                assert(best.fi >= 0);
                pen += int(i > best.fi);
                bt[b][best.se] = pt[best.fi][best.se] = 1;
            }
        }*/

        cout << "Case #" << tc << ": ";
        cout << ans << ' ' << pen << '\n';

        forn(i, c) bc[i] = 0;
        forn(i, n) pc[i] = 0, t[i].clear();
        forn(i, c) forn(j, ans) bt[i][j] = 0;
        forn(i, n) forn(j, ans) pt[i][j] = 0;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
