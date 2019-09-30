#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <stack>

using namespace std;

//#define ZTDebug
#ifdef ZTDebug
#define In scanf_s
#else
#define In scanf
#endif // ZTDebug

#define Ind(d) In("%d", &d)
#define Ind2(a, b) In("%d%d", &a, &b)
#define InD(d) int d; In("%d", &d);
#define InD2(a, b) int a, b; In("%d%d", &a, &b);
#define InDN(n, v) for (auto _i = 0; _i < n; ++_i) In("%d", &v[_i]);
#define OutDNLine(n, v) for (auto _i = 0; _i < n; ++_i) printf("%d%c", *(v + _i), _i + 1 == n ? '\n' : ' ');

typedef double db;
typedef long long LL;
typedef pair<int, int> pii;

const int Max = 100010;

int r, c, rd;

int toP(int x, int y) {
    if (y == 0) return x;
    if (x == r) return r + y;
    if (y == c) return r + c + r - x;
    if (x == 0) return rd - y;
    return -1;
}
int getP() { int x, y; cin >> x >> y; return toP(x, y); }

vector<pii> ps;
int turnP(int d, int x) {
    auto nx = x - d;
    if (nx < 0) return rd + nx;
}
bool test(int d) {
    vector<pii> cur;
    auto cnt = 0;
    for (auto p : ps) {
        auto q1 = turnP(d, p.first), q2 = turnP(d, p.second);
        if (q1 > q2) swap(q1, q2);
        ++cnt;
        cur.push_back(make_pair(q1, cnt));
        cur.push_back(make_pair(q2, -cnt));
    }
    sort(cur.begin(), cur.end());

#ifdef ZTDebug
    cout << "test " << d << endl;
    for (auto p : cur) cout << p.first << "," << p.second << " "; cout << endl;
#endif // ZTDebug

    stack<int> st;
    for (auto p : cur) {
        auto i = p.second;
        if (i < 0) {
            if (st.top() != -i) return false;
            st.pop();
        }
        else {
            st.push(i);
        }
    }
    return true;
}

int main() {
#ifdef ZTDebug
    while (true) {
#endif // ZTDebug
        int n;
        cin >> r >> c >> n;
        rd = r + c + r + c;

        ps.clear();
        for (auto i = 0; i < n; ++i) {
            auto p1 = getP(), p2 = getP();
            if (p1 != -1 && p2 != -1) ps.push_back(make_pair(p1, p2));
        }

#ifdef ZTDebug
        for (auto p : ps) cout << p.first << "," << p.second << " "; cout << endl;
#endif // ZTDebug

        int x[] = { 0, r, r + c, r + c + r };
        auto succ = false;
        for (auto d : x) if (test(d)) { succ = true; break; }
        cout << (succ ? "YES" : "NO") << endl;
#ifdef ZTDebug
    }
#endif // ZTDebug
    return 0;
} ./Main.cpp:48:1: warning: control may reach end of non-void function [-Wreturn-type]
}
^
1 warning generated.