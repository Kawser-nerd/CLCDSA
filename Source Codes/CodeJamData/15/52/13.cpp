#include <bits/stdc++.h>

#define FO(i,a,b) for (long long i = (a); i < (b); i++)

using namespace std;

long long s[1005];
long long mn[1005], mx[1005];
long long vl[1005];

long long floor(long long a, long long b) {
    if (a % b == 0) return a / b;
    if (a > 0) return a/b;
    else return - ((-a)/b) - 1;
}

long long ceil(long long a, long long b) {
    if (a % b == 0) return a / b;
    else return floor(a,b)+1;
}

int main() {
    long long T; scanf("%lld", &T);
    FO(Z,1,T+1) {
        long long n, k; scanf("%lld%lld", &n, &k);
        FO(i,0,1005) s[i] = vl[i] = 0, mn[i] = 0, mx[i] = 0;
        FO(i,0,n-k+1) scanf("%lld", &s[i]);
        FO(i,k,n) {
            vl[i] = vl[i-k] + s[i-k+1] - s[i-k];
            mn[i%k] = min(mn[i%k], vl[i]);
            mx[i%k] = max(mx[i%k], vl[i]);
        }
        long long st = 0, e = 1ll<<55, res = 1ll<<61;
        while (st <= e) {
            long long m = (st+e)/2;

            bool can = false;
            long long sv = 0, bv = 0;
            // values must be in [lo,lo+m]
            FO(i,0,k) {
                // x + mn[i] = lo -> x = lo-mn[i]
                // x + mx[i] = lo+m -> x = lo+m-mx[i]
                long long lv = -mn[i], rv = +m-mx[i];
                if (lv > rv) {
                    sv = 1; bv = 0;
                    break;
                }
                sv += lv; bv += rv;
            }
            if (sv <= bv) {
                // k*lo + sv <= s[0] <= k*lo + bv
                // lo <= (s[0]-sv)/k
                // (s[0]-bv)/k <= lo
                long long mnk = ceil(s[0]-bv,k);
                long long mxk = floor(s[0]-sv,k);
                if (mnk <= mxk) {
                    can = true;
                }
            }

            if (can) {
                e = m-1;
                res = m;
            } else st = m+1;
        }
        if (res > (1ll<<60)) {
            fprintf(stderr, "WHOOPS\n");
            return 0;
        }
        printf("Case #%lld: %lld\n", Z, res);
    }
}

