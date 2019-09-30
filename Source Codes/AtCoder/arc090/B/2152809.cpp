#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <tuple>

int n, m;
constexpr int MAXN = 100000;
struct Node {int i, d;};
std::vector<Node> G[MAXN+1];
int C[MAXN + 1];
int D[MAXN + 1];
int MAXINT = std::numeric_limits<int>::max();

bool solve() {
    std::queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (C[i] == 0) {
            int r = i;
            C[r] = 1;
            D[r] = 0;
            Q.push(r);
            while (!Q.empty()) {
                r = Q.front();
                for (auto& p: G[r]) {
                    if ((p.d < MAXINT) && (C[p.i] == 1)) {
                        if ((D[r] + p.d) != D[p.i]) {
                            return false;
                        }
                    } else if ((p.d < MAXINT) && (C[p.i] == 0)) {
                        Q.push(p.i);
                        C[p.i] = 1;
                        D[p.i] = D[r] + p.d;
                    }
                }
                Q.pop();
            }
        }
    }
    return true;
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int l, r, d;
        std::cin >> l >> r >> d;
        l -= 1;
        r -= 1;
        G[l].push_back({r, d});
        G[r].push_back({l, -d});
    }

    if (solve()) {
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}