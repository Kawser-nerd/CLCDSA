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

void solve(int d, int i)
{
    int index = 12;
    if (d == 5) {
        index += 4 - i;
    }
    else if (d == 7) {
        index += 11 - i;
    }
    else {
        assert(false);
        return ;
    }
    index %= 12;


    switch (index) {
        case 0:
            debug("Do");
            break;
        case 2:
            debug("Re");
            break;
        case 4:
            debug("Mi");
            break;
        case 5:
            debug("Fa");
            break;
        case 7:
            debug("So");
            break;
        case 9:
            debug("La");
            break;
        case 11:
            debug("Si");
            break;
        default:
            assert(false);
            break;
    }
}

int main(void)
{
    cin >> S;

    int white = -1;
    rep(i, S.size() - 1) {
        if (S[i] == 'W' && S[i+1] == 'W') {
            if (white != -1) {
                int d = i - white;
                solve(d, i);
                break;
            }
            white = i;
        }
    }

    return 0;
}