#include <set>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
multiset<int> s;

void solve() {
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s.insert(x);
    }

    int ans = 0;
    while (s.size() >= 2) {
        auto ptr = s.end();
        ptr--;
        int x = *ptr;
        s.erase(ptr);

        long long sum = 1;
        for (int i = 0; i < 32; i++) {
            int y = sum - x;
            auto ptr = s.find(y);
            if (ptr != s.end()) {
                s.erase(ptr);
                ans++;
                break;
            }
            sum *= 2;
        }
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}