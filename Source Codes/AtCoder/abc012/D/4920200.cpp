//
// Created by Tetsuya Shiota on 2019-04-12.
//

#include<iostream>

using namespace std;

int main(){
    int N, M;
    const int inf = 1e9;
    cin >> N >> M;

    int cost[N][N];

    for(int i = 0; i<N; i++){
        for(int j =0; j<N; j++){
            cost[i][j] =inf;
        }
        cost[i][i] = 0;
    }

    for(int i = 0; i<M; i++){
        int a, b, t;
        cin >> a >> b >> t;
        a--;b--;
        cost[a][b] = cost[b][a] = t;
    }

    for(int k = 0; k< N; k++){
        for(int i = 0; i<N; i++) {
            for (int j = 0; j < N; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    int ans = inf;

    for(int start = 0; start <N; start++){
        int maxi = 0;
        for(int to =0; to <N; to++){
            maxi = max(maxi, cost[start][to]);
        }
        ans = min(ans, maxi);
    }
    cout << ans <<endl;


}