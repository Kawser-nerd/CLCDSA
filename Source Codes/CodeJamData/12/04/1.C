// -*- c-basic-offset: 4 -*-
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<climits>
#include<set>
#include<fstream>
#include<iostream>
#include<bitset>
#include<cassert>
#include<climits>
#include<vector>
#include<queue>
#include<string>

using namespace std;

long H, W, D;
char map[30][31];

long gcd(long x, long y)
{
    assert(x >= 0);
    assert(y >= 0);
    if(x == 0) return y;
    if(x > y) return gcd(y, x);
    return gcd(y % x, x);
}

struct Rational {
    Rational(long _n, long _d) {
        assert(_d != 0);
        long g = gcd(_n > 0 ? _n : -_n, _d > 0 ? _d : -_d);
        num = _n / g;
        den = _d / g;
        if(den < 0) {
            num = -num;
            den = -den;
        }
    }
    bool operator<(const Rational &a)const {
        return num * a.den < den * a.num;
    }
    bool operator>(const Rational &a)const {
        return num * a.den > den * a.num;
    }
    bool operator<=(const Rational &a)const {
        return num * a.den <= den * a.num;
    }
    bool operator==(const Rational &a)const {
        return num * a.den == den * a.num;
    }
    void operator+=(const Rational &a) {
        long nw = num * a.den + den * a.num;
        long dw = den * a.den;
        long g = gcd(nw, dw);
        num = nw / g;
        den = dw / g;
    }

    long num;
    long den;
};

struct Light {
    Rational x;
    Rational y;

    long dx, dy;
    Rational t;
};

Rational x0(0, 1);
Rational y0(0, 1);
const Rational inf(1000000, 1);
const Rational zero(0, 1);

void find_initial(void)
{
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            if(map[i][j] == 'X') {
                x0 = Rational(2 * i + 1, 2);
                y0 = Rational(2 * j + 1, 2);
                return;
            }
        }
    }
}

// return false if destroyed
bool reflect(Light &l, const Rational &xwall, const Rational &ywall)
{
    int x = l.x.num / l.x.den;
    int y = l.y.num / l.y.den;
    if(l.dx > 0 && l.x.num % l.x.den == 0) --x;
    if(l.dy > 0 && l.y.num % l.y.den == 0) --y;

    assert(map[x][y] != '#');

    if(xwall < ywall) {
        if(l.dx > 0 && map[x + 1][y] == '#'
           || l.dx < 0 && map[x - 1][y] == '#')
            l.dx = -l.dx;
        return true;
    }else if(ywall < xwall) {
        if(l.dy > 0 && map[x][y + 1] == '#'
           || l.dy < 0 && map[x][y - 1] == '#')
            l.dy = -l.dy;
        return true;
    }else {
        int xstep = l.dx > 0 ? 1 : -1;
        int ystep = l.dy > 0 ? 1 : -1;
        if(map[x + xstep][y + ystep] != '#') return true;
        if(map[x + xstep][y] != '#' && map[x][y + ystep] != '#') return false;
        if(map[x + xstep][y] == '#') l.dx = -l.dx;
        if(map[x][y + ystep] == '#') l.dy = -l.dy;
        return true;
    }
}

Rational t_to_next_line_x(Light &l)
{
    if(l.dx == 0) return inf;
    if(l.dx > 0) {
        long xn = (l.x.num / l.x.den + 1) * l.x.den;
        return Rational(xn - l.x.num, l.dx * l.x.den);
    } else {
        long xn = l.x.num / l.x.den * l.x.den;
        if(xn == l.x.num) xn -= l.x.den;
        assert(xn > 0);

        return Rational(l.x.num - xn, -l.dx * l.x.den);
    }
}

Rational t_to_next_line_y(Light &l)
{
    if(l.dy == 0) return inf;
    if(l.dy > 0) {
        long yn = (l.y.num / l.y.den + 1) * l.y.den;
        return Rational(yn - l.y.num, l.dy * l.y.den);
    } else {
        long yn = l.y.num / l.y.den * l.y.den;
        if(yn == l.y.num) yn -= l.y.den;
        assert(yn > 0);

        return Rational(l.y.num - yn, -l.dy * l.y.den);
    }
}

void move(Light &l, const Rational &d)
{
    long xn = l.x.num * d.den + l.dx * d.num * l.x.den;
    long xd = l.x.den * d.den;
    l.x = Rational(xn, xd);

    long yn = l.y.num * d.den + l.dy * d.num * l.y.den;
    long yd = l.y.den * d.den;
    l.y = Rational(yn, yd);

    l.t += d;
}

bool dis_sq(const Light &l)
{
    long num = (l.dx * l.dx + l.dy * l.dy) * l.t.num * l.t.num;
    long den = l.t.den * l.t.den;

    return num <= D * D * den;
}

bool hit(const Light &l, const Rational &xwall, const Rational &ywall)
{
    Rational tx(0, 1), ty(0, 1);
    if(l.dx == 0) {
        ty = Rational(y0.num * l.y.den - y0.den * l.y.num, l.dy * l.y.den * y0.den);
        tx = ty;
    } else if(l.dy == 0) {
        tx = Rational(x0.num * l.x.den - x0.den * l.x.num, l.dx * l.x.den * x0.den);
        ty = tx;
    }else {
        tx = Rational(x0.num * l.x.den - x0.den * l.x.num, l.dx * l.x.den * x0.den);
        ty = Rational(y0.num * l.y.den - y0.den * l.y.num, l.dy * l.y.den * y0.den);
    }

    if(tx == ty) {
        if(tx <= Rational(0, 1)) return false;
        if(tx > xwall || tx > ywall) return false;

        Light tmp = l;
        move(tmp, tx);
        return dis_sq(tmp);
    } else {
        return false;
    }
}

bool test(Light &l)
{
    while(dis_sq(l)) {
        Rational xwall = t_to_next_line_x(l);
        Rational ywall = t_to_next_line_y(l);
        if(hit(l, xwall, ywall)) return true;
        
        move(l, xwall < ywall ? xwall : ywall);
        if(reflect(l, xwall, ywall) == false) return false;
    }
    return false;
}

void do_case(void)
{
    cin >> H >> W >> D;
    for(int i = 0; i < H; ++i) {
        cin >> map[i];
    }
    find_initial();

    unsigned long result = 0;
    for(int dx = -D; dx <= D; ++dx) {
        for(int dy = -D; dy <= D; ++dy) {
            if(dx == 0 && dy == 0) continue;
            if(dx * dx + dy * dy > D * D) continue;
            if(gcd(dx > 0 ? dx : -dx, dy > 0 ? dy : -dy) > 1) continue;

            Light l = {x0, y0, dx, dy, Rational(0, 1)};
            if(test(l)) ++result;
        }
    }
    cout << result << "\n";
}

int main()
{
    freopen("input.data", "r", stdin);
    //freopen("output.data", "r", stdout);

    int cases;
    scanf("%d\n", &cases);
    int i = 1;
    do{
        printf("Case #%d: ", i);
        do_case();
    }while(++i <= cases);

    return 0;
}
