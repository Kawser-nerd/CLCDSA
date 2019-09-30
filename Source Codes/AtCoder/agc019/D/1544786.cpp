#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <cassert>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i, m, n) for (int i = (n)-1; (i) >= int(m); --(i))
#define whole(x) begin(x), end(x)
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

template <typename UnaryPredicate>
ll binsearch(ll l, ll r, UnaryPredicate p) { // [l, r), p is monotone
    assert (l < r);
    -- l;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r; // = min { x in [l, r) | p(x) }, or r
}

constexpr int inf = 1e9+7;
int solve(string const & a, string const & b) {
    if (not count(whole(b), '1')) {
        return count(whole(a), '1') ? -1 : 0;
    }
    int n = a.size();
    if (count(whole(a), '1') == n and count(whole(b), '1') == 1) {
        return 2 * n - 2;
    }
    vector<int> b_acc(n + 1);
    repeat (i, n) b_acc[i + 1] = b_acc[i] + (b[i] == '1');
    auto get_b_acc = [&](int l, int r) { return b_acc[r] - b_acc[l] + (l > r ? b_acc[n] : 0); };
    int result = inf;
    repeat (l, n) {
        vector<pair<int, int> > que;
        int cnt = 0;
        repeat (j, n) {
            int i = (l + j) % n;
            if (a[i] != b[j]) {
                cnt += 1;
                if (not get_b_acc(j, i + 1)) {
                    int dl = binsearch(0, n, [&](int d) {
                        return get_b_acc((j - d + n) % n, j);
                    });
                    int dr = binsearch(0, n, [&](int d) {
                        return get_b_acc(i + 1, (i + 1 + d) % n);
                    });
// cerr << i << " : " << dl << " / " << dr << endl;
                    que.emplace_back(dl, dr);
                }
            }
        }
        int delta = n;
        if (que.empty()) {
            delta = 0;
        } else {
            sort(whole(que));
            int acc = 0;
            repeat_reverse (i, que.size()) {
                setmin(delta, 2 * que[i].first + 2 * acc);
                acc = max(acc, que[i].second);
            }
            setmin(delta, 2 * acc);
        }
// cerr << a.substr(l) << a.substr(0, l) << " A " << ' ' << l << ' ' << cnt << ' ' << delta << " -> " <<l + cnt + delta<< endl;
// cerr << b << " B" << endl;
        setmin(result, l + cnt + delta);
    }
    return result;
}

int main() {
    string a, b; cin >> a >> b;
    int result = inf;
    setmin(result, solve(a, b));
    reverse(whole(a));
    reverse(whole(b));
    setmin(result, solve(a, b));
    cout << result << endl;
    return 0;
}