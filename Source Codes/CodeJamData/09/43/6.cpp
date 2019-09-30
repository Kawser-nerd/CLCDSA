#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <ctime>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define NMAX 105

int n, k;
int pr[NMAX][NMAX];
bool g[NMAX][NMAX];
bool used[NMAX];
int match[NMAX];

bool kuhn(int v)
{
    if (used[v]) return false;
    used[v] = true;

    forn(i, n)
    {
        if (!g[v][i]) continue;

        if (match[i] == -1 || kuhn(match[i]))
        {
            match[i] = v;
            return true;
        }
    }

    return false;   
}

void solve(int tc)
{
    printf("Case #%d: ", tc);

    cin >> n >> k;

    forn(i, n)
    {
        forn(j, k)
        {
            cin >> pr[i][j];
        }
    }

    forn(i, n)
    {
        forn(j, n)
        {
            if (i == j) continue;

            g[i][j] = true;

            forn(t, k)
            {
                if (pr[i][t] >= pr[j][t])
                {
                    g[i][j] = false;
                    break;
                }
            }
        }
    }

    forn(i, n) match[i] = -1;

    int size = 0;

    forn(i, n)
    {
        memset(used, 0, sizeof(used));
        if (kuhn(i)) ++size;
    }

    cout << n - size << endl;
}

int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}
            
