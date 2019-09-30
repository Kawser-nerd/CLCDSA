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
    cin >> s;
    int count[30] = {};
    for (int i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i <= 'z' - 'a'; i++) {
        if (count[i] % 2 == 1) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}