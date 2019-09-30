#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include <cmath>
using namespace std;

const double PI = acos(-1.0);

int n, k;
vector<pair<int, int>> a;

long long GetBottomSquare(const pair<int, int>& p) {
    return 2LL * p.first * p.second;
}

void Solve() {
    sort(a.begin(), a.end(), [] (const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return GetBottomSquare(lhs) > GetBottomSquare(rhs);
    });

    vector<long long> bottomSum(n);
    bottomSum[0] = GetBottomSquare(a[0]);
    for (int i = 1; i < n; ++i) {
        bottomSum[i] = bottomSum[i - 1] + GetBottomSquare(a[i]);
    }

    long long result = 0;
    for (int mx = 0; mx < n; ++mx) {
        long long curResult = 1LL * a[mx].first * a[mx].first;
        int toId = k - 2;
        if (mx <= toId) {
            ++toId;
            curResult -= GetBottomSquare(a[mx]);
        }
        if (toId >= 0) {
            curResult += bottomSum[toId];
        }
        curResult += GetBottomSquare(a[mx]);
        result = max(result, curResult);
    }

    cout << fixed << setprecision(15) << PI * result << endl;
}

void Read() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        Read();
        cout << "Case #" << test << ": ";
        Solve();
    }

    return 0;
}
