#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = int64_t;

int R, C, N;

i64 get_ord(i64 x, i64 y) {
    if (y == 0) {
        return x;
    } else if (y == C) {
        return R + C + R - x;
    } else if (x == 0) {
        return R + C + R + C - y;
    }
    return R + y;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    vector<pair<int, i64> > ls;

    cin >> R >> C >> N;
    for (int j = 0; j < N; ++j) {
        i64 x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if ((x1 == 0 || x1 == R || y1 == 0 || y1 == C) &&
            (x2 == 0 || x2 == R || y2 == 0 || y2 == C)) {

            i64 o1 = get_ord(x1, y1), o2 = get_ord(x2, y2);

            ls.emplace_back(min(o1, o2), j);
            ls.emplace_back(max(o1, o2), j);
        }
    }

    sort(begin(ls), end(ls));

    stack<int> stk;
    for (int j = 0; j < (int)ls.size(); ++j) {
        if (!stk.empty() && stk.top() == ls[j].second) {
            stk.pop();
        } else {
            stk.push(ls[j].second);
        }
    }
    cout << (stk.empty() ? "YES" : "NO") << endl;


    return 0;
}