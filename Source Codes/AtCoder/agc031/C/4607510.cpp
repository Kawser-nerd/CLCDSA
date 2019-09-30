#include <cstdio>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <string>

using namespace std;
using ll = long long;

ll N, A, B;

void input() {
    cin >> N >> A >> B;
//        N = 4;
//        A = 0b0001;
//        B = 0b1100;
}

void bitshow(ll x) {
    for (ll i = N; i > 0; i--) {
        cerr << (x >> (i - 1) & 1);
    }
    cerr << endl;
}

vector<ll> path;

void rec(ll d, ll f) {
    if (f == 0)
        return;
    ll x = d & -d; // mrb
    ll nd = d ^ x, nf = f ^ x;
    
    if (nd == 0) {
        rec(nf & -nf, nf);
        path.push_back(x);
        rec(nf & -nf, nf);
    } else {
        ll y = nd & -nd;
        ll z = nd ^ y;
        rec(y, nf);
        path.push_back(x);
        rec(z, nf);
    }
}

void solve() {
    ll haminglen = A ^ B;
    ll eo = 0;
    for (ll i = 0; i < N; i++) {
        if ((haminglen >> i) & 1)
            eo ^= 1;
    }
    if (eo == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
//    bitshow(A);
    cout << A << endl;
    
    path.reserve(1ull << N);
    rec(A ^ B, (1ull << N) - 1);
    
    for (auto p : path) {
//        bitshow(A ^= p);
        cout << (A ^= p) << endl;
    }
    
}

int main() {
    input();
    //    cout << solve() << endl;
    solve();
    
    return 0;
}