#include <stdio.h>
#include <stdlib.h>

#define INF 100000000
int R,G,B;
int sum;
int dp[2001][901];

int culRGB(v,n){
    if(n<R){
        return abs(v+100);
    }else if(n<R+G){
        return abs(v);
    }else{
        return abs(v-100);
    }
}

int DP(int v,int n){
    //printf("%d, %d\n",v,n);
    if(dp[v+1000][n]!=-1)return dp[v+1000][n];
    if(v>999)return INF;
    if(n==sum)return 0;
    int tmp1,tmp2;
    tmp1=DP(v+1,n+1)+ culRGB(v,n);
    tmp2=DP(v+1,n);
    dp[v+1000][n]=(tmp1 > tmp2 ? tmp2 : tmp1);
    return dp[v+1000][n];
}

int main()
{
    scanf("%d %d %d",&R,&G,&B);
    sum=R+G+B;
    memset(dp,-1,sizeof(dp));
    
    printf("%d\n",DP(-1000,0));
    return 0;
} ./Main.c: In function ‘culRGB’:
./Main.c:9:5: warning: type of ‘v’ defaults to ‘int’ [-Wimplicit-int]
 int culRGB(v,n){
     ^
./Main.c:9:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c: In function ‘main’:
./Main.c:35:5: warning: implicit declaration of function ‘memset’ [-Wimplicit-function-declaration]
     memset(dp,-1,sizeof(dp));
     ^
./Main.c:35:5: warning: incompatible implicit declaration of built-in function ‘memset’
./Main.c:35:5: note: include ‘<string.h>’ or provide a declaration of ‘memset’
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&R,&G,&B);
     ^