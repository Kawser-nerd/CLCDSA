#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n;
    int64_t first = 0, second = 0;
    cin >> n;
    std::vector<int64_t> s;
    for (int i = 0; i < n; i++) {
        int m1;
        cin >> m1;
        s.push_back(m1);
    }
    std::sort(s.begin(), s.end(), std::greater<int64_t>());
    int64_t len = 0;
    for (auto x : s) {
        if (x == len) {

            len = 0;
            if (first == 0)
                first = x;
            else {
                second = x;
                cout << first * second << endl;
                exit(0);
            }

        } else {
            len = x;
        }
    }
    cout << 0 << endl;

    return 0;
}