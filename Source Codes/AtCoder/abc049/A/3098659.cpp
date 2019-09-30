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
    char c;
    cin >> c;
    std::string s = "aeiou";
    for (int i = 0; i < 5; i++) {
        if (c == s[i]) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;

    return 0;
}