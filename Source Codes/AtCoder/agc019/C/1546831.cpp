#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(x) begin(x), end(x)
using namespace std;

template <typename T>
vector<T> longest_increasing_subsequence(vector<T> const & xs) {
    vector<T> l; // l[i] is the last element of the increasing subsequence whose length is i+1
    l.push_back(xs.front());
    for (auto && x : xs) {
        auto it = lower_bound(l.begin(), l.end(), x);
        if (it == l.end()) {
            l.push_back(x);
        } else {
            *it = x;
        }
    }
    return l;
}

int main() {
    // input
    int lx, ly, rx, ry, n; scanf("%d%d%d%d%d", &lx, &ly, &rx, &ry, &n);
    int h = abs(ry - ly);
    int w = abs(rx - lx);
    vector<pair<int, int> > f;
    repeat (i, n) {
        int x, y; scanf("%d%d", &x, &y);
        x = lx <= rx ? x - lx : lx - x;
        y = ly <= ry ? y - ly : ly - y;
        if (0 <= x and x <= w and 0 <= y and y <= h) {
            f.emplace_back(x, y);
        }
    }
    // solve
    vector<int> lis;
    if (not f.empty()) {
        vector<int> g;
        sort(whole(f));
        for (auto it : f) g.push_back(it.second);
        lis = longest_increasing_subsequence(g);
    }
    double result = 100.0 * (h + w) - (20 - 5 * M_PI) * lis.size();
    if (lis.size() == min(w, h) + 1) {
        result += 5 * M_PI;
    }
    // output
    printf("%.15lf\n", result);
    return 0;
}