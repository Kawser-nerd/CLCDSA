#include <algorithm>
#include <cctype>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

class drink {
   public:
    int p;
    int x;
    drink() {}
    drink(int p, int x) : p(p), x(x) {}
};

int main() {
    int n;
    cin >> n;

    vector<int> ts(n);
    for (int i = 0; i < n; i++) {
        cin >> ts[i];
    }

    int m;
    cin >> m;
    vector<drink> ds(m);
    for (int i = 0; i < m; i++) {
        cin >> ds[i].p >> ds[i].x;
        ds[i].p--;
    }

    int sum_t = 0;
    for (int t : ts) {
        sum_t += t;
    }

    for (int i = 0; i < m; i++) {
        cout << (sum_t - ts[ds[i].p] + ds[i].x) << endl;
    }

    return 0;
}