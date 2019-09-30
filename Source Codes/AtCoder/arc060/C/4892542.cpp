#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;
const ll MOD = 1000000007LL;

int n, Q;
ll x[100005], L;
int idx[30][100005]; // ???j??2^i????????????idx

// k????a??b???????
bool check(int a, int b, int k) {
    if (a >= b) return true;
    if (k == 0) return false;

    int t = 0;
    while (1 << (t + 1) <= k) t++;
    return check(idx[t][a], b, k - (1 << t));
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    cin >> L;

    for (int j = 0; j < n; j++) {
        int i = lower_bound(x, x+n, x[j] + L) - x;
        if (i < n && x[i] == x[j] + L) i++;
        i--;
        idx[0][j] = i;
    }

    // ?????
    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < n; j++) {
            idx[i+1][j] = idx[i][idx[i][j]];
        }
    }

    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a > b) swap(a, b);

        int l = 0, r = 100000;
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (check(a, b, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        cout << r << "\n";
    }

    return 0;
}