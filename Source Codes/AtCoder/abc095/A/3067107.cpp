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
    int result = 0;
    std::string s;
    cin >> s;
    int count = 0;
    for (auto x : s) {
        if (x == 'o')
            count++;
    }
    cout << 700 + count * 100 << endl;

    return 0;
}