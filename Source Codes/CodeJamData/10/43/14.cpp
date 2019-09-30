#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
const int MXN = 2002;
int x[MXN], y[MXN], tx[MXN], ty[MXN];
int a[MXN][MXN];
int q[MXN*MXN][2];
int dx[6]={1,0,1,-1,0,-1};
int dy[6]={-1,1,0,1,-1,0};
int xmax,ymax,ans;
int floodfill(int x,int y) {
    int m = 1;
    int k = 0;
    q[0][0]=x;
    q[0][1]=y;
    a[x][y] = 0;
    while(k<m) {
        int x=q[k][0];
        int y=q[k][1];
        for(int i =0;i<6;i++) {
            int tx=q[k][0]+dx[i];
            int ty=q[k][1]+dy[i];
            if(a[tx][ty]) {
                q[m][0] = tx;
                q[m][1] = ty;
                a[tx][ty] =0;
                m++;
            }
        }
        k++;
    }
    int xmax= 0;
    int ymax = 0;
    for(int i =0;i<m;i++) {
        xmax=max(xmax,tx[q[i][0]+1]);
        ymax=max(ymax,ty[q[i][1]+1]);
    }
    for(int i =0;i<m;i++) {
        ans = max(ans,xmax-tx[q[i][0]]+ymax-ty[q[i][1]]);
    }
}
int main() {
    freopen("C-large.in","r",stdin);
    freopen("c.out","w",stdout);
    int cn;
    cin>>cn;
    for(int ci = 0; ci<cn;ci++) {
        int m;
        cin>>m;
        for(int i = 1;i<=m;i++) {
            scanf("%d%d%d%d",&y[i*2-1],&x[i*2-1],&y[i*2],&x[i*2]);
            x[i*2]+=1;
            y[i*2]+=1;
        }
        for(int i = 1;i<=m*2;i++){
            tx[i] = x[i];
            ty[i] = y[i];
        }
        sort(tx+1,tx+m*2+1);
        sort(ty+1,ty+m*2+1);
        int k = 2;
        for(int i = 2;i<=m*2;i++){
            if(tx[i]!=tx[i-1]) {
                tx[k] = tx[i];
                k++;
            }
        }
        int k1= k;
        k = 2;
        for(int i = 2;i<=m*2;i++){
            if(ty[i]!=ty[i-1]) {
                ty[k] = ty[i];
                k++;
            }
        }
        int k2=k;
        for(int i =1;i<=m*2;i++) {
            for(int j=1;j<=k1;j++) {
                if(x[i]==tx[j]) {
                    x[i] = j;
                    break;
                }
            }
        }
        for(int i =1;i<=m*2;i++) {
            for(int j=1;j<=k2;j++) {
                if(y[i]==ty[j]) {
                    y[i] = j;
                    break;
                }
            }
        }
        memset(a,0,sizeof(a));
        for(int i = 1;i<=m;i++) {
            for(int j=x[i*2-1];j<x[i*2];j++)
                for(int k=y[i*2-1];k<y[i*2];k++)
                    a[j][k] = 1;
        }
        ans = 0;
        for(int i=1;i<=k1;i++) 
            for(int j=1;j<=k2;j++)
                if(a[i][j]) 
                    floodfill(i,j);
        printf("Case #%d: %d\n",ci+1,ans-1);
    }
    return 0;
}
