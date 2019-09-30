#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>

using namespace std;

#define PB push_back
#define MP make_pair

int tt, n, m, f[520][520], ma[520][520], ok[520][520], tot, fx[1000000], fy[1000000], hax[1000000], hay[1000000], all;
char ch;
int main()
    {
        freopen("C-large.in", "r", stdin);
        freopen("C-large.out", "w", stdout);
//        freopen("in.txt", "r", stdin);
  //      freopen("out.txt", "w", stdout);
        cin >> tt;
        for (int ca = 1; ca <= tt; ca++)
            {
                cin >> m >> n;
                int bi = min(n, m);
                for (int i = 0; i < m; i++)
                    {
                        cin >> ch;
                        for (int j = 0; j < n / 4; j++)
                            {
                                int a1;
                                if ('0' <= ch && ch <= '9')
                                    a1 = (int)(ch - '0');
                                else
                                    a1 = (int)(ch - 'A') + 10;
                                for (int k = 3; k >= 0; k--)
                                    if (a1 & (1 << k))
                                        ma[i][j * 4 + (3 - k)] = 1;
                                    else
                                        ma[i][j * 4 + (3 - k)] = 0;
                                ch = getchar();
                            }
                    }
                all = 0;
                for (int le = bi; le > 1; le--)
                    {
                        tot = 0;
                        memset(f, 0, sizeof(f));
                        memset(ok, 0, sizeof(ok));
                        for (int i = 0; i < m; i++)
                            {
                                f[i][0] = 0;
                                if (ma[i][0] != 2)
                                    ok[i][0] = 1;
                                else
                                    ok[i][0] = 0;
                                for (int j = 1; j < n; j++)
                                    {
                                        if (ma[i][j] == 2)
                                            {
                                                ok[i][j] = 0;
                                                f[i][j] = 0;
                                                continue;
                                            }
                                        if (ma[i][j] != ma[i][j - 1])
                                            ok[i][j] = ok[i][j - 1] + 1;
                                        else
                                            ok[i][j] = 1;
                                        if (ok[i][j] >= le)
                                            {
                                                if (i && ma[i][j] != ma[i - 1][j])
                                                    f[i][j] = f[i - 1][j] + 1;
                                                else
                                                    f[i][j] = 1;
                                            }
                                        else
                                            f[i][j] = 0;
                                        if (f[i][j] == le)
                                            {
                                                tot++;
                                                fx[tot] = i;
                                                fy[tot] = j;
                                                ok[i][j] = 0;
                                                for (int k = 0; k < le; k++)
                                                    f[i][j - k] = 0;
                                            }
                                    }
                            }
                        if (tot)
                            {
                                all++;
                                hax[all] = le;
                                hay[all] = tot;
                                for (int i = 1; i <= tot; i++)
                                    for (int x = 0; x < le; x++)
                                        for (int y = 0; y < le; y++)
                                            ma[fx[i] - x][fy[i] - y] = 2;
                            }
                    }
                int cou = 0;
                for (int i = 0; i < m; i++)
                    for (int j = 0; j < n; j++)
                        if (ma[i][j] != 2)
                            cou++;
                if (cou)
                    {
                        all++;
                        hax[all] = 1;
                        hay[all] = cou;
                    }
                printf("Case #%d: %d\n", ca, all);
                for (int i = 1; i <= all; i++)
                    printf("%d %d\n", hax[i], hay[i]);
            }
    }
