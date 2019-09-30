#include <algorithm>
#include <complex>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
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
using std::pair;
using std::make_pair;

using std::min;
using std::max;
using std::min_element;
using std::max_element;
using std::sort;
using std::count;
using std::abs;

pair<int, int> solve(const string& s) {
    int len = s.length();

    int p = -1;
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == '(' && s[i + 1] == ')') {
            p = i;
            break;
        }
    }

    if (p != -1) {
        string tmp(s);
        tmp.erase(p, 2);
        return solve(tmp);
    }

    int l = count(s.begin(), s.end(), '(');
    int r = count(s.begin(), s.end(), ')');

    return make_pair(l, r);
}

int main(void) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string tmp(s);
    pair<int, int> p = solve(tmp);

    string ans;
    for(int i = 0; i < p.second; i++){
        ans.append("(");
    }
    ans.append(s);
    for(int i = 0; i < p.first; i++){
        ans.append(")");
    }

    cout << ans << endl;
    return 0;
}