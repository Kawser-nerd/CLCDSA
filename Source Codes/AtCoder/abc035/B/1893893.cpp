#include <algorithm>
#include <complex>
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
#include <algorithm>
#include <complex>
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
#include <algorithm>
#include <complex>
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

int main() {
    string s;
    cin >> s;

    int t;
    cin >> t;

    int x = 0;
    int y = 0;
    int qcnt = 0;

    for (char c : s) {
        switch (c) {
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case '?':
                qcnt++;
                break;
        }
    }

    int d = abs(x) + abs(y);
    if (t == 1) {
        cout << d + qcnt << endl;
    } else {
        if (d >= qcnt) {
            cout << d - qcnt << endl;
        } else {
            int sub = qcnt - d;
            cout << (sub % 2 == 0 ? 0 : 1) << endl;
        }
    }

    return 0;
}