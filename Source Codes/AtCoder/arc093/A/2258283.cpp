#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numeric>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )
constexpr int MAXN = 100000 + 1;
ll N;
ll A[MAXN];
ll D[MAXN];
ll DD[MAXN];
int main() {
    ll cnt = 0;
    std::cin >> N;
    A[0] = 0;
    REP(i, 1, N){
        cin >> A[i];
    }
    D[0] = 0;
    REP(i, 1, N) {
        D[i] = abs(A[i] - A[i - 1]);
    }
    rep(i, 1, N) {
        DD[i] = abs(A[i+1] - A[i-1]) - D[i] - D[i+1];
    }
    DD[N] = -D[N] - abs(A[N]) + abs(A[N-1]);
    ll sum = std::accumulate(D, D+N+1, 0) + abs(A[N]);
    for (int i = 1; i <=N ;i++) {
        std::cout << sum + DD[i] << std::endl;
    }
}