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
    int n;
    cin >> n;
    int two = 0, one = 0, zero = 0;

    int m1;
    for (int i = 0; i < n; i++) {
        cin >> m1;
        if (m1 % 4 == 0)
            two++;
        else if (m1 % 2 == 0)
            one++;
        else
            zero++;
    }

    bool flag;
    if (n % 2 == 0) {
        if (zero <= two)
            flag = true;
        else
            flag = false;
    } else {
        if (zero <= two + 1)
            flag = true;
        else
            flag = false;
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}