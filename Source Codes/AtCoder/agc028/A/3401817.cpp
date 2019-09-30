#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    int64_t n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int64_t l = n * m / __gcd(n, m);

    map<int64_t, int> a;

    for (int i = 0; i < n; i++) {
        a[i * l / n] = i;
    }

    for (int i = 0; i < m; i++) {
        if (a.count(i * l / m) && s[a[i * l / m]] != t[i]) {
            cout << -1 << endl;

            return 0;
        } 
    }

    cout << l << endl;
}