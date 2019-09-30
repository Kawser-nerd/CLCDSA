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

int N;
ll H[100005], S[100005];

// ???k???????????
bool check(ll k) {

    // cnt???????????????????
    vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        if (k < H[i]) return false;
        int c = (k - H[i]) / S[i];
        if (c >= 0 && c < N) cnt[c]++;
    }

    for (int i = 0; i < N; i++) {
        if (i > 0) cnt[i] += cnt[i-1];
        if (cnt[i] > i + 1) return false;
    }

    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> H[i] >> S[i];

    ll l = 0, r = 1LL << 60;
    while (r - l > 1) {
        ll mid = (r + l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << "\n";
    return 0;
}