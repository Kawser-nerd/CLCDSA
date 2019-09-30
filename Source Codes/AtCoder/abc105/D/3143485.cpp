#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m, a[100000];
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    map<int, int> rest_num_table;
    rest_num_table[0]++;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum + a[i]) % m;
        rest_num_table[sum]++;
    }

    long long ans = 0;
    for (auto rest_num_i : rest_num_table) ans += 1ll * rest_num_i.second * (rest_num_i.second - 1) / 2;

    cout << ans << endl;
}