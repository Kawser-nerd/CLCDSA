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
    string S;
    cin >> S;
    map<char, int> cnt;

    rep(i, 0, N) {
        if (cnt.count(S[i])) {
            cnt[S[i]]++;
        }
        else {
            cnt[S[i]] = 2;
        }
    }

    ll ans = 1;
    for(auto it = cnt.begin(); it != cnt.end(); ++it) {
        ans *= it->second;
        ans %= 1000000007;
    }
    cout << ans - 1 << endl;
}