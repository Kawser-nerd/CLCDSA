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
#include <cstring>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl

int main() {
    int N;
    while (cin >> N) {
        vector<pair<int, int>> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        auto b = a;
        sort(a.begin(), a.end());
        auto p = a[a.size() / 2 - 1];
        auto q = a[a.size() / 2];
        for (int i = 0; i < N; ++i) {
            if (b[i].first <= p.first) {
                cout << q.first << endl;
            } else {
                cout << p.first << endl;
            }
        }
    }
    return 0;
}