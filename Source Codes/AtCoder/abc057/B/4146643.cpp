#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;

using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<P> s;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        s.push_back({a, b});
    }
    vector<P> c;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        c.push_back({a, b});
    }
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
        int mind = 999999999;
        int tmp = -1;
        for (int j = 0; j < M; ++j) {
            int d = abs(s[i].first - c[j].first) + abs(s[i].second - c[j].second);
            if (d < mind) {
                mind = d;
                tmp = j + 1;
            }
        }
        ans.push_back(tmp);
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << endl;
    }
}