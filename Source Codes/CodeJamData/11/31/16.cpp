#pragma comment(linker, "/STACK:256000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
#define sort_unique(v) sort(all(v)); (v).erase(unique(all(v)), (v).end())

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<ll> vl;

struct Point
{
    int x, y;
};

bool solve(vector<string>& a)
{
    int n = a.size();
    int m = a[0].size();
    forn(i, n) {
        forn(j, m) {
            if (a[i][j] == '#')
            {
                if (j + 1 == m) return false;
                if (a[i][j + 1] != '#') return false;
                if (i + 1 == n) return false;
                if (a[i + 1][j] != '#' || a[i + 1][j + 1] != '#') return false;
                a[i][j] = '/';
                a[i][j + 1] = '\\';
                a[i + 1][j] = '\\';
                a[i + 1][j + 1] = '/';
            }
        }
    }
    return true;
}

int main()
{
   // freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    forn(it, tc)
    {
        cout << "Case #" << it + 1 << ":\n";
        int n, m; cin >> n >> m;
        vector<string> a(n);
        forn(i, n) cin >> a[i];
        if (solve(a)) 
        {
            forn(i, n) cout << a[i] << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}
