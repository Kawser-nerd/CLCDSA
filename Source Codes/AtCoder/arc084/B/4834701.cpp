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
const ll MOD = 1000000007LL;

struct edge {
    int to, cost;
};

vector <edge> edges[100005];
int c[100005];

int main() {
    int K;
    cin >> K;

    for (int i = 1; i <= K; i++) {
        edges[i].push_back((edge){(i + 1) % K, 1});
        edges[i].push_back((edge){i * 10 % K, 0});
    }

    deque <int> q;
    fill(c, c+K, 1e9);

    q.push_back(1);
    c[1] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop_front();

        for (edge e : edges[cur]) {
            if (c[cur] + e.cost >= c[e.to]) continue;
            c[e.to] = c[cur] + e.cost;
            if (e.cost == 0) {
                q.push_front(e.to);
            } else {
                q.push_back(e.to);
            }
        }
    }

    cout << c[0] << "\n";
    return 0;
}