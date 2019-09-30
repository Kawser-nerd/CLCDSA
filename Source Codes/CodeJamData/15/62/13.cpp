#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <cassert>
#include <ctime>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
#define DBG(x) cerr << #x << ": " << x << endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int md = 1000000007;

ll F[1000010], fact[1000010], invf[1000010];


ll binpow(ll a, int b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % md;
        a = a * a % md;
    }
    return res;
}

ll C(int n, int m) {
    ll res = fact[n] * invf[n-m] % md;
    return res * invf[m] % md;
}

void gen() {
    int a[15];
    for (int n = 1; n <= 11; n++) {
        forn(i, n) a[i] = i;
        int res = 0;
        do {
            bool ok = true;
            forn(j, n) {
                if (a[j] == j) {
                    ok = false;
                    break;
                }
            }
            res += ok;
            //if (ok) {
            //    forn(j, n) printf("%d ", a[j]); printf("\n");
            //}
        } while (next_permutation(a, a + n));
        printf("%d: %d\n", n, res);
    }
}

void solve() {
    int n, x;
    scanf("%d %d", &n, &x);
    ll ans = 0;
    for (; x <= n; x++) {
        ll cur = C(n, x);
        cur = cur * cur % md;
        cur = cur * fact[x] % md;
        cur = cur * F[n-x] % md;
        cur = cur * fact[n-x] % md;
        // printf("%d: %lld\n", x, cur);
        ans = (ans + cur) % md;
    }
    printf("%lld\n", ans);
}

void init() {
    fact[0] = 1;
    invf[0] = 1;
    for (int i = 1; i <= 1000003; i++) {
        fact[i] = fact[i-1] * i % md;
        invf[i] = invf[i-1] * binpow(i, md - 2) % md;
    }
    F[0] = 1;
    F[1] = 0;
    for (int n = 2; n <= 1000003; n++) {
        F[n] = (F[n-1] + F[n-2]) * (n-1) % md;
        /*
        ll cur = 1;
        for (int k = 1; k <= n - 1; k++) {
            cur = cur * (n - k) % md;
            F[n] = (F[n] + cur * F[n-k-1]) % md;
            // printf("k=%d, cur=%lld, F[%d]=%lld\n", k, cur, n, F[n]);
        }
        */
        // printf("%d: %lld\n", n, F[n]);
        // F[n] = F[n] * fact[n] % md;
    }
}

int main() {
    // gen();
	int tc;
    auto start = clock();
	scanf("%d", &tc);
    init();
	for (int q = 1; q <= tc; q++) {
		printf("Case #%d: ", q);
		solve();
		fprintf(stderr, "Case %d done, %.3f sec.\n",
                q, double(clock() - start) / CLOCKS_PER_SEC);
	}
	return 0;
}
