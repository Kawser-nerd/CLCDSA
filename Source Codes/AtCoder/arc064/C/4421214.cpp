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
typedef long double ld;
using namespace std;

ld inf = 1e18;
int n;
typedef pair<ld, int> P;
ld cost[1005];
vector<P> edge[1005];

void dijkstra() {
    priority_queue < P, vector<P>, greater<P> > q;
    for (int i = 0; i < n+2; i++) cost[i] = inf;
    cost[0] = 0.0;
    q.push(P(0.0, 0));

    while (!q.empty()) {
        P p = q.top(); q.pop();
        int node = p.second;
        if (cost[node] < p.first) continue;
        for (P next : edge[node]) {
            int next_node = next.second;
            ld c = next.first;

            if (cost[next_node] > cost[node] + c) {
                cost[next_node] = cost[node] + c;
                q.push(P(cost[next_node], next_node));
            }
        }
    }
}

int main() {
    ld x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2 >> n;

    vector <ld> X(n+2), Y(n+2), R(n+2);
    X[0] = x1; Y[0] = y1; R[0] = 0.0;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i] >> R[i];
    }
    X[n+1] = x2; Y[n+1] = y2; R[n+1] = 0.0;

    for (int i = 0; i < n+2; i++) {
        for (int j = i+1; j < n+2; j++) {
            ld distance = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
            ld c = max((ld)0, distance - R[i] - R[j]);
            edge[i].push_back(P(c, j));
            edge[j].push_back(P(c, i));
        }
    }

    dijkstra();

    cout << fixed << setprecision(12) << cost[n+1] << '\n';
    return 0;
}