#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

int tr(int x) {
    return x * (x + 1) / 2;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int T;
    cin >> T;
    forn(t, T) {
        cout << "Case #" << t + 1 << ": ";
        int N, M, K;
        cin >> N >> M >> K;
        int ans = K;
        for (int w = 2; w <= N; ++w) {
            for (int h = 2; h <= M; ++h) {
                for (int c = 0; c <= min(N, M); ++c) {
                    forn(c00, 2) forn(c01, 2) forn(c10, 2) forn(c11, 2) {
                        if (2 * c + c00 + c01 >= w) continue;
                        if (2 * c + c10 + c11 >= w) continue;
                        if (2 * c + c00 + c10 >= h) continue;
                        if (2 * c + c01 + c11 >= h) continue;
                        int S = w * h - tr(c + c00) - tr(c + c01) - tr(c + c10) - tr(c + c11);
                        int P = 2 * (w + h) - 4  - 4 * c - c00 - c01 - c10 - c11;
                        if (S >= K) ans = min(ans, P);
                    }
                }
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
