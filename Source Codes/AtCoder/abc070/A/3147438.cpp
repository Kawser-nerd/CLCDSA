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
    std::string s;
    cin >> s;
    cout << (s[0] == s[2] ? "Yes" : "No") << endl;
    return 0;
}