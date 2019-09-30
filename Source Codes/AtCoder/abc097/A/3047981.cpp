#include <algorithm>
#include <cstdio>
#include <cstdlib>
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((std::abs(a - b) <= d && std::abs(b - c) <= d) ||
                     std::abs(a - c) <= d
                 ? "Yes"
                 : "No")
         << endl;

    return 0;
}