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
    int n;
    cin >> n;

    vector<string> ss(n);
    vector<int> ps(n);
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
        cin >> ps[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ps[i];
    }

    int p = -1;
    for (int i = 0; i < n; i++) {
        if (ps[i] > sum / 2) {
            p = i;
            break;
        }
    }

    if (p == -1) {
        cout << "atcoder" << endl;
    } else {
        cout << ss[p] << endl;
    }

    return 0;
}