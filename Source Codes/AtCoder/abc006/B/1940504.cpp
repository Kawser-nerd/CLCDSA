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
    int n;
    cin >> n;

    vector<int> a(1e6 + 1);
    a[0] = 0;
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i < n; i++) {
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10007;
    }

    cout << a[n-1] << endl;

    return 0;
}