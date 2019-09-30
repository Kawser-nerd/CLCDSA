#include <algorithm>
#include <complex>
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

    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 0 << endl;
    } else if (x < y) {
        if (0 <= x) {
            cout << y - x << endl;
        } else if (x < 0 && 0 < y) {
            if (abs(x) <= abs(y)) {
                cout << 1 + abs(y) - abs(x) << endl;
            } else {
                cout << abs(x) - abs(y) + 1 << endl;
            }
        } else {
            cout << y - x << endl;
        }
    } else {
        if (0 < y) {
            cout << 1 + abs(x) - abs(y) + 1 << endl;
        } else if (y == 0) {
            cout << 1 + abs(x) << endl;
        } else if (y < 0 && 0 < x) {
            if (abs(x) < abs(y)) {
                cout << abs(y) - abs(x) + 1 << endl;
            } else {
                cout << abs(x) - abs(y) + 1 << endl;
            }
        } else if (x < 0) {
            cout << 1 + abs(y) - abs(x) + 1 << endl;
        } else {
            cout << abs(y) + 1 << endl;
        }
    }

    return 0;
}