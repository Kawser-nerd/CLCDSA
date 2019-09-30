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

int main(void) {
    int w, a, b;
    cin >> w >> a >> b;

    if ((a <= b && b <= a + w) || (a <= b + w && b + w <= a + w)) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1e9;
    ans = min(ans, abs(a - b));
    ans = min(ans, abs((a + w) - b));
    ans = min(ans, abs(a - (b + w)));
    ans = min(ans, abs((a + w) - (b + w)));

    cout << ans << endl;

    return 0;
}