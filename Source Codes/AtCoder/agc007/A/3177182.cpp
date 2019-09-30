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
    int h, w;
    cin >> h >> w;
    std::vector<std::string> field;
    std::string fieldedge = "..........";
    field.push_back(fieldedge);
    for (int i = 0; i < h; i++) {
        std::string s;
        cin >> s;
        std::string pushed = "." + s + ".";
        field.push_back(pushed);
    }
    field.push_back(fieldedge);

    int x = 1, y = 1;
    while (x != w || y != h) {
        bool right = false, under = false, left = false, upper = false;
        int moveablecount = 0;
        if (field[y][x + 1] == '#') {
            right = true;
            moveablecount++;
        }
        if (field[y + 1][x] == '#') {
            under = true;
            moveablecount++;
        }
        if (field[y][x - 1] == '#') {
            left = true;
            moveablecount++;
        }
        if (field[y - 1][x] == '#') {
            upper = true;
            moveablecount++;
        }
        if ((right && under) || (!right && !under)) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (moveablecount >= 3) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (right) {
            x++;
        } else {
            y++;
        }
    }
    if (field[y - 1][x] == '#' && field[y][x - 1] == '#') {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    return 0;
}