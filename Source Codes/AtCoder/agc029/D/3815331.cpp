#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_set>
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
    std::unique_ptr<int[]> barrier_mostsouth(new int[200010]);
    std::unique_ptr<std::unordered_set<int>[]> barrier(
        new std::unordered_set<int>[200010]);
    cin >> h >> w >> n;
    for (int i = 1; i <= h; i++) {
        barrier_mostsouth[i] = w + 1;
    }
    barrier_mostsouth[h + 1] = 1;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        barrier[x].insert(y);
        if (barrier_mostsouth[x] > y) {
            barrier_mostsouth[x] = y;
        }
    }
    for (int i = 1; i <= h; i++) {
        barrier[i].insert(w + 1);
    }
    for (int i = 1; i <= w + 1; i++) {
        barrier[h + 1].insert(i);
    }

    int pos_x = 1, pos_y = 1;
    while (!(barrier_mostsouth[pos_x + 1] <= pos_y)) {

        pos_x++;
        // cout << "posx++: " << pos_x - 1 << " -> " << pos_x << endl;
        if (barrier[pos_x].find(pos_y + 1) == barrier[pos_x].end()) {
            pos_y++;
            // cout << "posy++: " << pos_y - 1 << " -> " << pos_y << endl;
        }
    }
    cout << pos_x << endl;

    return 0;
}