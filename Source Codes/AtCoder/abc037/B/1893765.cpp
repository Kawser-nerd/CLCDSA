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
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < q; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        l--;
        r--;
        for (int j = l; j <= r; j++) {
            a[j] = t;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}