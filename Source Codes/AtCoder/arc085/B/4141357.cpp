#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;

ll N, Z, W;
vector<ll> A;

void input() {
    cin >> N >> Z >> W;
    A.resize(N);
    for (auto& a : A)
        cin >> a;
}

void solve() {
    if (N == 1) {
        cout << abs(A.back() - W) << endl;
    } else {
        cout << max(abs(A.back() - W), abs(A[N - 2] - A[N - 1])) << endl;
    }
}


int main() {
    input();
    solve();
    
    return 0;
}