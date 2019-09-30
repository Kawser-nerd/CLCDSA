#include <algorithm>
#include <complex>
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

using std::min;
using std::max;
using std::sort;
using std::abs;

using std::pair;
using std::lower_bound;

typedef long long int ll;
const int MOD = 1e9 + 7;

class box {
   public:
    int w, h;
    box() {}
    box(int w, int h) : w(w), h(h) {}
    bool operator<(const box& b) const {
        if (w == b.w) {
            return h > b.h;
        }
        return w < b.w;
    }
};

int main() {
    size_t n;
    cin >> n;

    vector<box> bs(n);
    for (size_t i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        bs[i] = box(w, h);
    }
    sort(bs.begin(), bs.end());

    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
        a[i] = bs[i].h;
    }

    vector<int> l;
    l.push_back(a[0]);
    for (size_t i = 0; i < n; i++) {
        size_t j = lower_bound(l.begin(), l.end(), a[i]) - l.begin();
        if (j >= l.size()) {
            l.push_back(a[i]);
        } else {
            l[j] = a[i];
        }
    }

    cout << l.size() << endl;

    return 0;
}