#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 100000;
long long x[N], y[N];
int n;

void gen(long long A, long long B, long long C, long long D, long long x0, long long y0, long long M)
{
    long long X = x0, Y = y0;
    x[0] = X, y[0] = Y;
    for (int i = 1; i < n; ++i)
    {
      X = (A * X + B) % M;
      Y = (C * Y + D) % M;
      x[i] = X;
      y[i] = Y;
    }
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int cc = 1; cc <= TC; ++cc)
    {
        {
            long long A, B, C, D, x0, y0, M;
            cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
            gen(A, B, C, D, x0, y0, M);
        }
        for (int i = 0; i < n; ++i)
                x[i] %= 3, y[i] %= 3;
        long long d[3][3];
        memset(d, 0, sizeof(d));
        for (int i = 0; i < n; ++i)
        {
            d[x[i]][y[i]]++;
        }
        long long res = 0;
        for (int x1 = 0; x1 < 3; ++x1)
        for (int y1 = 0; y1 < 3; ++y1)
        for (int x2 = 0; x2 < 3; ++x2)
        for (int y2 = 0; y2 < 3; ++y2)
        for (int x3 = 0; x3 < 3; ++x3)
        for (int y3 = 0; y3 < 3; ++y3)
        {
            long long c1 = d[x1][y1];
            long long c2 = d[x2][y2]; if (x2==x1 && y2==y1) c2--;
            long long c3 = d[x3][y3]; if (x3==x1 && y3==y1) c3--; if (x3==x2 && y3==y2) c3--;
            if (c3 < 0) c3 = 0;
            if (c2 < 0) c2 = 0;
            if ((x1 + x2 + x3) % 3 == 0 &&
                (y1 + y2 + y3) % 3 == 0)
                res += c1 * c2 * c3;
        }

        printf("Case #%d: %I64d\n", cc, res / 6);
    }
    return 0;
}
