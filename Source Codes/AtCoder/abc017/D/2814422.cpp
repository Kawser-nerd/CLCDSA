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



int N, M;
int F[100010];
int T[100010];
int L[100010];
int DP[100010];
int MOD = 1000000007;

int main() {
    cin >> N >> M;
    rep(i, 0, N) cin >> F[i];
    int r = 0;
    rep(l, 0, N) {
        while ((r < N) && (T[F[r]] == 0)) {
            T[F[r++]] = 1;
            L[r] = l;
        }
        if (l == r) r++;
        else T[F[l]] = 0;
    }
    DP[0] = 1;
    int sum = 0;
    r = 0;
    REP(i, 1, N) {
        sum += DP[i-1];
        sum %= MOD;
        for(; r < L[i]; r++) {
            sum -= DP[r];
            sum %= MOD;
            if (sum < 0) sum += MOD;
        }
        DP[i] = sum % MOD;
    }
    cout << DP[N]%MOD << endl;
}