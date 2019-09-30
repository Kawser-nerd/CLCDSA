#include <stdio.h>
#include <stdlib.h>
int dp[10001][51][51]={0};
int w,n,k;
int a[50][2];

int sol2(int x, int wid,int num){
    //printf("%d %d %d\n",x,wid,num);
    if(dp[wid][x][num])return dp[wid][x][num];
    if(x==n-1){
        if(wid+a[x][0]<=w&&num<k){
            return a[x][1];
        }else{
            return 0;
        }
    }
    int i;
    int l=0;
    if(wid+a[x][0]<=w&&num<k)l=sol2(x+1,wid+a[x][0],num+1)+a[x][1];
    int m=sol2(x+1,wid,num);
    return dp[wid][x][num]=(l>m?l:m);
}

int main(){
    scanf("%d %d %d",&w,&n,&k);
    int i;
    for(i=0;i<n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    int ans=sol2(0,0,0);
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&w,&n,&k);
     ^
./Main.c:28:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a[i][0],&a[i][1]);
         ^