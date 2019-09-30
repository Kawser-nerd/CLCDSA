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
    /*cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);*/
    int h, w;
    cin >> h >> w;
    std::string s;
    for (int i = 0; i < h; i++) {
        cin >> s;
        cout << s << endl << s << endl;
    }

    return 0;
}