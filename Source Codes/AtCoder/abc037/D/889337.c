#include<stdio.h>
#define REP(i,n) for(i=0;i<(n);i++)
#define M 1000000007

int W,H;
int A[1000][1000];
int dp[1000][1000]={0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};




int foo(int y,int x){
    int i;
    int ret = 1;
    if (dp[y][x])return dp[y][x];
    REP(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx <= W-1 && ny <= H-1){
            if (A[ny][nx]>A[y][x]){
                ret = (ret+foo(ny,nx))%M;
            }
        }
    }
    dp[y][x] = ret%M;
    return dp[y][x];
}




void solve(){
    int i,j;
    int ans = 0;
    REP(i,H)
        REP(j,W)
            ans =(ans + foo(i,j))%M;
    printf("%d\n",ans);
}

int main(void){
    int i,j;
    scanf("%d %d",&H,&W);
    REP(i,H)
        REP(j,W)
            scanf("%d",&A[i][j]);
       
    solve();
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&H,&W);
     ^
./Main.c:48:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&A[i][j]);
             ^