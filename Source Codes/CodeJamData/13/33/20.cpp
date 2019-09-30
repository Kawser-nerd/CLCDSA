#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
const int maxn = 1000000 + 100;

struct Attack {
    int day, west, east, s;
    Attack(int _day, int _west, int _east, int _s): day(_day), west(_west), east(_east), s(_s) {}
    bool operator < (const Attack &a) const {
        return day < a.day;
    }
};

vector<Attack> att;
vector<int> v;
int a[maxn * 8], delay[maxn * 8];
int n;

void discretize(vector<int> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < SZ(att); ++i) {
        att[i].west = lower_bound(v.begin(), v.end(), att[i].west) - v.begin();
        att[i].east = lower_bound(v.begin(), v.end(), att[i].east) - v.begin();
    }
}

void pushUp(int n, int l, int r) {
    a[n] = min(a[n * 2], a[n * 2 + 1]);
}

void pushDown(int n, int l, int r) {
    if (delay[n]) {
        a[n * 2] = max(a[n * 2], delay[n]);
        delay[n * 2] = max(delay[n * 2], delay[n]);
        a[n * 2 + 1] = max(a[n * 2 + 1], delay[n]);
        delay[n * 2 + 1] = max(delay[n * 2 + 1], delay[n]);
        delay[n] = 0;
    }
}

void update(int n, int l, int r, int ll, int rr, int s) {
    if (r <= ll || rr <= l) return;
    if (ll <= l && r <= rr) {
        a[n] = max(a[n], s);
        delay[n] = max(delay[n], s);
        return;
    }
    pushDown(n, l, r);
    int mid = (l + r) / 2;
    update(n * 2, l, mid, ll, rr, s);
    update(n * 2 + 1, mid, r, ll, rr, s);
    pushUp(n, l, r);
}

bool succeed(int n, int l, int r, int ll, int rr, int s) {
    if (r <= ll || rr <= l) return false;
    if (ll <= l && r <= rr) {
        return s > a[n];
    }
    pushDown(n, l, r);
    int mid = (l + r) / 2;
    return succeed(n * 2, l, mid, ll, rr, s) || succeed(n * 2 + 1, mid, r, ll, rr, s);
}

int main() {
    freopen("c.out", "w", stdout);
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case #%d: ", ++ca);
        scanf("%d", &n);
        v.clear();
        att.clear();
        for (int i = 0; i < n; ++i) {
            int d, m, w, e, s, dd, dp, ds;
            scanf("%d%d%d%d%d", &d, &m, &w, &e, &s);
            scanf("%d%d%d", &dd, &dp, &ds);
            for (int j = 0; j < m; ++j) {
                v.push_back(w);
                v.push_back(e);
                att.push_back(Attack(d, w, e, s));
                d += dd;
                w += dp;
                e += dp;
                s += ds;
            }
        }
        discretize(v);
        sort(att.begin(), att.end());
        memset(a, 0, sizeof(a[0]) * (SZ(v) * 4));
        memset(delay, 0, sizeof(delay[0]) * (SZ(v) * 4));
        int prev = 0, ans = 0;
        for (int i = 0; i < SZ(att); ++i) {
            //printf("day: %d west: %d east: %d strength: %d\n", att[i].day, v[att[i].west], v[att[i].east], att[i].s);
            while (att[prev].day < att[i].day) {
                update(1, 0, SZ(v) - 1, att[prev].west, att[prev].east, att[prev].s);
                ++prev;
            }
            if (succeed(1, 0, SZ(v) - 1, att[i].west, att[i].east, att[i].s)) {
                //printf("suceeded\n");
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

