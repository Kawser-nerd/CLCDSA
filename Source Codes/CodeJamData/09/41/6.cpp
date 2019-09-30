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

#define NMAX 45

string s[NMAX];
int n;
int p[NMAX];
int l[NMAX];
bool used[NMAX];

int ans;

int start;

int iter;

bool TL;

void rec(int k, int inv)
{
    if (TL) return;
    if (ans <= inv) return;
    if (k == n)
    {
        ans = inv;
    }   

    ++iter;

    if (iter % 100000 == 0)
    {
        if (clock() - start > 30000)
        {
            TL = true;
            return; 
        }
    }

    forn(i, n)
    {
        if (used[i]) continue;

        if (l[i] > k) continue;

        p[k] = i;

        int add = 0;

        forn(j, k)
        {
            if (p[j] > i) ++add;
        }

        used[i] = true;

        rec(k + 1, inv + add);

        used[i] = false;
    }
}

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d: ", tc);

    cin >> n;
    forn(i, n) cin >> s[i];

    forn(i, n)
    {
        l[i] = 0;

        forn(j, n)
        {
            if (s[i][j] == '1') l[i] = j;
        }
    }

    ans = 10000;
    start = clock();
    TL = false;

    forn(i, n) used[i] = false;

    rec(0, 0);

    cout << ans << endl;
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
            
