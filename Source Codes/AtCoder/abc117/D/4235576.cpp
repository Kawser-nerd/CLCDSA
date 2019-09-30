//
//  main.cpp
//

// https://atcoder.jp/contests/abc117/tasks/abc117_d

#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ll N, K;
vector<ll> Ais;

ll f(ll x) {
    ll ret = 0;
    for (ll ai : Ais) {
        ret += ai ^ x;
    }
    return ret;
}

int main() {
    cin >> N >> K;
    for (int n = 0; n < N; n++) {
        ll ai;
        cin >> ai;
        Ais.push_back(ai);
    }
    int cnt[64]; // cnt[i] = Ai??????ibit?1????????
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 64; i++) {
        for (ll ai : Ais) {
            if ((ai & ((ull)1 << i)) != 0) {
                cnt[i] += 1;
            }
        }
    }
    vector<ll> fs(64, 0);
    // fs[i] = ?(i+1)??????K?????i????K???????(i-1)???????????????????x????f(x)????
    // ?????????x?????????????-1???
    for (int i = 0; i < 64; i++) {
        if (((ull)K & ((ull)1 << i)) == 0) { // K??i????0???
            fs[i] = -1;
            continue;
        }
        ll x = 0;
        if (i < 63) {
            x += ((ull)K) & (((ull)-1) << (i+1));
        }
        // ??????(i+1)??????K?????i????K??????0?
        for (int j = i-1; j >= 0; j--) {
            // ?j???????
            if (2 * cnt[j] < N) { // ????0??????????
                x += (ull)1 << j;
            }
        }
        fs[i] = f(x);
    }
    ll max_fs = f(K);
    for (ll f : fs) {
        max_fs = max(max_fs, f);
    }
    cout << max_fs << endl;
}