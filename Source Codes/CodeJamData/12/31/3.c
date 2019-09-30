#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[1001][1001];
int n;
char used[1001];
int ok;
int dp[1001][1001];
int main(){
    int Case = 0;
    int t;
    int i,j,k;
    int num;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(map,0,sizeof(map));
        memset(used,0,sizeof(used));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;++i){
            scanf("%d",&num);
            while(num--){
                scanf("%d",&j);
                map[i][j] = 1;
                dp[i][j] = 1;
            }
        }
        for(k=ok=1;k<=n&&ok;++k){
            for(i=1;i<=n&&ok;++i){
                for(j=1;j<=n&&ok;++j){
                    if(dp[i][k] && dp[k][j]){
                        ++dp[i][j];
                    }
                    if(dp[i][j]==2)ok=0;
                }
            }
        }

        printf("Case #%d:",++Case);
        if(!ok)puts(" Yes");
        else puts(" No");
    }
    return 0;
}
