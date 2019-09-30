#include <iostream>
#include <map>
using namespace std;

long long nCr(int n, int r) {
    long long ans = 1;
    for (int i = n; i > n - r; i--) ans *= i;
    for (int i = r; i >= 1; i--) ans /= i;
    return ans;
}

int main() {
    int n, m, a[100000];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    map<int, int> rest_num;
    rest_num[0] = 1;
    int bi = 0;
    for (int i = 0; i < n; i++) {
        bi = (bi + a[i]) % m;
        if (rest_num.find(bi) == rest_num.end()) {
            rest_num[bi] = 1;
        } else {
            rest_num[bi] = rest_num[bi] + 1;
        }
    }

    long long ans = 0;
    for (auto table_i : rest_num) {
        int rest_num_i = table_i.second;
        if (rest_num_i >= 2) ans += nCr(rest_num_i, 2);
    }

    cout << ans << endl;
}