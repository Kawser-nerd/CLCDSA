#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numeric>
#include <string>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )
#define llrep(i, a, b) for(ll i = (a); i < (b); ++i )
#define llrrep(i, a, b) for(ll i = (a); i > (b); --i )
#define llREP(i, a, b) for(ll i = (a); i <= (b); ++i )
#define llRREP(i, a, b) for(ll i = (a); i >= (b); --i )
#define ullrep(i, a, b) for(ull i = (a); i < (b); ++i )
#define ullrrep(i, a, b) for(ull i = (a); i > (b); --i )
#define ullREP(i, a, b) for(ull i = (a); i <= (b); ++i )
#define ullRREP(i, a, b) for(ull i = (a); i >= (b); --i )


int H, W, D;
int X[90010];
int Y[90010];
int S[90010];
int Q;

int main() {
    cin >> H >> W >> D;
    REP(i, 1, H)
    REP(j, 1, W) {
        int val;
        cin >> val;
        X[val] = j;
        Y[val] = i;
    }
    cin >> Q;
    REP(i, 1, D) {
        S[i] = 0;
    }
    REP(i, D+1, H*W) {
        S[i] = S[i-D] + abs(X[i] - X[i-D]) + abs(Y[i] - Y[i-D]);
    }
    rep(i, 0, Q) {
        int L, R;
        cin >> L >> R;
        cout << S[R] - S[L] << endl;
    }
}