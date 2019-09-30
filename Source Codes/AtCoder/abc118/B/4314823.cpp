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


ull E = 1000000007;
ull e = 10007;
const double pi = 3.14159265359;


int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> cnt;
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            int a;
            cin >> a;
            ++cnt[a];
        }
    }
    int ans = 0;
    for (auto&& it : cnt) {
        if (it.second == N) {
            ++ans;
        }
    }
    cout << ans << endl;
}