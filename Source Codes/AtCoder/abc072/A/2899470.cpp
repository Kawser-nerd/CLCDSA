#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    cout << std::fixed << std::setprecision(10);

    int x, t;
    cin >> x >> t;
    int answer = x - t > 0 ? x - t : 0;
    cout << answer << endl;

    return 0;
}