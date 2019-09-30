#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
char s[205];
char a[205][205];
int d[205][205];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main() {
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    int cn;
    cin>>cn;
    for(int ci = 0; ci<cn;ci++) {
        memset(a,0,sizeof(a));
        int n;
        int ans =10000000;
        cin>>n;
        gets(a[0]);
        int m = 2*n-1;
        for(int i=1;i<=m;i++) {
            gets(s);
            for(int j=1;j<=m;j++) {
                a[i][j]=s[j-1];
            }
        }
        for(int x =0;x<=m+1;x++){
            for(int y = 0;y<=m+1;y++){
                if(1){
                    int t=1000;
                    int p = abs(x-n)+abs(y-n);
                    //cout<<x<<','<<y<<';'<<p<<endl;
                    int flag = 1;
                    for(int i = 0;i<=m+1;i++) {
                        for(int j=0;j<=m+1;j++) {
                            if(abs(i-n)+abs(j-n)<n){
                                if(a[i][j]>='0' && a[i][j]<='9') {
                                    int tx,ty;
                                    int ti = x+(x-i);
                                    int tj = y+(y-j);
                                    if(abs(ti-n)+abs(j-n)<n && a[i][j] != a[ti][j] ||
                                       abs(i-n)+abs(tj-n)<n && a[i][j] != a[i][tj])
                                        flag = 0;
                                }
                            }
                        }
                    }
                    if(flag) {
                        ans=min(ans,(n+p)*(n+p)-n*n);
                    }
                }
            }
        }
        printf("Case #%d: %d\n",ci+1,ans);
    }
    return 0;
}
