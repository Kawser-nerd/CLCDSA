#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int f[12][1026][12];
int a[12][1026];
int main() {
    freopen("B-large.in","r",stdin);
    freopen("b.out","w",stdout);
    int cn;
    cin>>cn;
    for(int ci = 0; ci<cn;ci++) {
        int p, n;
        cin>>p;
        n = 1 << p;
        memset(f,0,sizeof(f));
        int sum = 0;
        for(int i = 1;i<=n;i++) {
            int x;
            cin>>x;
            for(int j = x+1;j<=p;j++) {
                f[p][i][j] = -1;
            }
        }
        for(int i = p-1; i>=0;i--) {
            for(int j=1; j<=1<<i;j++) {
                cin>>a[i][j];
                sum+=a[i][j];
            }
        }
        for(int i = p-1; i>=0;i--) {
            for(int j=1; j<=1<<i;j++) {
                for(int k = 0;k<=i;k++) {
                    int x,y;
                    x = j*2;
                    y = j*2-1;
                    if(f[i+1][x][k] >=0 && f[i+1][y][k] >= 0) {
                        f[i][j][k] = f[i+1][x][k]+f[i+1][y][k];
                        if (f[i+1][x][k+1] >=0 && f[i+1][y][k+1] >= 0) {
                            f[i][j][k] = max(f[i][j][k],f[i+1][x][k+1]+f[i+1][y][k+1]+a[i][j]);
                            //printf("%d, %d, %d, %d, %d\n",i,j,k,a[i][j],f[i][j][k]);
                        }
                    } else {
                        f[i][j][k] = -1;
                    }
//                    printf("%d, %d, %d: %d (%d, %d)\n",i,j,k,f[i][j][k],x,y);
                }
            }
        }
        /*for(int i = p; i>=0;i--) 
            for(int j=1; j<=1<<i;j++)
                for(int k = 0;k<=i;k++)
                    printf("%d, %d, %d: %d\n",i,j,k,f[i][j][k]);*/
        printf("Case #%d: %d\n",ci+1,sum-f[0][1][0]);
    }
    return 0;
}
