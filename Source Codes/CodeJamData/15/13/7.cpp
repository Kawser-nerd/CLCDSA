#include <vector>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long TYPE;
const TYPE EPS = 0;

inline int sgn(TYPE a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }
inline int cmp(TYPE a, TYPE b) { return sgn(a - b); }

struct pt {
    TYPE x, y;
    pt(TYPE x = 0, TYPE y = 0) : x(x), y(y) { }

    bool operator==(pt p) { return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
    bool operator<(pt p) const {
        return cmp(x, p.x) ? cmp(x, p.x) < 0 : cmp(y, p.y) < 0;
    }
    bool operator<=(pt p) { return *this < p || *this == p; }
    TYPE operator||(pt p) { return x*p.x + y*p.y; }
    TYPE operator%(pt p) { return x*p.y - y*p.x; }
    pt operator~() { return pt(x, -y); }
    pt operator+(pt p) { return pt(x + p.x, y + p.y); }
    pt operator-(pt p) { return pt(x - p.x, y - p.y); }
    pt operator*(pt p) { return pt(x*p.x - y*p.y, x*p.y + y*p.x); }
    pt operator/(TYPE t) { return pt(x/t, y/t); }
    pt operator/(pt p) { return (*this * ~p)/(p||p); }
};
const pt I = pt(0,1);

struct circle {
    pt c; TYPE r;
    circle(pt c, TYPE r) : c(c), r(r) { }
};

TYPE norm(pt a) { return a||a; }
TYPE area(pt a, pt b, pt c) { return (a-c)%(b-c); }
int ccw(pt a, pt b, pt c) { return sgn(area(a, b, c)); }

int main() {
    int T;
    cin >> T;

    for (int z = 1; z <= T; z++) {
        int N;
        cin >> N;

        vector<pt> pts;
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            pts.push_back(pt(x, y));
        }

        cout << "Case #" << z << ":" << endl;
        for (int i = 0; i < N; i++) {
            int best = 0x3f3f3f3f;

            for (int j = 0; j < N; j++) {
                if (j == i) continue;
                int cur = 0;

                for (int k = 0; k < N; k++)
                    if (ccw(pts[i], pts[j], pts[k]) < 0) {
                        cur++;
                        if (cur >= best)
                            break;
                    }

                best = min(best, cur);
            }

            if (N == 1)
                best = 0;
            cout << best << endl;
        }
    }
}
