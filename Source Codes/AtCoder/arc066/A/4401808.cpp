#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const int MOD = 1000000007;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A, A+n);

    vector <int> vec(n);
    if (n % 2 == 0) {
        int s = 1;
        for (int i = 0; i < n; i += 2) {
            vec[i] = s;
            vec[i+1] = s;
            s += 2;
        }
    } else {
        int s = 2;
        vec[0] = 0;
        for (int i = 1; i < n; i += 2) {
            vec[i] = s;
            vec[i+1] = s;
            s += 2;
        }
    }

    for (int i = 0; i < n; i++) {
        if (A[i] != vec[i]) {
            cout << 0 << "\n";
            return 0;
        }
    }

    int ans = 1;
    for (int i = 0; i < n / 2; i++) {
        ans = ans * 2 % MOD;
    }

    cout << ans << "\n";
    return 0;
}