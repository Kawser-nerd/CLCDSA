#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <bitset>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

struct Idx {
    int idx;
    ll val;
};

// ???????????
// ????????index?????????
bool SortbyVal(const Idx &a, const Idx &b) {
    if (a.val == b.val) return a.idx > b.idx;
    return a.val > b.val;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <Idx> vec(n);
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        vec[i] = (Idx){i, a};
    }

    vec.push_back((Idx){-1, 0LL});
    sort(vec.begin(), vec.end(), SortbyVal);

    vector <ll> ans(n, 0);
    int id = n;
    ll pc = 0, cur = vec[0].val;
    while (pc <= n) {
        if (vec[pc].val == cur) {
            pc++;
            continue;
        }

        id = min(id, vec[pc - 1].idx);
        ans[id] += (cur - vec[pc].val) * pc;
        cur = vec[pc++].val;
    }

    for (ll ret : ans) cout << ret << "\n";
    return 0;
}