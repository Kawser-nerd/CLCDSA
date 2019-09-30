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

int main() {
    int n;
    cin >> n;

    int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector <bool> used(n, false);
    vector <int> ans(n);

    for (int i = 0; i < n; i++) {
        int num = 1;
        int idx = -1;

        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            if (b[j] == num) idx = j;
            num++;
        }

        if (idx == -1) {
            cout << -1 << '\n';
            return 0;
        } else {
            ans[n-i-1] = b[idx];
            used[idx] = true;
        }
    }

    for (int x : ans) cout << x << "\n";
    return 0;
}