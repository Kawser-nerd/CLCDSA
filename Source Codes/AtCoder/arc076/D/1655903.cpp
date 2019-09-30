#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(x) begin(x), end(x)
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<pair<int, int> > lrs(n);
    repeat (i, n) {
        int l, r; scanf("%d%d", &l, &r); -- l; -- r;
        lrs[i] = { l, r };
    }
    // solve
    sort(whole(lrs));
    int left = 0;
    reversed_priority_queue<int> unused_rs;
    vector<int> rs;
    for (auto lr : lrs) {
        int l, r; tie(l, r) = lr;
        if (l == -1 and r == m) {
            // nop
        } else if (l == -1) {
            rs.push_back(r);
        } else {
            if (left <= l) {
                ++ left;
                unused_rs.push(r);
            } else {
                unused_rs.push(r);
                int min_r = unused_rs.top();
                unused_rs.pop();
                rs.push_back(min_r);
            }
        }
        if (left == m) {
            break;
        }
    }
    int right = m;
    sort(whole(rs));
    reverse(whole(rs));
    for (int r : rs) {
        if (left == right) {
            break;
        }
        if (r == m) {
            // nop
        } else {
            if (r < right) {
                -- right;
            }
        }
    }
    // output
    int used = left + (m - right);
    printf("%d\n", n - used);
    return 0;
}