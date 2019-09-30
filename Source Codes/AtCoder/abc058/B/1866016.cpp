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
    string s, t;
    cin >> s >> t;

    int len = s.length() + t.length();
    string ans;
    for (int i = 0; i < len; i++) {
        ans.push_back(i % 2 == 0 ? s[i / 2] : t[i / 2]);
    }

    cout << ans << endl;

    return 0;
}