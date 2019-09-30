#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int N_MAX = 5005, INF = 1000000005;

struct point
{
    int x, y;

    point (int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }

    point operator + (const point &p) const
    {
        return point(x + p.x, y + p.y);
    }

    point operator - (const point &p) const
    {
        return point(x - p.x, y - p.y);
    }

    point rotate90(const point &p) const
    {
        point diff = (*this) - p;
        diff = point(diff.y, -diff.x);
        return p + diff;
    }

    bool operator < (const point &p) const
    {
        if (x != p.x)
            return x < p.x;

        return y < p.y;
    }

    double abs() const
    {
        return sqrt((double) x * x + (double) y * y);
    }

    double norm() const
    {
        return (double) x * x + (double) y * y;
    }
};

const point ORIGIN = point(0, 0);

int N, M, F;
double best;
point stars[N_MAX];
point rotations[4][N_MAX], full[4 * N_MAX];

int cross(point a, point b)
{
    return a.x * b.y - b.x * a.y;
}

int dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

bool left_turn(point a, point b, point c)
{
    return cross(b - a, c - a) > 0;
}

bool is_origin(point p)
{
    return p.x == 0 && p.y == 0;
}

bool compare_angle(point a, point b)
{
    if (is_origin(a))
        return false;

    if (is_origin(b))
        return true;

    bool a_upper = a.y > 0 || (a.y == 0 && a.x > 0);
    bool b_upper = b.y > 0 || (b.y == 0 && b.x > 0);

    if (a_upper ^ b_upper)
        return a_upper;

    return cross(a, b) > 0;
}

void initialize()
{

}

double get_dist(double x, double y)
{
    return sqrt(x * x + y * y);
}

void test(point p)
{
    double x = 0, y = 0;
    vector<point> ideal;

    for (int d = 0; d < 4; d++)
    {
        int count = (M + 3 - d) / 4;
        int high = -1, high_dot = -INF;

        for (int i = 0; i < N; i++)
        {
            int dp = dot(p, rotations[d][i]);

            if (dp > high_dot)
            {
                high = i;
                high_dot = dp;
            }
        }

        ideal.push_back(rotations[d][high]);

        x += (double) count * rotations[d][high].x;
        y += (double) count * rotations[d][high].y;
    }

    best = max(best, get_dist(x, y));

    for (int m = M - 1, it = 0; m >= 0 && it < 10; m--, it++)
    {
        x -= ideal[m % 4].x;
        y -= ideal[m % 4].y;
        best = max(best, get_dist(x, y));
    }

    x = 0;
    y = 0;

    for (int m = 0, it = 0; m < M && it < 10; m++, it++)
    {
        x += ideal[m % 4].x;
        y += ideal[m % 4].y;
        best = max(best, get_dist(x, y));
    }
}

void solve_case(int test_case)
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &stars[i].x, &stars[i].y);
        stars[i] = ORIGIN.rotate90(stars[i]);
    }

    F = 0;

    for (int i = 0; i < N; i++)
    {
        rotations[0][i] = stars[i];
        rotations[1][i] = rotations[0][i].rotate90(ORIGIN);
        rotations[2][i] = rotations[1][i].rotate90(ORIGIN);
        rotations[3][i] = rotations[2][i].rotate90(ORIGIN);

        for (int j = 0; j < 4; j++)
            full[F++] = rotations[j][i];
    }

    sort(full, full + F, compare_angle);

    while (F > 0 && is_origin(full[F - 1]))
        F--;

    best = 0;

    for (int i = 0; i < F; i++)
        test(full[i]);

    for (int i = 0; i < F; i++)
        test(full[i] + full[(i + 1) % F]);

    printf("Case #%d: %.9lf\n", test_case, best);
}

int main()
{
    initialize();
    int T; scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        solve_case(tc);
        fflush(stdout);
    }

    return 0;
}
