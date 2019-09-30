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
        vector<string> a(n);
        for (auto& s : a) cin >> s;
        vector<int> b(n, 0);
        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < n; ++x) {
                char c = a[y][x];
                int x2 = x;
                int y2 = y;
                for (int i = 0; i < n; ++i) {
                    char c2 = a[y2][x2];
                    if (c == c2) ++b[(i + x - y + n) % n];
                    x2 = (x2 + 1) % n;
                    y2 = (y2 - 1 + n) % n;
                }
            }
        }
        long long sm = 0;
        for (int& p : b) {
            if (p == n * n)
                sm += n;
        }
        cout << sm << endl;
    }
    return 0;
}