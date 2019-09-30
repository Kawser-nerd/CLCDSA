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
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TPoint {
    ld x, y;

    TPoint(ld x = 0.0, ld y = 0.0)
        : x(x)
        , y(y)
    {
    }

    TPoint operator+(const TPoint &p) const {
        return TPoint(x + p.x, y + p.y);
    }

    TPoint operator-(const TPoint &p) const {
        return TPoint(x - p.x, y - p.y);
    }

    TPoint operator*(ld t) const {
        return TPoint(t * x, t * y);
    }

    ld operator*(const TPoint &p) const {
        return x * p.x + y * p.y;
    }

    ld operator%(const TPoint &p) const {
        return x * p.y - y * p.x;
    }

    ld operator~() const {
        return sqrtl(*this * *this);
    }
};

bool cmp(TPoint a, TPoint b) { 
    return a % b > 0;
}

const ld PI = atan2l(0, -1);
const ld eps = 0.0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int T;
    cin >> T;
    for1(t, T) {
        int N;
        ld V, X;
        cin >> N >> V >> X;
        vector<double> r(N), c(N);
        forn(i, N) cin >> r[i] >> c[i];
        double minc = 1e9, maxc = -1e9;
        forn(i, N) uin(minc, c[i]), uax(maxc, c[i]);
        if (minc > X + 1e-9 || maxc < X - 1e-9) {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }
        if (fabs(minc - X) < 1e-9) {
            double ss = 0.0;
            forn(i, N) {
                if (fabs(c[i] - X) < 1e-9) ss += r[i];
            }
            cout << "Case #" << t << ": " << (double)(V / ss) << "\n";
            continue;
        }
        if (fabs(maxc - X) < 1e-9) {
            double ss = 0.0;
            forn(i, N) {
                if (fabs(c[i] - X) < 1e-9) ss += r[i];
            }
            cout << "Case #" << t << ": " << (double)(V / ss) << "\n";
            continue;
        }

        vector<TPoint> sides;
        forn(i, N) sides.pb(TPoint(r[i], r[i] * c[i]));
        sort(all(sides), cmp);
        ld L = 0.0, R = 1e9;
        forn(ITS, 100) {
            ld m = 0.5 * (L + R);
            ld sang = 0.0;
            TPoint p(0, 0);
            TPoint target(V, V * X);
            forn(i, N) {
                TPoint q = p + sides[i] * m;
                sang += atan2l((p - target) % (q - target), (p - target) * (q - target));
                p = q;
            }
            forn(i, N) {
                TPoint q = p - sides[i] * m;
                sang += atan2l((p - target) % (q - target), (p - target) * (q - target));
                p = q;
            }
//            cerr << sang << '\n';
            (fabs(sang - 2 * PI) < 1 ? R : L) = m;
        }
        cout << "Case #" << t << ": " << (double)R << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
