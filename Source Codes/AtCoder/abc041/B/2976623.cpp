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
    long long a, b, c;
    long long answer;
    cin >> a >> b >> c;
    answer = (a * b) % 1000000007;
    answer *= c;
    answer %= 1000000007;
    cout << answer << endl;

    return 0;
}