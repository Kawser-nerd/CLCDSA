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

int n;
std::string s;

void search(char first, char second) {
    std::string res;
    res.push_back(first);
    res.push_back(second);
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == 'o') {
            if (res[i] == 'S') {
                res.push_back(res[i - 1]);
            } else {
                if (res[i - 1] == 'S') {
                    res.push_back('W');
                } else {
                    res.push_back('S');
                }
            }
        } else {
            if (res[i] == 'S') {
                if (res[i - 1] == 'S') {
                    res.push_back('W');
                } else {
                    res.push_back('S');
                }

            } else {
                res.push_back(res[i - 1]);
            }
        }
    }
    // cout << res << endl;

    if (s[n - 1] == 'o' && res[n - 1] == 'S') {
        if (res[n - 2] != res[0]) {
            return;
        }
    } else if (s[n - 1] == 'o' && res[n - 1] == 'W') {
        if (res[n - 2] == res[0]) {
            return;
        }
    } else if (s[n - 1] == 'x' && res[n - 1] == 'S') {
        if (res[n - 2] == res[0]) {
            return;
        }
    } else {
        if (res[n - 2] != res[0]) {
            return;
        }
    }

    if (s[0] == 'o' && res[0] == 'S') {
        if (res[1] != res[n - 1]) {
            return;
        }
    } else if (s[0] == 'o' && res[0] == 'W') {
        if (res[1] == res[n - 1]) {
            return;
        }
    } else if (s[0] == 'x' && res[0] == 'S') {
        if (res[1] == res[n - 1]) {
            return;
        }
    } else {
        if (res[1] != res[n - 1]) {
            return;
        }
    }

    cout << res << endl;
    exit(0);

    return;
}

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    search('S', 'S');
    // cout << "false" << endl;
    search('S', 'W');
    // cout << "false" << endl;
    search('W', 'W');
    // cout << "false" << endl;
    search('W', 'S');
    cout << -1 << endl;

    return 0;
}