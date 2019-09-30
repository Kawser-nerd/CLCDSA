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

string S;

unordered_map<char, int> counts;

int main(void)
{
    cin >> S;
    rep(i, S.size()) counts[S[i]]++;

    int odds = 0;
    for(auto& count : counts) {
        if (count.scd % 2 == 1) odds++;
    }

    if (odds == 0) {
        cout << S.size() << endl;
        return 0;
    }

    int evens = S.size() - odds;
    // 2 * odds ??????
    cout << (evens / (odds * 2) * 2 + 1) << endl;
    return 0;
}