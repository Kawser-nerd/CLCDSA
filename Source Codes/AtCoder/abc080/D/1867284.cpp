#include <algorithm>
#include <cstdio>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(x) begin(x), end(x)
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int main() {
    // input
    int n, k; scanf("%d%d", &n, &k);
    vector<int> l(n), r(n), c(n);
    repeat (i, n) {
        scanf("%d%d%d", &l[i], &r[i], &c[i]);
        -- c[i];
    }
    // solve
    map<int, vector<int> > from_l;
    repeat (i, n) {
        from_l[l[i]].push_back(i);
    }
    int free_tvs = 0;
    reversed_priority_queue<pair<int, int> > used_tvs;
    for (auto & event : from_l) {
        int t = event.first;
        while (not used_tvs.empty() and used_tvs.top().first < t) {
            free_tvs += 1;
            used_tvs.pop();
        }
        vector<int> fixed_tvs(k);
        while (not used_tvs.empty() and used_tvs.top().first == t) {
            fixed_tvs[used_tvs.top().second] += 1;
            used_tvs.pop();
        }
        for (int i : event.second) {
            if (fixed_tvs[c[i]]) {
                fixed_tvs[c[i]] -= 1;
            } else if (free_tvs) {
                free_tvs -= 1;
            }
            used_tvs.emplace(r[i], c[i]);
        }
        free_tvs += accumulate(whole(fixed_tvs), 0);
    }
    int result = free_tvs + used_tvs.size();
    // output
    printf("%d\n", result);
    return 0;
}