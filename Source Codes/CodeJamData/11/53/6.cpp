/**********************************************************************
Author: hanshuai
Created Time:  2011/6/11 23:02:59
File Name: C.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 10005;
const int MOD = 1000003;
int R, C;
vector<int> vec[maxn], vecB[maxn];
char s[105][105];
int ID(int x, int y){
    while(x < 0) x += R;
    while(x >= R) x -= R;
    while(y < 0) y += C;
    while(y >= C) y -= C;
    return x*C+y;
}
int deg[maxn];
bool vis[maxn], visB[maxn];
int cnt, cntB;
void dfs(int v);
void dfsB(int v){
    if(visB[v]) return;
    cntB ++;
    visB[v] = true;
    for(int i = 0; i < (int)vecB[v].size(); i ++){
        dfs(vecB[v][i]);
    }
}
void dfs(int v){
    if(vis[v]) return;
    cnt ++;
    vis[v] = true;
    for(int i = 0; i < (int)vec[v].size(); i ++){
        dfsB(vec[v][i]);
    }
}
int solve(){
    memset(deg, 0, sizeof(deg));
    memset(vis, false, sizeof(vis));
    memset(visB, false, sizeof(visB));
    for(int i = 0; i < R*C; i ++){
        for(int j = 0; j < (int)vec[i].size(); j ++){
            vecB[vec[i][j]].push_back(i);
            deg[vec[i][j]] ++;
        }
    }
    int ans = 1;
    for(int i = 0; i < R*C; i ++){
        if(!vis[i]){
            cnt = cntB = 0;
            dfs(i);
            if(cnt != cntB) return 0;
            ans = (ans*2)%MOD;
        }
    }
    for(int i = 0; i < R*C; i ++){
        if(!visB[i]){
            cnt = cntB = 0;
            dfsB(i);
            if(cnt != cntB) return 0;
            ans = (ans*2)%MOD;
        }
    }
    return ans;
}
int main() {
    freopen("C.out", "w", stdout);
    int test, cas = 0;
    scanf("%d", &test);
    while(test --){
        printf("Case #%d: ", ++cas);
        scanf("%d%d", &R, &C);
        for(int i = 0; i < R*C; i ++){
            vec[i].clear(); vecB[i].clear();
        }
        for(int i = 0; i < R; i ++){
            scanf("%s", s[i]);
            for(int j = 0; j < C; j ++){
                int id = ID(i, j);
                if(s[i][j] == '|'){
                    vec[id].push_back(ID(i-1, j));
                    vec[id].push_back(ID(i+1, j));
                }else if(s[i][j] == '-'){
                    vec[id].push_back(ID(i, j-1));
                    vec[id].push_back(ID(i, j+1));
                }else if(s[i][j] == '/'){
                    vec[id].push_back(ID(i-1, j+1));
                    vec[id].push_back(ID(i+1, j-1));
                }else if(s[i][j] == '\\'){
                    vec[id].push_back(ID(i-1, j-1));
                    vec[id].push_back(ID(i+1, j+1));
                }
            }
        }
        printf("%d\n", solve());
        fprintf(stderr, "cas = %d\n", cas);
    }
    return 0;
}

