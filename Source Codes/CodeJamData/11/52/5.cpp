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

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define NMAX 100005

int c[NMAX];

void solve(int test)
{
    printf("Case #%d: ", test);

    memset(c, 0, sizeof(c));

    int n; cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }

    forn(i, n)
    {
        int x;
        cin >> x;
        c[x]++;
    }

    queue<int> q;
    int sz = 0;
    int ans = NMAX;

    forn(i, NMAX)
    {
        if (c[i] == sz) continue;
        while (c[i] > sz)
        {
            sz++;
            q.push(i);    
        }
        while (c[i] < sz)
        {
            sz--;
            ans = min(ans, i - q.front());
            q.pop();
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
    forn(it, tc) solve(it + 1);
    
    return 0;
}