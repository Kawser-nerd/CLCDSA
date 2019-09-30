#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

struct Attack {
    int day;
    int strength;
    int l, r;
};

bool operator < (const Attack& a, const Attack& b) {
    return a.day < b.day;
}

int rescale(vector<Attack>& v) {
    map<int, int> coords;
    FORE (it, v) {
        coords[it->l] = coords[it->r]= 0;
    }
    int c = 0;
    FORE (it, coords) {
        it->ND = ++c;
    }
    FORE (it, v) {
        it->l = coords[it->l] * 2;
        it->r = coords[it->r] * 2;
    }
    return c * 2;
}

int t[10300005];
int ch[10300005];
int z;

inline int ls(int x) { return x << 1; }
inline int rs(int x) { return (x << 1) + 1; }

void pushd(int x) {
    ch[ls(x)] = max(ch[ls(x)], ch[x]);
    t[ls(x)] = max(t[ls(x)], ch[x]);
    ch[rs(x)] = max(ch[rs(x)], ch[x]);
    t[rs(x)] = max(t[rs(x)], ch[x]);
    ch[x] = 0;
}

void upd(int x) {
    t[x] = min(t[ls(x)], t[rs(x)]);
}

void imp(int x, int l, int r, int cl, int cr, int v) {
    if (cl == l && cr == r) {
        ch[x] = max(ch[x], v);
        t[x] = max(t[x], v);
        return;
    }
    pushd(x);
    int m = (l + r) / 2;
    if (cl <= m) {
        imp(ls(x), l, m, cl, min(m, cr), v);
    }
    if (cr > m) {
        imp(rs(x), m + 1, r, max(m + 1, cl), cr, v);
    }
    upd(x);
}

int get(int x, int l, int r, int cl, int cr) {
    if (cl == l && cr == r) {
        return t[x];
    }
    pushd(x);
    int m = (l + r) / 2;
    int res = (int) 2e9;
    if (cl <= m) {
        res = min(res, get(ls(x), l, m, cl, min(m, cr)));
    }
    if (cr > m) {
        res = min(res, get(rs(x), m + 1, r, max(m + 1, cl), cr));
    }
    return res;
}

int alg() {
    int n;
    cin >> n;
    vector<Attack> v;
    for (int i = 0; i < n; ++i) {
        int d, nn, w, e, s, delta_d, delta_p, delta_s;
        cin >> d >> nn >> w >> e >> s >> delta_d >> delta_p >> delta_s;
        for (int j = 0; j < nn; ++j) {
            Attack a;
            a.day = d;
            a.strength = s;
            a.l = w;
            a.r = e;
            v.PB(a);
            d += delta_d;
            e += delta_p;
            w += delta_p;
            s += delta_s;
        }
    }
    int m = rescale(v);
    sort(ALL(v));
    int z = 1;
    while (z <= m) {
        z *= 2;
    }
    assert((int) (sizeof(t) / sizeof(int)) > 2 * z + 5);
    ZERO(t);
    ZERO(ch);
    vector<Attack> waiting;
    int res = 0;
    FORE (it, v) {
        if (!waiting.empty() && waiting.back().day < it->day) {
            FORE (jt, waiting) {
                imp(1, 1, z, jt->l, jt->r, jt->strength);
            }
            waiting.clear();
        }
        if (get(1, 1, z, it->l, it->r) < it->strength) {
            ++res;
        }
        waiting.PB(*it);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int d;
    cin >> d;
    for (int i = 1; i <= d; ++i) {
        cout << "Case #" << i << ": " << alg() << endl;
    }
}
