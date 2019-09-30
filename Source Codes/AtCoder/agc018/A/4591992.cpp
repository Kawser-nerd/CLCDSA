#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;

    ll A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A, A+n);

    ll g = A[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, A[i]);
    }

    if (k <= A[n-1] && k % g == 0) {
        cout << "POSSIBLE\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}