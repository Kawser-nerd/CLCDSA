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

int N, C, L;
ll T;
vl a;

ll solve()
{
    vl s(N);
    s[0] = a[0];
    for1(i, N - 1) s[i] = s[i - 1] + a[i];
    int k = 0;
    while (k < N && 2 * s[k] <= T) ++k;
    if (k == N)
    {
        return 2 * s[N - 1];    
    }
    ll T1 = T;
    if (k > 0) T1 -= 2 * s[k - 1];
    a[k] -= T1 / 2;
    assert(a[k] > 0);
    vl b(N - k);
    ll S1 = 0;
    forn(i, N - k) {
        b[i] = a[i + k];
        S1 += b[i];
    }
    sort(all(b));
    reverse(all(b));
    ll M1 = 0;
    forv(i, b)
    {
        if (i >= L) break;
        M1 += b[i];
    }
    return 2 * S1 - M1 + T;
}

int main()
{
    //freopen("input.txt", "rt", stdin);
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    forn(it, tc) {
        cin >> L >> T >> N >> C;
        a.resize(N);
        forn(i, C) cin >> a[i];
        forn(i, N) 
        {
            if (i >= C)
                a[i] = a[i % C]; 
        }
        cout << "Case #" << it + 1 << ": " << solve() << endl;
    }
    return 0;
}
