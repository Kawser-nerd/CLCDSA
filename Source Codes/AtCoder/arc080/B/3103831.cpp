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

    int h, w, n;
    cin >> h >> w >> n;
    std::vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    int result[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            result[i][j] = 0;
        }
    }

    int target = 1;
    int x = 0, y = 0;
    bool lefttoright = true;
    while (target <= n) {
        int count = 0;
        while (count < vec[target]) {
            result[x][y] = target;
            if (lefttoright) {
                if (y + 1 < w) {
                    y++;
                } else {
                    x++;
                    lefttoright = false;
                }
            } else {
                if (y - 1 >= 0) {
                    y--;
                } else {
                    x++;
                    lefttoright = true;
                }
            }
            count++;
        }
        target++;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}