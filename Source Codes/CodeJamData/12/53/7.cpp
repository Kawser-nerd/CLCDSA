#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long llint;

const int MAXN = 218;
const llint INF = 1000000007LL * 2000000007LL;

vector<pair<llint, llint> > v;

llint add(llint a, llint b) {
    return min(INF, a + b);
}

llint mul(llint a, llint b) {
    if (b == 0) {
        return 0;
    } else if (a > INF / b) {
        return INF;
    } else {
        return min(INF, a * b);
    }
}

llint eval(llint d) {
    llint pre = 0, ret = 0;
    for (const auto p: v) {
        llint cur = min(p.second, d);
        if (pre < cur) {
            ret = add(ret, mul(p.first, cur - pre));
            pre = cur;
        }
    }
    return pre == d ? ret : INF;
}

llint eval(llint d, llint t, llint m) {
    llint d0 = d / m;
    llint d1 = d0 + 1;
    llint c1 = d % m;
    llint c0 = m - c1;
    return add(
        mul(c0, add(t, eval(d0))),
        mul(c1, add(t, eval(d1))));
}

llint gao(llint d, llint t) {
    llint l, r, m1, m2;
    llint ret = INF;
    l = 1;
    r = d;
    while (r - l >= 5) {
        // printf("%lld %lld\n", l, r);
        m1 = (l + l + r) / 3;
        m2 = (l + r + r) / 3;
        if (eval(d, t, m1) <= eval(d, t, m2)) {
            r = m2;
        } else {
            l = m1;
        }
    }
    // puts("-");
    // fflush(stdout);
    for (llint i = l; i <= r; ++i) {
        // printf("do %d\n", i);
        // fflush(stdout);
        ret = min(ret, eval(d, t, i));
    }
    // puts("--");
    // fflush(stdout);
    return ret;
}

int main() {
    int re, n;
    llint s, t, l, r, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%lld%lld%d", &s, &t, &n);
        v.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld%lld", &v[i].first, &v[i].second);
            ++v[i].second;
        }
        sort(v.begin(), v.end(), [](const pair<llint, llint>& lhs, const pair<llint, llint>& rhs) {
                return lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first);
            });
        n = 1;
        for (int i = 1; i < (int)v.size(); ++i) {
            if (v[i].first < v[n - 1].first) {
                v[n++] = v[i];
            }
        }
        v.resize(n);
        reverse(v.begin(), v.end());

        l = 1;
        r = s + 1;
        while (l < r) {
            m = (l + r) / 2;
            llint cmp = gao(m, t);
            fprintf(stderr, "%lld %lld: %lld => %lld\n", l, r, m, cmp);
            if (cmp <= s) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        printf("Case #%d: %lld\n", ri, r - 1);
        fflush(stdout);
    }

    return 0;
}

