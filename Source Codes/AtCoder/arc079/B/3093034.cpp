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

    int64_t k;
    cin >> k;
    if (k == 0) {
        cout << 2 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    } else if (k < 50) {

        cout << k + 1 << endl;
        for (int i = 0; i < k; i++) {
            cout << 0 << " ";
        }
        cout << (k + 1) * k << endl;
        return 0;
    } else {
        int remain = k % 50;
        std::vector<int64_t> num(50, 50 - remain + (k / 50) - 1);
        for (int i = 50 - remain; i < 50; i++) {
            num[i] += 51;
        }

        cout << 50 << endl;
        for (int i = 0; i < 49; i++) {
            cout << num[i] << " ";
        }
        cout << num[49] << endl;
    }

    return 0;
}