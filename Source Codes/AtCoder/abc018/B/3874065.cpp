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

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        std::string newstr;
        for (int i = 0; i < l - 1; i++) {
            newstr += s[i];
        }
        for (int i = r - 1; i >= l - 1; i--) {
            newstr += s[i];
        }
        for (int i = r; i < s.size(); i++) {
            newstr += s[i];
        }
        s = newstr;
    }

    cout << s << endl;

    return 0;
}