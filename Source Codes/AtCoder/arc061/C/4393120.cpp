#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

int N, M, inf=1e9;
typedef pair<int, int> P;
typedef pair<int, P> PP;
map <P, vector<PP>> mp;
map <P, int> cost;

void dijkstra(P start){
    priority_queue < PP, vector<PP>, greater<PP> > q;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        cost[itr->first] = inf;
    }
    cost[start] = 0;
    q.push(PP(0, start));
    while (q.size()) {
        PP p = q.top();
        q.pop();
        P current_station = p.second;

        for (PP next : mp[current_station]) {
            P next_station = next.second;
            int c = next.first;
            if (cost[next_station] > cost[current_station] + c) {
                cost[next_station] = cost[current_station] + c;
                q.push(PP(cost[next_station], next_station));
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int p, q, c;
        cin >> p >> q >> c;
        mp[P(p, 0)].push_back(PP(1, P(p, c))); // ?p???c???
        mp[P(p, c)].push_back(PP(0, P(q, c))); // ??c?p->q
        mp[P(q, c)].push_back(PP(0, P(q, 0))); // ?q???c????
        mp[P(q, 0)].push_back(PP(1, P(q, c))); // ?q???c???
        mp[P(q, c)].push_back(PP(0, P(p, c))); // ??c?q->p
        mp[P(p, c)].push_back(PP(0, P(p, 0))); // ?p???c????
    }

    dijkstra(P(1, 0));

    int ans = cost[P(N, 0)] == 0 || cost[P(N, 0)] == inf ? -1 : cost[P(N, 0)];
    cout << ans << "\n";
    return 0;
}