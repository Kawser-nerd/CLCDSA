#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
#define rep(i, a, b) for(int i = (a); i < (b); ++i )
#define rrep(i, a, b) for(int i = (a); i > (b); --i )
#define REP(i, a, b) for(int i = (a); i <= (b); ++i )
#define RREP(i, a, b) for(int i = (a); i >= (b); --i )

ll N;
struct e {ll i, val;};
e A[200000];

int main() {
    cin >> N;
    for (ll i = 0; i < N; i++) {
        A[i].i = i;
        cin >> A[i].val;
    }
    sort(A, A+N, [](auto a, auto b) {return a.val < b.val;});
    ll min = A[N / 2-1].val;
    ll max = A[N / 2].val;
    for (ll i = 0; i < N; i++) {
        A[i].val = i + 1;
    }
    sort(A, A+N, [](auto a, auto b) {return a.i < b.i;});
    for (ll i = 1; i <= N; i++) {
        if (A[i-1].val < N/2 + 1) {
            cout << max << endl;
        }
        else {
            cout << min << endl;
        }
    }
}