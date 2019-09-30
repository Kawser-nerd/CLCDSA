#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;

static constexpr ull MOD = 1000000007;
static constexpr double pi = 3.14159265359;

int main() {
    int N;
    cin >> N;
    using T = tuple<int, int, int>;

    vector<T> V;
    for (int i = 0; i < N; ++i) {
        int x, y, h;
        cin >> x >> y >> h;
        V.push_back({x, y, h});
    }
    map<P, vector<int>> Hs;
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int ub = 2000000000;
            set<int> chk;
            for (int i = 0; i < N; ++i) {
                int x = get<0>(V[i]);
                int y = get<1>(V[i]);
                int h = get<2>(V[i]);
                int tmp = abs(x - cx) + abs(y - cy);
                if (h == 0) {
                    ub = min(ub, tmp);
                } else {
                    chk.insert(h + tmp);
                    if (chk.size() > 1) break;
                }
            }
            if (chk.size() == 1 && *(chk.begin()) <= ub) {
                cout << cx << " " << cy << " " << *(chk.begin()) << endl;
                return 0;
            }
        }
    }
}