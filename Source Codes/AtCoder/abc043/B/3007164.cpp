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
    std::string result;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'B') {
            if (result.size() > 0) {
                result.erase(result.end() - 1);
            }
        } else {
            result += s[i];
        }
    }
    cout << result << endl;

    return 0;
}