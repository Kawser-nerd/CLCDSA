#include "math.h"
#include <algorithm>
#include <complex>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <string>
#include <vector>
#define ifor(i, a, b) for (int i = (a); i < (b); i++)
#define rfor(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long double ld;
typedef long long int lli;
typedef complex<double> P;
const double eps = 1e-11;
int vex[4] = {1, 0, -1, 0};
int vey[4] = {0, 1, 0, -1};
typedef vector<double> Vec;
typedef vector<int> vec;
typedef vector<Vec> MAT;
typedef vector<vec> mat;
lli MOD = 1000000007;
P p1, p2, p3;
double r;
bool jou(P p)
{
    // cout << p.imag() << endl;
    // cout << p.real() << endl;
    //cout << norm(p - p1) << endl;
    return r * r >= norm(p - p1);
}
void show(P p)
{
    cout << "x,y= " << p.real() << ' ' << p.imag() << endl;
}
bool en(P p)
{
    //show(p);
    return p2.real() <= p.real() && p3.real() >= p.real() && p2.imag() <= p.imag() && p3.imag() >= p.imag();
}
int main()
{
    double x, y;
    cin >> x >> y >> r;
    p1 = P(x, y);
    cin >> x >> y;
    p2 = P(x, y);
    cin >> x >> y;
    p3 = P(x, y);
    random_device rnd;
    mt19937 mt(rnd());
    bool flag1 = false, flag2 = false;
    rep(i, 1000000)
    {

        uniform_real_distribution<> rand(-100.0, 100.0);
        auto x = rand(mt);
        auto y = rand(mt);
        flag1 |= (jou(P(x, y)) && !en(P(x, y)));
        flag2 |= (en(P(x, y)) && !jou(P(x, y)));
    }
    rep(i, 1000000)
    {

        uniform_real_distribution<> rand(-10.0, 10.0);
        auto x = rand(mt);
        auto y = rand(mt);
        flag1 |= jou(P(x, y) + p1) && !en(P(x, y) + p1);
        flag2 |= en(P(x, y) + p1) && !jou(P(x, y) + p1);
    }
    rep(i, 1000000)
    {

        uniform_real_distribution<> rand(-r, r);
        auto x = rand(mt);
        auto y = rand(mt);
        flag1 |= jou(P(x, y) + p1) && !en(P(x, y) + p1);
        flag2 |= en(P(x, y) + p1) && !jou(P(x, y) + p1);
    }
    cout << (flag1 ? "YES" : "NO") << endl;
    cout << (flag2 ? "YES" : "NO") << endl;
}