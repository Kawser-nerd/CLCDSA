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

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    int rest = 0;
    int j = 0;
    for (int i = 0; i <= a[n - 1] + t + 1; i++) {
        while (j < n && a[j] == i) {
            rest = t;
            j++;
        }
        if (rest > 0) {
            cnt++;
            rest--;
        }
    }

    cout << cnt << endl;
    return 0;
}