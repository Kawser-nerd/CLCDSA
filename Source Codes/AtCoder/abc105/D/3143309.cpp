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

    map<int, int> rest_num_table;
    rest_num_table[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + a[i]) % m;
        if (rest_num_table.find(sum) == rest_num_table.end()) {
            rest_num_table[sum] = 1;
        } else {
            rest_num_table[sum]++;
        }
    }

    long long ans = 0;
    for (auto rest_num_table_i : rest_num_table) {
        if (rest_num_table_i.second >= 2) ans += nCr(rest_num_table_i.second, 2);
    }
    cout << ans << endl;
}