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

ll solve(ll a) {
    string s = to_string(a);

    const int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '4' || s[i] == '9') {
            s[i]--;
            for (int j = i + 1; j < n; j++) {
                s[j] = '8';
            }
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if(s[i] >= '5'){
            s[i]--;
        }
    }

    return std::stoll(s, nullptr, 8);
}

int main() {
    ll a, b;
    cin >> a >> b;

    ll cnt_a = solve(a - 1);
    ll cnt_b = solve(b);
    cout << (b - a + 1) - (cnt_b - cnt_a) << endl;
    return 0;
}