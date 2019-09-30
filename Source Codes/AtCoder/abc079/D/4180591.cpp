#include <iostream>

using namespace std;

int c[10][10];
int cost[10];
bool used[10];

void dfs(int n, int cst){
    //cout << n << ':' << cst << ' ';
    used[n] = true;
    cost[n] = min(cst, cost[n]);
    for(int i = 0; i < 10; i++){
        if(!used[i]) dfs(i, cst+c[i][n]);
    }
    used[n] = false;
}

int main(){
    int H, W;
    long ans = 0;
    cin >> H >> W;
    for(int i = 0; i < 10; i++){
        cost[i] = INT32_MAX;
        used[i] = false;
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> c[i][j];
        }
    }
    dfs(1, 0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int A;
            cin >> A;
            if(A != -1) ans += cost[A];
        }
    }
    
    cout << ans << endl;
}