#include <iostream>
#include <algorithm>
#include <vector>

#define N 10
#define INF (1 << 30)

using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::min;

void dump(const vector<int>& v){
    for(int i : v){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> dijkstra(const int c[N][N]) {
    vector<int> d(N);
    for(int i = 0; i < N; i++){
        d[i] = INF;
    }
    d[1] = 0;

    vector<int> q;
    for(int i = 0; i < N; i++){
        q.push_back(i);
    }

    while (q.size() != 0) {
        int v = q[0];
        for(int u : q){
            if(d[u] < d[v]){
                v = u;
            }
        }
        q.erase(remove(q.begin(), q.end(), v), q.end());

        for(int u = 0; u < N; u++){
            d[u] = min(d[u], d[v] + c[u][v]);
        }
    }

    return d;
}

int main() {
    int h, w;
    cin >> h >> w;

    int c[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
        }
    }

    vector<int> cost = dijkstra(c);

    int sum = 0;
    for (int q = 0; q < h * w; q++) {
        int x;
        cin >> x;
        if(x == -1){
            continue;
        }
        sum += cost[x];
    }

    cout << sum << endl;

    return 0;
}