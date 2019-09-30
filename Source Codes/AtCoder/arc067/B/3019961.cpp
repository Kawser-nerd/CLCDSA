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

    int64_t n, a, b;
    std::vector<int64_t> town;
    cin >> n >> a >> b;
    int64_t result = 0;
    for (int i = 0; i < n; i++) {
        int m1;
        cin >> m1;
        town.push_back(m1);
    }
    for (int i = 1; i < n; i++) {
        if ((town[i] - town[i - 1]) * a > b)
            result += b;
        else
            result += (town[i] - town[i - 1]) * a;
    }
    cout << result << endl;

    return 0;
}