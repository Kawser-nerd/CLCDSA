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
    int n, p[20000];
    cin >> n;
    int t1;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int64_t a[20001], b[20001];
    for (int i = 1; i <= n; i++) {
        a[i] = 20000 * (i - 1) + 1;
    }
    int64_t target = 20000 * (n - 1) + 2;
    for (int i = 0; i < n; i++) {
        int pos = p[i];
        b[pos]  = target - a[pos];
        target++;
    }
    for (int i = 1; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << a[n] << endl;
    for (int i = 1; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << b[n] << endl;

    return 0;
}