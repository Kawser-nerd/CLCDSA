#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <cmath>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

double curtime() {
    return double(clock()) / CLOCKS_PER_SEC;
}

ll n, A, B;
map<ll, ll> mf;

ll f(int d) {
    if (d < 0) return 0;
    if (d < A) return 1;

    if (mf.find(d) != mf.end()) return mf[d];

    return mf[d] = f(d - A) + max(1LL, f(d - B));
}

void solve() {
    cin >> n >> A >> B;
    mf.clear();
    for (int d = 0; ; d++) {
        if (f(d) >= n) {
            printf("%d\n", d);
            return;
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        solve();
        fprintf(stderr, "Test %d done, time: %.5f sec.\n", t, curtime());
    }
	return 0;
}
