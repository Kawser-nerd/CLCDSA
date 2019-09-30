#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using int64 = long long;

const int MAXN = 200000;

static int64 A[MAXN];
static vector<int> tree[MAXN];

int64 dfs(int v, int p) {
    if (tree[v].size() == 1) {
        return A[v];
    }
    int64 sum = 0,
          maxc = 0;

    for (int to : tree[v]) {
        if (to == p) continue;
        int64 child = dfs(to, v);
        if (child < 0) return -1;
        sum += child;
        maxc = max(maxc, child);
    }
    // sum - A[v]?????????
    int64 L = sum - A[v];

    if (L < 0 or min(sum / 2, sum - maxc) < L) return -1;
    return sum - 2 * L;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    if (N == 2) {
        cout << (A[0] == A[1] ? "YES" : "NO") << endl;
        return 0;
    }

    int r = -1;
    for (int i = 0; i < N; i++) if (tree[i].size() > 1) r = i;

    if (dfs(r, -1) == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}