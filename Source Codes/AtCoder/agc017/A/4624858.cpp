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

ll C[51][51];

void comb_table(int N) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1LL;
            } else {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2) odd++;
        else even++;
    }

    ll ans = 0;
    comb_table(50);
    for (int i = 0; i <= odd; i++) {
        if (i % 2 == p) {
            ans += C[odd][i];
        }
    }

    cout << ans * (1LL << even) << "\n";
    return 0;
}