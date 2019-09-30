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
    int64_t res = 0;
    cin >> s;
    int floor;
    const int topfloor = s.size();
    for (int i = 0; i < s.size(); i++) {
        floor = i + 1;
        if (s[i] == 'U') {
            res += (topfloor - floor) + (floor - 1) * 2;
        } else {
            res += (floor - 1) + (topfloor - floor) * 2;
        }
    }
    cout << res << endl;

    return 0;
}