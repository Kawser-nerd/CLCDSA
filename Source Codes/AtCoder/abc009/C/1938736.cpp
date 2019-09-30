#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
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
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::sort;
using std::abs;
using std::swap;

using std::fixed;
using std::setprecision;
using std::setw;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 314;

int diff(const string& s, const string& t) {
    int cnt = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != t[i]) {
            cnt++;
        }
    }
    return cnt;
}

bool valid(const string& s, const string& t, int k) {
    string w(s);
    for (size_t i = 0; i < t.size(); i++) {
        bool found = false;
        for (size_t j = i; j < w.size(); j++) {
            if (t[i] == w[j]) {
                swap(w[i], w[j]);
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }

    for (size_t i = t.size(); i < w.size(); i++) {
        for (size_t j = t.size(); j < w.size(); j++) {
            if (s[j] != w[j] && s[i] == w[j]) {
                swap(w[i], w[j]);
                break;
            }
        }
    }

    // cout << "t: " << t << endl;
    // cout << "s: " << s << endl;
    // cout << "w: " << w << endl;
    // cout << (diff(s, w) <= k) << endl;
    // cout << endl;
    return diff(s, w) <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string t;
    for (int i = 0; i < n; i++) {
        for (int j = 'a'; j <= 'z'; j++) {
            t.push_back(j);
            if (valid(s, t, k)) {
                break;
            }
            t.pop_back();
        }
    }
    cout << t << endl;
    return 0;
}