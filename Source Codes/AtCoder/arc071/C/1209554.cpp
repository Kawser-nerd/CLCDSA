#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;

int main() {
    array<string, 2> s; cin >> s[0] >> s[1];
    array<vector<int>, 2> a_acc;
    repeat (p,2) {
        a_acc[p].resize(s[p].length() + 1);
        repeat (i, s[p].length()) {
            a_acc[p][i+1] = a_acc[p][i] + (s[p][i] == 'A');
        }
    }
    auto pred = [&](int l0, int r0, int l1, int r1) {
        // swap is possible: AB AAA BBAA BAAAA BA
        int a0 = a_acc[0][r0] - a_acc[0][l0];
        int a1 = a_acc[1][r1] - a_acc[1][l1];
        int b0 = (r0 - l0) - a0;
        int b1 = (r1 - l1) - a1;
        assert (a0 or b0);
        if (a0 < a1) { int delta = a1 - a0; a0 += delta; b0 += delta; } // A BB AAB or B AA ABB
        if (b0 < b1) { int delta = b1 - b0; a0 += delta; b0 += delta; } // A BB AAB or B AA ABB
        assert (a1 <= a0 and b1 <= b0);
        int delta = b0 - b1;
        b0 -= delta;
        a0 += 2 * delta;
        return (a0 - a1) % 3 == 0;
    };
    int q; cin >> q;
    while (q --) {
        int l0, r0, l1, r1; cin >> l0 >> r0 >> l1 >> r1; -- l0; -- l1;
        cout << (pred(l0, r0, l1, r1) ? "YES" : "NO") << endl;
    }
    return 0;
}