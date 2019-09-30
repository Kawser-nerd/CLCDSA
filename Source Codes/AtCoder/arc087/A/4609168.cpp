#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    }

    long long ans = 0;

    for (auto& p : m) {
        if (p.second < p.first) {
            ans += p.second;
        } else if(p.second > p.first) {
            ans += p.second - p.first;
        }
    }

    cout << ans << endl;
}