#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

const double INFF = 1e12;
const double EPS = 1e-9; // !!!
const double PI = acos(-1);

// sign
int sgn(double r) {
    return (r < -EPS) ? -1 : (r > +EPS) ? +1 : 0;
}

// 2D point
struct Pt {
    double x, y;
    Pt(double x = 0, double y = 0) : x(x), y(y) { }
    Pt operator + (const Pt& o) const { return Pt(x + o.x, y + o.y); }
    Pt operator - (const Pt& o) const { return Pt(x - o.x, y - o.y); }
    Pt operator * (const double k) const { return Pt(k*x, k*y); }
    Pt operator / (const double k) const { return Pt(x/k, y/k); }
    double dot(const Pt& o) const { return x*o.x + y*o.y; }
    double det(const Pt& o) const { return x*o.y - o.x*y; }
    double abs2() const { return x*x + y*y; }
    double abs() const { return sqrt(abs2()); }
    double angle() const { return atan2(y, x); }
    Pt rot(const double t) const { return Pt(x*cos(t) - y*sin(t), x*sin(t) + y*cos(t)); }
    Pt rot90() const { return Pt(-y, x); }
    bool operator < (const Pt& o) const { return x != o.x ? x < o.x : y < o.y; }
    bool operator == (const Pt& o) const { return sgn(x - o.x) == 0 && sgn(y - o.y) == 0; }
};
ostream& operator << (ostream& os, const Pt& p) { os << "(" << p.x << ", " << p.y << ")"; return os; }

// 2 * (signed area of a triangle)
double tri(Pt a, Pt b, Pt c)
{
    return (b - a).det(c - a);
}

int iSP(Pt a, Pt b, Pt c)
{
    int cross = sgn(tri(a, b, c));
    if (cross != 0) return cross; // 1: counter clockwise, -1: clockwise
    if (sgn((b - a).dot(c - a)) < 0) return -2; // c-a-b
    if ((b - a).abs2() < (c - a).abs2()) return +2; // a-b-c
    return 0;
}

pair<int, int> convex_hull(int n, Pt p[], Pt lo[], Pt up[])
{
    int m = 0, k = 0, i;
    sort(p, p + n);
    for (i = 0;     i <  n; lo[m++] = p[i++]) for (; m > 1 && iSP(lo[m - 2], lo[m - 1], p[i]) < 0; --m) ;
    for (i = n - 1; i >= 0; up[k++] = p[i--]) for (; k > 1 && iSP(up[k - 2], up[k - 1], p[i]) < 0; --k) ;
    return make_pair(m, k);
}

int convex_hull(int n, Pt p[], Pt q[])
{
    int m = 0, i, r;
    sort(p, p + n);
    for (i = 0;            i <  n; q[m++] = p[i++]) for (; m > 1 && sgn(tri(q[m - 2], q[m - 1], p[i])) <= 0; --m) ;
    for (i = n - 2, r = m; i >= 0; q[m++] = p[i--]) for (; m > r && sgn(tri(q[m - 2], q[m - 1], p[i])) <= 0; --m) ;
    return m - 1;
}

vector<Pt> getPolygon(int n, Pt p[], int m, Pt base[])
{
    Pt rem[1024];
    int rc = 0;
    for (int i = 0; i < n; ++i) {
        bool in_ch = false;
        for (int j = 0; !in_ch && j < m; ++j) {
            in_ch |= p[i] == base[j];
        }
        if (!in_ch) {
            rem[rc++] = p[i];
        }
    }

    sort(rem, rem + rc);
    vector<Pt> res;
    for (int i = 0; i < m; ++i) {
        res.push_back(base[m - i - 1]);
    }
    for (int i = 0; i < rc; ++i) {
        res.push_back(rem[i]);
    }
    return res;
}

double getArea(vector<Pt> poly)
{
    const int n = poly.size();
    double res = 0;
    for (int i = 0; i < n; ++i) {
        res += poly[i].det(poly[(i + 1) % n]);
    }
    return fabs(res) / 2;
}

int main()
{
    int T;
    cin >> T;

    for (int CN = 1; CN <= T; ++CN) {
        int N;
        Pt I[1024], P[1024];
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> P[i].x >> P[i].y;
        }
        memcpy(I, P, sizeof(P));

        Pt hull[1024];
        int M = convex_hull(N, P, hull);
        double A = 0;
        for (int i = 0; i < M; ++i) {
            A += hull[i].det(hull[(i+1) % M]);
        }
        A = fabs(A) / 2;

        Pt lo[1024], up[1024];
        pair<int, int> ps = convex_hull(N, P, lo, up);

        vector<Pt> los, ups;
        los = getPolygon(N, P, ps.first, lo);
        for (int i = 0; i < ps.second; ++i) {
            up[i] = up[i] * -1;
        }
        for (int i = 0; i < N; ++i) {
            P[i] = P[i] * -1;
        }
        ups = getPolygon(N, P, ps.second, up);
        for (int i = 0; i < ups.size(); ++i) {
            ups[i] = ups[i] * -1;
        }

        double loa = getArea(los), upa = getArea(ups);
        vector<Pt> sol = loa > upa ? los : ups;

        cout << "Case #" << CN << ":";
        for (int i = 0; i < sol.size(); ++i) {
            for (int j = 0; j < N; ++j) {
                if (sol[i] == I[j]) {
                    cout << " " << j;
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
