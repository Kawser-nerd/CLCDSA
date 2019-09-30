#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const int maxN = 2e5;
int cnt[maxN];

int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] % 2 != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}