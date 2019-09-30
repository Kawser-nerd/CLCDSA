#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdint>

constexpr int MOD=1e9+7;

std::vector<int> factors_of(int64_t n) {
    std::vector<int> res;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            res.emplace_back(i);
            n /= i;
            while (n % i == 0) n /= i;
        }

    if (n > 1) res.emplace_back(n);

    return res;
}

std::vector<int> divisors_of(int n) {
    if (n == 1)
        return {1};

    std::vector<int> res{1, n};
    {
        int i;
        for (i=2; i*i<n; ++i)
            if (n % i == 0) {
                res.emplace_back(i);
                res.emplace_back(n/i);
            }

        if (i * i == n)
            res.emplace_back(i);
    }

    return res;
}

inline int modsum_aseq(int a, int n, int d, int mod) {
    // Returns the sum (modulo mod) of the n-term arithmetic sequence
    // whose first term is a and common difference is d

    return ((n*(2LL*a+(n-1LL)*d))>>1) % mod;
}

int64_t modsum_coprimes(int N, int K, int64_t mod) {
    // Returns the sum (modulo mod) of integers from one to N,
    // each of which is co-prime to K

    std::vector<int> facs=factors_of(K);
    size_t n=facs.size(), pn=(1<<n);

    int res=0;
    for (int i=0; i<pn; ++i) {
        int div=1;
        bool neg=false;
        for (size_t j=0; j<n; ++j)
            if (i>>j & 1) {
                div *= facs[j];
                neg ^= true;
            }

        if (N < div) continue;

        int cur=modsum_aseq(div, (N-div)/div+1, div, mod);
        if (neg)
            cur = mod - cur;

        res = (res+cur) % mod;
    }

    return res;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    std::vector<int> divs=divisors_of(K);
    int res=0;
    for (int d: divs)
        (res += modsum_coprimes(N/d, K/d, MOD)*K % MOD) %= MOD;

    printf("%d\n", res);
    return 0;
}