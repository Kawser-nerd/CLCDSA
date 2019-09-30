#include <iostream>
#include <vector>
#include <cassert>
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

int main() {
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
#endif

    int T;
    cin >> T;
    forn(t, T) {
        cout << "Case #" << t + 1 << ": ";
        int N;
        cin >> N;
        vector<string> s(N);
        forn(i, N) {
            cin >> s[i];
            s[i].erase(unique(all(s[i])), s[i].end());
        }
        int comps = 26;
        bool ok = true;
        i64 ans = 1;
        const i64 P = 1000000000 + 7;
        for (char c = 'a'; c <= 'z'; ++c) {
            int mid = 0, st = 0, end = 0, comp = 0;
            forn(i, N) {
                int th = 0;
                forn(j, s[i].size()) {
                    if (s[i][j] == c) {
                        ++th;
                        if (s[i].size() > 1) {
                            if (j == 0) ++st;
                            else if (j + 1 == s[i].size()) ++end;
                            else ++mid;
                        } else {
                            ++comp;
                        }
                    }
                }
                if (th > 1) {
                    ok = false;
                    break;
                }
            }
            if (mid + st + end + comp == 0) {
                --comps;
                continue;
            }
            if (mid && st + end + comp + mid - 1) {
                ok = false;
                break;
            }
            if (st > 1 || end > 1) {
                ok = false;
                break;
            }
            for (int i = 1; i <= comp; ++i) {
                ans *= i;
                ans %= P;
            }
        }
        if (!ok) {
            cout << "0\n";
            continue;
        }
        vector<int> next(26, -1);
        forn(i, N) {
            for (int j = 0; j + 1 < (int)s[i].size(); ++j) {
                if (s[i][j] != s[i][j + 1]) {
                    --comps;
                    assert(next[s[i][j] - 'a'] == -1);
                    next[s[i][j] - 'a'] = s[i][j + 1] - 'a';
                }
            }
        }
        forn(i, 26) {
            int j = next[i];
            while (j != -1 && j != i) j = next[j];
            if (j == i) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "0\n";
            continue;
        }

        for (int i = 1; i <= comps; ++i) {
            ans *= i;
            ans %= P;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
