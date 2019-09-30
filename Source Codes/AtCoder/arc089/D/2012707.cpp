#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

const int MOD = (int)1e9 + 7;
const int kN = 70 + 1;
const int kM = 10000;
int n, k;
char s[kN];
int Inv[kM], F[kM], Finv[kM];

int binom(int a, int b)
{
    if (b < 0 || b > a) return 0;
    return F[a] * 1LL * Finv[b] % MOD * Finv[a - b] % MOD;
}

inline void add(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}

std::vector<int> vec; // ??B???

int getBound(const std::vector<int> &vec)
{
    std::vector<int> used(k);
    int j = 0, pa = 0;
    for (int i = 0; i < k; ++ i) {
        if (s[i] == 'r') {
            if (pa < vec.size())
                used[i] = -1, ++ pa;
        } else if (j < pa) {
            used[i] = 1;
            ++ j;
        }
    }
    if (j != vec.size()) return -1;
    int left[2] = {};
    j = 0;
    for (int i = k - 1; i >= 0; -- i) {
        if (used[i] == 0) {
            left[s[i] == 'b'] ++;
        } else if (used[i] > 0) {
            int c = vec[j ++] - 1;
            for (int w = 1; w >= 0; -- w) {
                int tmp = std::min(left[w], c);
                c -= tmp;
                left[w] -= tmp;
            }
            if (c > 0) return -1;
        }
    }
    return left[0];
}

int calc(const std::vector<int> &vec)
{
    int bound_a = getBound(vec);
    if (bound_a < 0) return 0;
    int ret = 0;
    for (int a = 0; a <= bound_a; ++ a) {
        int segc = vec.size() + a;
        if (segc == 0) {
            add(ret, 1); continue;
        }
        int pre = ret;
        int len = a;
        int hole = 1 + a * 2;
        int ops = a;
        for (int x : vec) len += x * 2 - 1, hole += x * 2 + 1 + 1, ops += x + 1;
        if (ops > k || segc - 1 + len > n) break;
        int coef = F[segc] * 1LL * Finv[a] % MOD;
        for (int i = 0, j = 0; i < vec.size(); i = j ++) {
            while (j < vec.size() && vec[j] == vec[i]) ++ j;
            coef = coef * 1LL * Finv[j - i] % MOD;
        }
        add(ret, binom(n - len - segc + 1 + hole - 1, hole - 1) * 1LL * coef % MOD);
    }
    return ret;
}

int search(int at, int segc, int len, int ops)
{
    int ret = calc(vec);
    if (ret == 0) return 0;
    for (int i = at; ; ++ i) {
        if (k < ops + i + 1 || n < segc + len + i * 2 - 1) break;
        int h = vec.size();
        for (int j = 1; ; ++ j) {
            if (k < ops + (i + 1) * j || n < segc + j - 1 + len + (i * 2 - 1) * j) break;
            vec.emplace_back(i);
            add(ret, search(i + 1, segc + j, len + (i * 2 - 1) * j, ops + (i + 1) * j));
        }
        vec.resize(h);
    }
    return ret;
}

int main()
{
    Inv[1] = 1;
    for (int i = 2; i < kM; ++ i)
        Inv[i] = (MOD - MOD / i) * 1LL * Inv[MOD % i] % MOD;
    F[0] = Finv[0] = 1;
    for (int i = 1; i < kM; ++ i) {
        F[i] = F[i - 1] * 1LL * i % MOD;
        Finv[i] = Finv[i - 1] * 1LL * Inv[i] % MOD;
    }
    scanf("%d%d%s", &n, &k, s);
    printf("%d\n", search(1, 0, 0, 0));
}