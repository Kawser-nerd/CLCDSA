#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int N=20;
int n,m,M;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

int Q[N*N][2],a[N][N],water[N][N],vis[N][N],low[N][N];

bool check(){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]) return false;
    return true;
}

int front,back;
void push(int x,int y){
    if (vis[x][y]) return;
    vis[x][y]=1;
    Q[back][0]=x;
    Q[back][1]=y;
    back++;
}
int main(){
    int T,cas;
    scanf("%d",&T);
    for (cas=1;cas<=T;cas++){
        scanf("%d%d%d",&n,&m,&M);
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        int ans=0;
        while (not check()){
            int maxh=0;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                    maxh=max(a[i][j],maxh);
            memset(water,0,sizeof(water));
            for (int h=maxh;h>0;h--){
                memset(vis,0,sizeof(vis));
                front=0, back=0;
                for (int i=1;i<=n;i++){
                    if (a[i][1]<h) push(i,1);
                    if (a[i][m]<h) push(i,m);
                }
                for (int i=1;i<=m;i++){
                    if (a[1][i]<h) push(1,i);
                    if (a[n][i]<h) push(n,i);
                }
                while (front<back){
                    int x=Q[front][0];
                    int y=Q[front][1];
                    front++;
                    for (int k=0;k<4;k++){
                        int x1=x+dir[k][0];
                        int y1=y+dir[k][1];
                        if (x1<1||x1>n) continue;
                        if (y1<1||y1>m) continue;
                        if (vis[x1][y1]) continue;
                        if (a[x1][y1]>=h) continue;
                        push(x1,y1);
                    }
                }
                for (int i=1;i<=n;i++)
                    for (int j=1;j<=m;j++)
                        if (!vis[i][j]) water[i][j]=max(water[i][j],h);
            }
/*
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++)
        printf("%3d",water[i][j]);
    printf("\n");
}puts(".");
*/
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++){
                    int mini=water[i][j];
                    if (i==1||i==n) mini=0;
                    if (j==1||j==m) mini=0;
                    for (int k=0;k<4;k++){
                        int x1=i+dir[k][0];
                        int y1=j+dir[k][1];
                        if (water[i][j]>=water[x1][y1])
                            mini=min(mini,water[x1][y1]);
                    }
                    low[i][j]=mini;
                }
/*
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++)
        printf("%3d",low[i][j]);
    printf("\n");
}puts(".");
*/
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                    a[i][j]-=min(water[i][j]-low[i][j],M);
/*
for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++)
        printf("%3d",a[i][j]);
    printf("\n");
}puts("*");
*/
            ans++;
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}

