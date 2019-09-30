#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long long ll;

#define NMAX 45

int n;
int a[NMAX][NMAX];
int b[NMAX];

void solve(int test)
{
    printf("Case #%d: ", test);
    scanf("%d\n", &n);

    char c;
    forn(i, n)
    {
        forn(j, n)
        {
            scanf("%c", &c);
            a[i][j] = int(c - '0');
        }
        scanf("\n");
    }

    forn(i, n)
    {
        b[i] = -1;
        forn(j, n)
        {
            if (a[i][j]) b[i] = j;
        }
    }

    int ans = 0;
    forn(i, n)
    {
        for (int j = i; j < n; j++)
        {
            if (b[j] > i) continue;
            for (int k = j; k > i; k--)
            {
                forn(t, n)
                {
                    swap(a[k][t], a[k-1][t]);
                }
                swap(b[k], b[k-1]);
                ans++;
            }
            break;
        }
    }
    cout << ans << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; 
    scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }
    return 0;
}