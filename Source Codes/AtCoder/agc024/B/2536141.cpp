#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int& p : a) cin >> p;
        vector<int> b(n, -1), c(n, n);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[a[i]] = i;
        int mx = 1;
        int cr = -1;
        int ct = 0;
        for (int i = 1; i <= n; ++i) {
            int j = mp[i];
            if (cr < j) {
                cr = j;
                ++ct;
            } else {
                cr = j;
                ct = 1;
            }
            mx = max(mx, ct);
        }
        cout << n - mx << endl;
    }
    return 0;
}