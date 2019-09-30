#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

constexpr int MAX_N = 100100;

using namespace std;

int n;
int arr[MAX_N];
ll suf[MAX_N];
int sub[MAX_N];
int pre[MAX_N];
bool has[MAX_N];
ll exempt[MAX_N];
ll ans[MAX_N];

ll tree1[4*MAX_N];
ll tree2[4*MAX_N];

ll update(ll *tree, int i, int a, int b, int j, int m) {
    if (b < a) return 0;
    if (b < j || j < a) return tree[i];
    if (a == b && a == j) tree[i] = m;
    else tree[i] = update(tree, 2*i+1, a, (a+b)/2, j, m)
        + update(tree, 2*i+2, (a+b)/2+1, b, j, m);
    return tree[i];
}

ll query(ll *tree, int i, int a, int b, int l, int r) {
    if (b < a) return 0;
    if (b < l || r < a) return 0;
    if (a >= l && b <= r) return tree[i];
    return query(tree, 2*i+1, a, (a+b)/2, l, r)
        + query(tree, 2*i+2, (a+b)/2+1, b, l, r);
}

int main() {
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %d", &arr[i]);
    }

    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + arr[i];
    }

    int ma = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[ma]) {
            sub[ma] = i;
            pre[i] = ma;
            has[i] = true;
            ma = i;
        }
    }

    vector<pair<int, int>> events;
    for (int i = 1; i <= n; i++) {
        events.push_back(make_pair(arr[i], -i));
    }

    sort(events.begin(), events.end());

    for (pair<int, int> event : events) {
        int amt = event.first;
        int idx = -event.second;
        update(tree1, 0, 1, n, idx, amt);
        update(tree2, 0, 1, n, idx, 1);
        if (sub[idx] > 0) {
            exempt[sub[idx]] = query(tree2, 0, 1, n, sub[idx], n) * amt
                - query(tree1, 0, 1, n, sub[idx], n);
        }
    }

    ll last = 0;
    for (int i = n; i >= 1; i--) {
        if (has[i]) {
            ans[i] = suf[i] - 1LL * arr[pre[i]] * (n - i + 1)
                + exempt[i] - last;
            last += ans[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!has[i]) {
            printf("0\n");
        } else {
            printf("%lld\n", ans[i]);
        }
    }

    return 0;
}