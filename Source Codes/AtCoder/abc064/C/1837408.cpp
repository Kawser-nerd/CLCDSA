#include <algorithm>
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
using std::min_element;
using std::max_element;
using std::sort;
using std::count;
using std::abs;

int main(void) {
    int n;
    cin >> n;

    vector<bool> a(8);
    int wild = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (1 <= x && x <= 399) {
            a[0] = true;
        } else if (400 <= x && x <= 799) {
            a[1] = true;
        } else if (800 <= x && x <= 1199) {
            a[2] = true;
        } else if (1200 <= x && x <= 1599) {
            a[3] = true;
        } else if (1600 <= x && x <= 1999) {
            a[4] = true;
        } else if (2000 <= x && x <= 2399) {
            a[5] = true;
        } else if (2400 <= x && x <= 2799) {
            a[6] = true;
        } else if (2800 <= x && x <= 3199) {
            a[7] = true;
        } else {
            wild++;
        }
    }

    int cnt = count(a.begin(), a.end(), true);
    cout << max(cnt, 1) << " " << (cnt + wild) << endl;

    return 0;
}