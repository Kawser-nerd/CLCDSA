#include <algorithm>
#include <iostream>
#include <vector>
#define SZ(x) ((int) (x).size())
using namespace std;

const int MOD = 998244353;

int Pow(int x, int y) {
    int res = 1;
    for (; y > 0; y /= 2) {
        if (y & 1) {
            res = (int64_t) res * x % MOD;
        }
        x = (int64_t) x * x % MOD;
    }
    return res;
}

int invMod(int x) {
    return Pow(x, MOD - 2);
}

int brute(const string& a, const string& b) {
    int n = SZ(a);
    vector<int> ind1, ind2;
    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            ind1.push_back(i);
        }
        if (b[i] == '1') {
            ind2.push_back(i);
        }
    }
    int ans = 0;
    int cntv = 0;
    do {
        do {
            string newA = a;
            for (int i = 0; i < SZ(ind1); ++i) {
                swap(newA[ind1[i]], newA[ind2[i]]);
            }
            if (newA == b) {
                ans++;
                bool ok = true;
                for (int i = 0; i < SZ(ind1); ++i) {
                    ok &= ind1[i] != ind2[i];
                }
                if (ok) {
                    for (int i = 0; i < SZ(ind1); ++i) {
                        cerr << ind1[i] + 1 << ' ';
                    }
                    cerr << endl;
                    for (int i = 0; i < SZ(ind2); ++i) {
                        cerr << ind2[i] + 1 << ' ';
                    }
                    cerr << endl << endl;
                }
                cntv += ok;
            }
        } while (next_permutation(ind2.begin(), ind2.end()));
    } while (next_permutation(ind1.begin(), ind1.end()));
    cerr << cntv << endl;
    return ans;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    // cerr << brute(A, B) << endl;

    int a = 0, b = 0;
    for (int i = 0; i < SZ(A); ++i) {
        if (A[i] == '1' && B[i] == '1') {
            b++;
        } else if (A[i] == '0' && B[i] == '1') {
            a++;
        }
    }
    int n = SZ(A);
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        fact[i] = (int64_t) fact[i - 1] * i % MOD;
    }
    vector<int> invFact(n + 1, 1);
    invFact[n] = invMod(fact[n]);
    for (int i = n - 1; i >= 0; --i) {
        invFact[i] = invFact[i + 1] * (int64_t) (i + 1) % MOD;
    }
    auto comb = [&](int n, int k) -> int {
        if (n < 0 || k < 0 || k > n) {
            return 0;
        }
        return fact[n] * (int64_t) invFact[n - k] % MOD * invFact[k] % MOD;
    };
    vector<int> dpx(b + 1, 0);
    dpx[0] = 1;
    for (int i = 1; i <= b; ++i) {
        for (int size = 1; size <= i; ++size) {
            int add = dpx[i - size] * (int64_t) comb(i, size) % MOD *
                comb(i - 1, size - 1) % MOD * fact[size] % MOD * fact[size - 1] % MOD;
            dpx[i] += add;
            dpx[i] %= MOD;
        }
    }
    vector<int> dp(b + 1, 0);
    vector<int> ndp(b + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= a; ++i) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int j = 0; j <= b; ++j) {
            if (i + 1 <= a) {
                ndp[j] = (ndp[j] + dp[j] * (int64_t) (a - i) % MOD *
                    (a - i)) % MOD;
            }
            if (j + 1 <= b) {
                dp[j + 1] = (dp[j + 1] + dp[j] * (int64_t) (b - j) % MOD *
                    (a - i)) % MOD;
            }
        }
        if (i < a) {
            dp.swap(ndp);
        }
    }
    int ans = 0;
    for (int j = 0; j <= b; ++j) {
        ans += dp[j] * (int64_t) dpx[b - j] % MOD * comb(a + b, b - j) % MOD;
        ans %= MOD;
    }
    // ans = ans * (int64_t) fact[a + b] % MOD * fact[a + b] % MOD;
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << '\n';

}