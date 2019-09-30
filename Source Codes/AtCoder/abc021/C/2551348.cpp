#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll MOD = 1000000007;
const int INF = 100000;
const int MAX_N = 110;
vector<int> G[MAX_N];
int dist[MAX_N];
ll cnt[MAX_N];

void dijkstra(int x, int n) {
    for(int i=0;i<n;i++) {
        dist[i] = INF;
        cnt[i] = 0;
    }
    priority_queue<P, vector<P>, greater<P> > pq;
    dist[x] = 0;
    cnt[x] = 1;
    pq.push(P(0, x));
    while (!pq.empty()) {
        P p = pq.top();pq.pop();
        for (int i=0;i<G[p.second].size();i++) {
            if (dist[G[p.second][i]] > dist[p.second] + 1) {
                dist[G[p.second][i]] = dist[p.second] + 1;
                cnt[G[p.second][i]] = cnt[p.second];
                pq.push(P(dist[G[p.second][i]], G[p.second][i]));
            } else if (dist[G[p.second][i]] == dist[p.second] + 1) {
                cnt[G[p.second][i]] += cnt[p.second];
                cnt[G[p.second][i]] %= MOD;
            }
        }
    }
}

int main() {
    int a, b, n, m, x, y;
    cin >> n;
    cin >> a >> b;
    cin >> m;
    for (int i=0;i<m;i++) {
        cin >> x >> y;
        x--;y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    a--;b--;
    dijkstra(a, n);
    // for (int i=0;i<n;i++) {
    //     cout << dist[i] << "," << cnt[i] << endl;
    // }
    printf("%lld\n", cnt[b] % MOD);
}