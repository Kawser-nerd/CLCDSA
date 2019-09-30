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

struct chocolate {
    int64_t to, cost;
    chocolate(int64_t a, int64_t b) {
        to   = a;
        cost = b;
    }
};

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;

    std::vector<chocolate> data[20];
    for (int i = 0; i < r; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        data[from].push_back(chocolate(to, cost));
    }

    int64_t res = 0;

    for (int i = 1; i <= ((1 << n) - 1); i++) {
        int bitcount = 0;
        for (int countmask = 1; countmask <= i; countmask = (countmask << 1)) {
            if (i & countmask)
                bitcount++;
        }
        if (bitcount != p)
            continue;

        int cumcost[20] = {};
        for (int person = 1; person <= n; person++) {

            int mask = (1 << (person - 1));
            if (mask & i) {
                // cout << "person " << person << endl;
                for (auto x : data[person]) {

                    cumcost[x.to] += x.cost;
                }
            }
        }
        std::vector<int64_t> sortvec;
        for (int i = 1; i <= m; i++) {
            sortvec.push_back(cumcost[i]);
        }
        std::sort(sortvec.begin(), sortvec.end(), std::greater<int64_t>());
        int tempsum = 0;
        for (int j = 0; j < q; j++) {
            tempsum += sortvec[j];
        }
        // cout << tempsum << endl;
        if (tempsum > res)
            res = tempsum;
    }
    cout << res << endl;

    return 0;
}