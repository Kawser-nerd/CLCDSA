#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int solve(int n, const vector<int>& b, int id) {
    bool leaf = true;
    int low = INF;
    int high= -INF;
    for (int i = 0; i < n; i++) {
        if (b[i] == id) {
            leaf = false;
            int v = solve(n, b, i);
            low = min(low, v);
            high = max(high, v);
        }
    }
    return leaf ? 1 : low + high + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> b(n);
    b[0] = -1;
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    cout << solve(n, b, 0) << endl;
    return 0;
}