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

int solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int u = (s[i] == 'C') ? 0 : 1;
        if (!st.size()) {
            st.push(u);
            continue;
        }
        if (st.top() == u) {
            st.pop();
            ans += 10;
            continue;
        }
        if (st.size() == n-i) {
            st.pop();
            ans += 5;
            continue;
        }
        st.push(u);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: %d\n", t, solve());
    }
    return 0;
}