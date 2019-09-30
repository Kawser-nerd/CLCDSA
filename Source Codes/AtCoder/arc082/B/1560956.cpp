#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;
using ll = long long;
const ll INF = 1e18;

int main() {
    int N;
    cin >> N;
    int p[N+1];
    for (int i = 1; i <= N; i++) cin >> p[i];

    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (i == p[i]) {
            if (i+1 == p[i+1]) {
                ans++;
                p[i+1] = -1;
            } else {
                ans++;
            }
        }
    }

    if (N == p[N]) { // last one
        ans++;
    }

    cout << ans << endl;

    return 0;
}