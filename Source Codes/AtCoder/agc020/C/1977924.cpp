#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

void solve(const vector<int>& as)
{
    int sum = 0;
    for (auto& a : as) {
        sum += a;
    }
    // cout << "sum: " << sum / 2.0 << endl;

    int n = as.size();

    // if (n >= 50) {
    //     cout << (sum + 1) / 2 << endl;
    //     return;
    // }

    bitset<4000001> s, t;
    s[0] = true;
    for (auto& a : as) {
        t = s | (s << a);
        swap(s, t);

        // for (int i = 0; sum - a - i >= 0; i++) {
        //     s[sum - i] |= s[sum - i - a];
        // }
    }

    // // vector<int> s(4000001);

    // s[0] = 1;
    // for (auto& a : as) {

    //     for (int i = 0; sum - a - i >= 0; i++) {
    //         s[sum - i] |= s[sum - i - a];
    //     }
    // }

    auto cand = (sum + 1) / 2;

    for (;;) {
        if (s[cand] > 0) {
            cout << cand << endl;
            return;
        }
        cand++;
    }

    // int64_t acc = 0;
    // for (int i = 1; i < s.size(); i++) {
    //     acc += s[i];
    //     if (acc >= (1L << (n - 1))) {
    //         cout << "* " << (sum + 1) / 2 << endl;
    //         cout << i << endl;
    //         // assert((sum + 1) / 2 == i);
    //         return;
    //     }
    // }
}

int main()
{
    if (0) {
        srand(time(nullptr));
        for (int i = 0; i < 1; i++) {
            int n = 2000;
            vector<int> as(n);
            for (auto& a : as) {
                a = rand() % 2000 + 1;
            }
            solve(as);
        }
        return 0;
    }

    cin.tie(0);

    int n;
    cin >> n;
    vector<int> as(n);
    for (auto& a : as)
        cin >> a;

    solve(as);

    return 0;
}