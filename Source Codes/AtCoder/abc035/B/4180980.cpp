#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;


ull E = 1000000007;


int main() {
    int x = 0, y = 0;
    string S;
    cin >> S;
    int cnt = 0;
    for (char c : S) {
        if (c == 'L') --x;
        if (c == 'R') ++x;
        if (c == 'D') --y;
        if (c == 'U') ++y;
        if (c == '?') ++cnt;
    }
    int T;
    cin >> T;
    if (T == 1) {
        cout << abs(x) + abs(y) + cnt << endl;
    } else {
        for (int c = 0; c < cnt; ++c) {
            if (abs(x) != 0) {
                if (x > 0) --x;
                else ++x;
            } else if (abs(y) != 0) {
                if (y > 0) --y;
                else ++y;
            } else {
                ++x;
            }
        }
        cout << abs(x) + abs(y) << endl;
    }
}