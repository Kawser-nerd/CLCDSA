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
using std::sort;
using std::abs;

bool evenstring(const string& s) {
    const int len = s.length();
    if (len % 2 != 0) {
        return false;
    }
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[i + len / 2]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    string s;
    cin >> s;

    const int len = s.length();
    for (int i = len - 1; i >= 0; i--) {
        s.resize(i);
        if (evenstring(s)) {
            cout << s.length() << endl;
            break;
        }
    }
    return 0;
}