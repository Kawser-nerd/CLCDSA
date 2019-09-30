/**********************************************************************
Author: hanshuai
Created Time:  7/29/2011 9:53:57 AM
File Name: b.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long LL;
const int INF = 123456789;
const int maxn = 25;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int a[maxn][maxn], h[maxn][maxn];
int H, W, M;
bool vis[maxn][maxn];
queue<pair<int,int> > que;
void push(int x, int y){
    if(vis[x][y]) return;
    vis[x][y] = true;
    que.push(make_pair(x, y));
}
void calH(){
    memset(vis, false, sizeof(vis));
    while(!que.empty()) que.pop();
    for(int i = 0; i <= H+1; i ++){
        for(int j = 0; j <= W+1; j ++) h[i][j] = INF;
    }
    for(int i = 0; i <= H+1; i ++){
        h[i][0] = 0;
        push(i, 0);
        h[i][W+1] = 0;
        push(i, W+1);
    }
    for(int i = 0; i <= W+1; i ++){
        h[0][i] = 0;
        push(0, i);
        h[H+1][i] = 0;
        push(H+1, i);
    }
    while(!que.empty()){
        pair<int,int> q = que.front(); que.pop();
        int x = q.first, y = q.second;
        for(int k = 0; k < 4; k ++){
            int tx = x + dx[k], ty = y + dy[k];
            if(tx < 0 || tx > H + 1 || ty < 0 || ty > W + 1) continue;
            int cost = max(a[tx][ty], h[x][y]);
            if(h[tx][ty] > cost){
                h[tx][ty] = cost;
                push(tx, ty);
            }
        }
        vis[x][y] = false;
    }
}
void out(int b[maxn][maxn]){
    printf("\n");
    for(int i = 1; i <= H; i ++){
        for(int j = 1; j <= W; j ++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
bool ok(){
    for(int i = 1; i <= H; i ++){
        for(int j = 1; j <= W; j ++){
            if(a[i][j] != 0) return false;
        }
    }
    return true;
}
void solve(){
    scanf("%d%d%d", &H, &W, &M);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= H; i ++){
        for(int j = 1; j <= W; j ++){
            scanf("%d", &a[i][j]);
        }
    }
    int step = 0;
    while(1){
        if(ok()) break;
        step ++;
        calH();
        for(int i = 1; i <= H; i ++){
            for(int j = 1; j <= W; j ++){
                int mc = INF;
                for(int k = 0; k < 4; k ++){
                    int tx = i + dx[k], ty = j + dy[k];
                    mc = min(mc, h[tx][ty]);
                }
                a[i][j] -= min(max(h[i][j]-mc, 0), M);
                a[i][j] = max(a[i][j], 0);
            }
        }
//        out(a);
//        break;
    }
    printf("%d\n", step);
}
int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int test, cas = 0;
    scanf("%d", &test);
    while(test --){
        printf("Case #%d: ", ++cas);
        solve();
    }
    return 0;
}

