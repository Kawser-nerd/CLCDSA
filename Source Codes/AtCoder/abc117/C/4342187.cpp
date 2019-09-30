#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;
ull e = 10007;
const double pi = 3.14159265359;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X;
    for (int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        X.push_back(x);
    }

    if (N >= M) {
        cout << 0 << endl;
        return 0;
    }

    sort(X.begin(), X.end());
    vector<int> L;
    for (int i = 0; i < M - 1; ++i) {
        L.push_back(X[i + 1] - X[i]);
    }
    sort(L.rbegin(), L.rend());
    int ans = X[M - 1] - X[0];
    for (int i = 0; i < N - 1; ++i) {
        ans -= L[i];
    }
    cout << ans << endl;
}