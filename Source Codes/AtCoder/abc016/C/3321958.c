#include <stdio.h>

int main(void){
    int n,m,a,b;
    scanf("%d%d",&n,&m);
    int cost[n][n];
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cost[i][j]=1e9;
        }
        cost[i][i]=0;
    }
    for (int i=0; i<m; i++){
        scanf("%d%d",&a,&b);
        a--;
        b--;
        cost[a][b]=1;
        cost[b][a]=1;
    }
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (cost[i][j]>cost[i][k]+cost[k][j]){
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }
    for (int i=0; i<n; i++){
        int ans=0;
        for (int j=0; j<n; j++){
            if (cost[i][j]==2){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&a,&b);
         ^