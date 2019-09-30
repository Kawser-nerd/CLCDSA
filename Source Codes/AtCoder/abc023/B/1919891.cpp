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

    string s;
    cin >> s;

    string t = "b";
    int step = 1;
    while (t.length() < s.length()) {
        if (step % 3 == 1) {
            t = "a" + t + "c";
        }
        if (step % 3 == 2) {
            t = "c" + t + "a";
        }
        if (step % 3 == 0) {
            t = "b" + t + "b";
        }
        step++;
    }
    if (s == t) {
        cout << step - 1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}