#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int64_t get_comb(int64_t n) {
    return n * (n - 1) / 2;
}

int main(void) {
    int64_t result = 0;
    int n;
    cin >> n;
    int64_t cum[200001] = {};
    int64_t m1;
    for (int i = 1; i <= n; i++) {
        cin >> m1;
        cum[i] = cum[i - 1] + m1;
    }
    std::vector<int64_t> veccum;
    for (int i = 0; i <= n; i++) {
        veccum.push_back(cum[i]);
    }
    std::sort(veccum.begin(), veccum.end());

    int64_t prev  = veccum[0];
    int64_t count = 1;
    for (int i = 1; i <= n; i++) {
        if (prev == veccum[i]) {
            count++;
        } else {
            result += get_comb(count);
            prev  = veccum[i];
            count = 1;
        }
    }
    result += get_comb(count);
    cout << result << endl;

    return 0;
}