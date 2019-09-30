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

int get_gcd(int a, int b) {
    if (a < b)
        std::swap(a, b);
    int r;
    while (1) {
        r = a % b;
        if (r == 0) {
            return b;
        } else {
            a = b;
            b = r;
        }
    }
}

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    std::vector<int> ball;
    int m1;
    bool is_ok = false;
    for (int i = 0; i < n; i++) {
        cin >> m1;
        ball.push_back(m1);
    }
    std::sort(ball.begin(), ball.end());
    int max = *(ball.end() - 1);
    if (max < k) {
        is_ok = false;
    } else if (max == k) {
        is_ok = true;
    } else {
        int min = *(ball.begin());
        int gcd = ball[0];
        for (int i = 1; i < n; i++) {
            gcd = get_gcd(gcd, ball[i]);
        }
        if (k % gcd == 0) {
            is_ok = true;
        } else {
            is_ok = false;
        }
    }

    if (is_ok) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}