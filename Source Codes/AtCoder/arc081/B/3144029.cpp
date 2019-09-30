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

const int64_t MOD = 1000000007;

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n;
    std::string s1, s2;
    cin >> n >> s1 >> s2;
    int64_t result = 0;

    int pos = 0;
    bool is_vert;
    if (s1[0] == s2[0]) {
        result  = 3;
        pos     = 1;
        is_vert = true;
    } else {
        result  = 6;
        pos     = 2;
        is_vert = false;
    }
    while (pos < n) {
        if (s1[pos] == s2[pos]) {
            if (is_vert) {
                result *= 2;
            } else {
                result *= 1;
            }
            pos++;
            result %= MOD;
            is_vert = true;
        } else {
            if (is_vert) {
                result *= 2;
            } else {
                result *= 3;
            }
            pos += 2;
            result %= MOD;
            is_vert = false;
        }
    }

    cout << result << endl;

    return 0;
}