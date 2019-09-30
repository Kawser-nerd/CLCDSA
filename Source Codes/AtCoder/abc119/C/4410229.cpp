#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define itrep(i, a) for (auto i = (a).begin(); i != (a).end(); i++)
#define REP(i, a, n) for (int i = (a); i <= (n); i++)
#define all(a) (a).begin(), (a).end()
#define mp(a, b) make_pair((a), (b))

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

template<class T> void inputVector(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}

signed main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<int> l;
    inputVector(l, N);

    sort(all(l));

    vector<int> a(N + 1);
    int ret = LLONG_MAX;
    while (a[N] == 0) {
        int len[3] = {0, 0, 0};
        int cnt[3] = {0, 0, 0};
        rep(i, N) {
            if (a[i] == 0) continue;
            len[a[i] - 1] += l[i];
            cnt[a[i] - 1]++;
        }
        bool ok = true;
        rep(i, 3) {
            if (cnt[i] == 0) ok = false;
        }

        if (ok) {
            int cost = 0;
            cost += abs(A - len[0]);
            cost += abs(B - len[1]);
            cost += abs(C - len[2]);
            rep(i, 3) cost += 10 * (cnt[i] - 1);

            ret = min(ret, cost);
        }

        int idx = 0;
        while (true) {
            a[idx]++;
            if (a[idx] < 4) break;
            a[idx] = 0;
            idx++;
        }
    }

    cout << ret << endl;

    return 0;
}