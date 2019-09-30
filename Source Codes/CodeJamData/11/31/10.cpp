#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const int size = 100;
char buf[size][size];
int n, m;

void process()
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (buf[i][j] == '#' && buf[i][j + 1] == '#' && buf[i + 1][j] == '#' && buf[i + 1][j + 1] == '#')
            {
                buf[i][j] = '/';
                buf[i][j + 1] = '\\';
                buf[i + 1][j] = '\\';
                buf[i + 1][j + 1] = '/';
            }
}

bool check()
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (buf[i][j] == '#')
                return false;
    return true;
}

int main()
{
    int i, j, tc, t;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &tc);
    for (t = 0; t < tc; t++)
    {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
            scanf("%s", buf[i]);
        for (i = 0; i <= n; i++)
            buf[i][m] = '@';
        for (i = 0; i <= m; i++)
            buf[n][i] = '@';
        process();
        printf("Case #%d:\n", t + 1);
        if (!check())
            printf("Impossible\n");
        else
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < m; j++)
                    printf("%c", buf[i][j]);
                printf("\n");
            }
    }

    return 0;
}
