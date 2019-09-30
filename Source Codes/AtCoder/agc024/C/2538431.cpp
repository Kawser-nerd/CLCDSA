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
        if (a[0]) {
            cout << -1 << endl;
            continue;
        }
        long long ct = 0;
        bool end = false;
        for (int i = 1; i < n; ++i) {
            int d = a[i] - a[i - 1];
            if (d > 1) {
                end = true;
                break;
            } else if (d == 1) {
            } else {
                ct += a[i - 1];
            }
        }
        ct += a.back();
        if (end)
            cout << -1 << endl;
        else
            cout << ct << endl;
    }
    return 0;
}