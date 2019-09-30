#include <algorithm>
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
    int n, k;
    cin >> n >> k;
    int result = 1;
    for (int i = 0; i < n; i++) {
        if (result * 2 < result + k)
            result *= 2;
        else
            result += k;
    }
    cout << result << endl;

    return 0;
}