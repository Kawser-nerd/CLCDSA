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

    int a, b;
    cin >> a >> b;

    int k;
    cin >> k;

    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }
    p.push_back(a);
    p.push_back(b);

    sort(p.begin(), p.end());

    bool ans = true;
    for (int i = 1; i < k + 2; i++) {
        if (p[i - 1] == p[i]) {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}