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

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int vecabx = bx - ax, vecaby = by - ay;
    cout << bx - vecaby << " " << by + vecabx << " " << ax - vecaby << " "
         << ay + vecabx << endl;

    return 0;
}