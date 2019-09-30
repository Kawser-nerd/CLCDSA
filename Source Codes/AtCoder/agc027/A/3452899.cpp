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

    int n, x;
    cin >> n >> x;
    std::vector<int> a;
    for (int i = 0; i < n; i++) {
        int m1;
        cin >> m1;
        a.push_back(m1);
    }
    std::sort(a.begin(), a.end());
    int result = 0;
    bool jump  = false;
    for (int i = 0; i < n - 1; i++) {
        int give = a[i];
        if (x - give >= 0) {
            result++;
            x -= give;
        } else {
            jump = true;
            break;
        }
    }

    if (!jump) {
        if (x == a[n - 1])
            result++;
    }

    cout << result << endl;

    return 0;
}