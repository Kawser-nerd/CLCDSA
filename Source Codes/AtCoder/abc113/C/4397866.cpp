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
    int N, M;
    cin >> N >> M;
    map<int, vector<pair<ull, int>>> D;
    for (int i = 1; i <= M; ++i) {
        int P;
        ull Y;
        cin >> P >> Y;
        D[P].push_back({Y, i});
    }
    map<int, pair<int, int>> D2;
    for (auto&& i : D) {
        sort(i.second.begin(), i.second.end());
        for (int j = 0; j < i.second.size(); ++j) {
            D2[i.second[j].second] = {i.first, j + 1};
        }
    }
    for (auto&& it : D2) {
        printf("%06d%06d\n", it.second.first, it.second.second);
    }
}