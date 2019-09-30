#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <numeric>
#include <complex>
#include <iomanip>
#include <set>

using namespace std;

#define bitcount(n) __builtin_popcount(n)

#define debug(n) cout << n << endl;

#define PREC(n) setprecision(n)
#define DOTPREC(n) fixed << setprecision(n)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define rep(i,x) for(int i=0;i<(x);++i)
#define rep1(i,x) for(int i=1;i<=(x);++i)
#define rrep(i,x) for(int i=(x)-1;i>=0;--i)
#define rrep1(i,x) for(int i=(x);i>=1;--i)
#define FOR(i,a,x) for(int i=(a);i<(x);++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define omajinai ios::sync_with_stdio(false); cin.tie(0)

template<typename T> bool chmax(T&a,T b) { if(a < b) {a = b; return true;} return false;}
template<typename T> bool chmin(T&a,T b) { if(a > b) {a = b; return true;} return false;}

const int inf = 1e9;
const ll linf = 3e18;
const double eps = 1e-9;

const ll MOD = 1000000007;

ll N, x;

int main(void)
{
    cin >> N >> x;
    if (x == 1 || x == (2 * N - 1)) {
        debug("No");
        return 0;
    }

    debug("Yes");


    set<ll> available;
    rep1(i, 2 * N - 1) {
        available.insert(i);
    }

    available.erase(x);

    ll r, l;
    if (x == (2 * N - 2)) {
        r = 2 * N - 1;
        l = x - 1;
    }
    else {
        r = 1;
        l = x + 1;
    }

    available.erase(l);
    available.erase(r);

    rep1(i, 2 * N - 1) {
        if (i == N) {
            debug(x);
            continue;
        }
        else if (i == N - 1) {
            debug(l);
            continue;
        }
        else if (i == N + 1) {
            debug(r);
            continue;
        }
        ll ans = *available.begin();
        debug(ans);
        available.erase(ans);
    }

    return 0;
}