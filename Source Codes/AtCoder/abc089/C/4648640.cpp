#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>
#include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define rep(i, a, N) for(int i = a; i < N; i++)

int main() {
    int N;
    cin >> N;

    map<char, int> table = {{'M', 0}, {'A', 1}, {'R', 2}, {'C', 3}, {'H', 4}};
    int cnt[5] = {};
    rep(i, 0, N) {
        string s;
        cin >> s;
        if (s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H')
            cnt[table[s[0]]]++;
    }

    ll ans = 0;
    rep(i, 0, 5) {
        rep(j, i + 1, 5) {
            rep(k, j + 1, 5) {
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << ans << endl;
}