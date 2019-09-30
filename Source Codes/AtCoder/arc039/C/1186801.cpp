#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Hash {
    size_t operator()(const array<int, 2>& key) const {
        return hash<int64_t>()(*(int64_t *)&key[0]);
    }
};

int main() {
    int k;
    string s;
    cin >> k >> s;

    int u[256];
    for (int i = 0; i < 4; i++) u["LRDU"[i]] = i;

    unordered_map<array<int, 2>, array<int, 4>, Hash> h(k * 4);
    array<int, 2> p = { 0, 0 };
    array<int, 4> a = { p[0] - 1, p[0] + 1, p[1] - 1, p[1] + 1 };

    for (int i = 0; i < k; i++) {
        auto i0 = h.insert({ p, a }).first;
        auto i1 = i0;
        int v = u[s[i]];
        do {
            p[v / 2] = i1->second[v];
        } while ((i1 = h.find(p)) != h.end());
        a = { p[0] - 1, p[0] + 1, p[1] - 1, p[1] + 1 };
        i0->second[v] = a[v];
        a[v ^ 1] = i0->second[v ^ 1];
    }

    cout << p[0] << ' ' << p[1] << endl;

    return 0;
}