#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    int x;
    cin >> x;
    if (x == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int number = x; number >= 1; number--) {
        for (int b = 2; b <= number; b++) {
            for (int p = 2; std::pow(b, p) <= number; p++) {
                if (std::pow(b, p) == number) {
                    cout << number << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}