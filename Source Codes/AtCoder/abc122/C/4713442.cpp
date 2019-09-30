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
#define rrep(i, a, N) for(int i = a; i >= N; i--)

int main() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<int> cnt;
    rep(i, 0, N - 1) {
        if (S[i] == 'A' && S[i + 1] == 'C') cnt.push_back(i);
    }

    rep(i, 0, Q) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        l = lower_bound(cnt.begin(), cnt.end(), l) - cnt.begin();
        r = lower_bound(cnt.begin(), cnt.end(), r) - cnt.begin();
        printf("%d\n", r - l);
    }
}