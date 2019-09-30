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

class person {
   public:
    int i, h;
    person() {}
    person(int i, int h) : i(i), h(h) {}
    bool operator<(const person &p) const { return h < p.h; }
};

int main() {
    int n;
    cin >> n;

    vector<person> a(n);
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        a[i] = person(i, h);
    }

    sort(a.begin(), a.end());

    for (int i = n - 1; i >= 0; i--) {
        cout << a[i].i + 1 << endl;
    }
    return 0;
}