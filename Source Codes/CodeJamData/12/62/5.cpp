#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<long double> p;

long double gao(int n, int m) {
    vector<long double> q;
    // printf("%d %d %d\n", n, m, p.size());
    q.insert(q.end(), p.rbegin(), p.rbegin() + m);
    q.insert(q.end(), p.begin(), p.begin() + (n - m));
    reverse(q.begin() + m, q.end());
    long double ret = 0.0, wake = 1.0, sleep = 0.0;
    for (long double i: q) {
        ret += sleep * i;
        sleep = (wake + sleep) * (1.0 - i);
        wake = wake * i;
    }
    return ret;
}

int main() {
    int re, n, m, l, r, a, b, c;
    long double ans;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%d", &n, &m);
        p.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d/%d %d", &a, &b, &c);
            for (int j = 0; j < c; ++j) {
                p.push_back((long double)a / b);
            }
        }
        sort(p.begin(), p.end());

        l = 0;
        r = m;
        while (r - l > 5) {
            a = (l + l + r) / 3;
            b = (l + r + r) / 3;
            if (gao(m, a) > gao(m, b)) {
                l = a;
            } else {
                r = b;
            }
        }

        ans = 1.0;
        for (int i = l; i <= r; ++i) {
            ans = min(ans, gao(m, i));
        }

        printf("Case #%d: %.10Lf\n", ri, ans);
        fflush(stdout);
    }

    return 0;
}


