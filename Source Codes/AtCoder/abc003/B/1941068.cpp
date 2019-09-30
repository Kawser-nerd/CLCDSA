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
    string s;
    string t;
    cin >> s;
    cin >> t;

    int n = s.length();

    bool ans = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            continue;
        }
        if (s[i] == '@') {
            std::swap(s[i], t[i]);
        }
        if (t[i] != '@' ||
            !(s[i] == 'a' || s[i] == 't' || s[i] == 'c' || s[i] == 'o' ||
              s[i] == 'd' || s[i] == 'e' || s[i] == 'r')) {
            ans = false;
            break;
        }
    }

    cout << (ans ? "You can win" : "You will lose") << endl;

    return 0;
}