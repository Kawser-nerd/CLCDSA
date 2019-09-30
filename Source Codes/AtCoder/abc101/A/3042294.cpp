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
    std::string s;
    int result = 0;
    cin >> s;
    for (int i = 0; i < 4; i++) {
        if (s[i] == '+')
            result++;
        else
            result--;
    }
    cout << result << endl;

    return 0;
}