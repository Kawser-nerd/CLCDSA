#include<stdio.h>
#define rep(i,n) for(i=0;i<n;i++)
int in(){int x;scanf("%d",&x);return x;}
void print(int x){printf("%d\n",x);}
int min(int x, int y){if(x>y)return y;else return x;}
int main(void){int i,j,k,n=in(),m=in(),a[2*m],dis[n][n],c[n];rep(i,n)rep(j,n)dis[i][j]=100;rep(i,n){dis[i][i]=0;c[i]=0;}rep(i,m){a[2*i]=in();a[2*i+1]=in();dis[a[2*i]-1][a[2*i+1]-1]=dis[a[2*i+1]-1][a[2*i]-1]=1;}rep(i,n)rep(j,n)rep(k,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);rep(i,n)rep(j,n)if(dis[i][j]==2)c[i]++;rep(i,n)print(c[i]);return 0;} ./Main.c: In function ‘in’:
./Main.c:3:16: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int in(){int x;scanf("%d",&x);return x;}
                ^