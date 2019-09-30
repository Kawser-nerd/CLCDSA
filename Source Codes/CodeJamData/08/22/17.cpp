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

const int N = 1000001;

int rep[N];
int c[N];
int nx[N];
int n;
bool np[N];

int res;
void join(int x, int y)
{
    int rx, ry;
    rx = rep[x], ry = rep[y];
    if (rx == ry) return;
    if (c[rx] < c[ry])
    {
        swap(rx, ry);
        swap(x, y);
    }
    int h = nx[ry];
    while (h != ry)
    {
        rep[h] = rx;
        h = nx[h];
    }
    rep[ry] = rx;
    c[rx] += c[ry];
    res --;
    swap(nx[rx], nx[ry]);
}

int main()
{
    for (int k = 2; k*k < N; ++k)
    {
        if (!np[k])
        {
            for (int j = k * k; j < N; j += k)
                np[j] = true;
        }
    }
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for (int cc = 1; cc <= TC; ++cc)
    {
        //cerr << cc << endl;
        long long A, B, P;
        cin >> A >> B >> P;
        n = int (B - A + 1);
        cerr << n << endl;
        for (int i = 0; i < n; ++i)
            rep[i] = i, c[i] = 1, nx[i] = i;
        
        res = n;
        if (P < n)
        {
            for (int p = 2; p < n; ++p)
                if (!np[p] && p >= P)
                {
                    int x = (p - A % p) % p;
                    int y = x + p;
                    while (y < n)
                    {
                        join(x, y);
                        x += p;
                        y += p;
                    }
                }

        }
        printf("Case #%d: %d\n", cc, res);
    }
    return 0;
}
