#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl;

int main() {
    int n;
    cin >> n;
    struct S {
        int t, x, y;
    };
    S prev;
    prev.t = prev.x = prev.y = 0;
    for (int i = 0; i < n; ++i) {
        S next;
        cin >> next.t >> next.x >> next.y;
        int d = abs(prev.x - next.x) + abs(prev.y - next.y);
        if (next.t - prev.t >= d) {
            if ((next.t - prev.t) % 2 == d % 2) {

            } else {
                cout << "No" << endl;
                return 0;
            }
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}