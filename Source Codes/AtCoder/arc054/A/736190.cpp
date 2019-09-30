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

using namespace std;

#define bitcount(n) __builtin_popcount(n)

#define debug(n) cout << (n) << endl;

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

ld L, X, Y, S, D;

int main(void)
{
    cin >> L >> X >> Y >> S >> D;

    ld ans;
    if (S > D) {
        if (Y - X <= 0)
            ans = (L - S + D) / (X + Y);
        else
            ans = min( (L - S + D) / (X + Y), (S - D) / (Y - X));
    }
    else {
        if (Y - X <= 0)
            ans = (D - S) / (X + Y);
        else
            ans = min( (D - S) / (X + Y), (L - D + S) / (Y - X));
    }

    cout << DOTPREC(40) << ans << endl;
    return 0;
}