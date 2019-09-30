#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <array>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;

    int u[256];
    for (int i = 0; i < 4; i++) u["LRDU"[i]] = i;

    map<uint64_t, array<int, 4>> h;
    uint64_t p = 0;
    int *q = (int *)&p;
    array<int, 4> a = { -1, 1, -1, 1 };

    for (int i = 0; i < k; i++) {
        auto i0 = h.insert({ p, a }).first;
        auto i1 = i0;
        int v = u[s[i]];
        do {
            q[v / 2] = i1->second[v];
        } while ((i1 = h.find(p)) != h.end());
        a = { q[0] - 1, q[0] + 1, q[1] - 1, q[1] + 1 };
        i0->second[v] = a[v];
        a[v ^ 1] = i0->second[v ^ 1];
    }

    cout << q[0] << ' ' << q[1] << endl;

    return 0;
}