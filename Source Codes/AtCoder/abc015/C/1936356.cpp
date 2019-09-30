#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
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
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

bool backtrack(const vector<vector<int>>& t, int n, int k, int d, int sum) {
    if (d >= n) {
        return sum == 0;
    }

    for (int i = 0; i < k; i++) {
        if (backtrack(t, n, k, d + 1, sum ^ t[d][i])) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> t(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> t[i][j];
        }
    }

    cout << (backtrack(t, n, k, 0, 0) ? "Found" : "Nothing") << endl;

    return 0;
}