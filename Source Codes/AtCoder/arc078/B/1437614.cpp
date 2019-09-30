#include <iostream>
#include <vector>
#include <algorithm>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

int step(const vvi &g, vi &q, vi &marked) {
    static vi q2;
    int r = 0;
    for (auto a : q) {
        if (!marked[a]) {
            marked[a] = 1;
            r++;
            for (auto b : g[a]) {
                if (!marked[b]) q2.push_back(b);
            }
        }
    }
    q.clear();
    std::swap(q, q2);
    return r;
}

int main() {
    int n; std::cin >> n;
    vvi g(n + 1);
    for (int i = 0; i < n-1; i++) {
        int a, b; std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi marked(n + 1);
    vi q1 = {1}, q2 = {n};
    int c1 = 0, c2 = 0;

    while (!(q1.empty() || q2.empty())) {
        c1 += step(g, q1, marked);
        c2 += step(g, q2, marked);
    }
    while (!q1.empty()) c1 += step(g, q1, marked);
    while (!q2.empty()) c2 += step(g, q2, marked);

    std::cout << (c1 > c2 ? "Fennec" : "Snuke") << std::endl;
}