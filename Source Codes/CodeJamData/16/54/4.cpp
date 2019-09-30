#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
#include <stack>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

string IMP = "IMPOSSIBLE";

void solve() {
    int n, l;
    cin >> n >> l;
    set<string> g;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        g.insert(s);
    }
    string b;
    cin >> b;

    if (g.count(b)) {
        cout << IMP << endl;
        return;
    }

    string a0, a1;
    if (l == 1) {
        //corner case
        if (b == "0") {
            a0 = "1?";
            a1 = "1";
        } else {
            a0 = "0?";
            a1 = "0";
        }
    } else {
        for (int i = 0; i < l-1; i++) {
            if (b[i] == '0') {
                a0 += "10";
            } else {
                a0 += "01";
            }
        }
        for (int i = 0; i < l; i++) {
            if (b[i] == '0') {
                a1 += "1?";
            } else {
                a1 += "0?";
            }
        }
    }

    cout << a0 << " " << a1 << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}