#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

void stop(void) {
    cout << "No" << endl;
    exit(0);
}

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::string s, t;
    cin >> s >> t;

    bool is_used[30]   = {};
    char link[30]      = {};
    bool is_linked[30] = {};

    for (int i = 0; i < s.length(); i++) {
        char cs = s[i], ct = t[i];
        if (is_linked[cs - 'a']) {
            if (link[cs - 'a'] != ct) {
                stop();
            }
        } else {
            if (is_used[ct - 'a']) {
                stop();
            } else {
                link[cs - 'a']      = ct;
                is_used[ct - 'a']   = true;
                is_linked[cs - 'a'] = true;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}