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
    int h, w;
    cin >> h >> w;
    std::string s;
    for (int i = 0; i < w + 2; i++) {
        s += '#';
    }
    cout << s << endl;

    for (int i = 0; i < h; i++) {
        std::string t, u;
        t += '#';
        cin >> u;
        t += u;
        t += '#';
        cout << t << endl;
    }
    cout << s << endl;

    return 0;
}