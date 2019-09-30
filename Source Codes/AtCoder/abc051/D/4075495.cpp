#include <iostream>

using namespace std;

int main(){
    int N, M;
    long d[100][100];
    long e[100][100];
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        d[i][i] = 0;
        for(int j = 0; j < N; j++){
            d[i][j] = INT32_MAX;
            e[i][j] = INT32_MAX;
        }
    }
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a-1][b-1] = c;
        d[b-1][a-1] = c;
        e[a-1][b-1] = c;
        e[b-1][a-1] = c;
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            
            if(e[i][j] != INT32_MAX && e[i][j] > d[i][j] && i != j) ans++;
        }
    }
    cout << ans << endl;
}