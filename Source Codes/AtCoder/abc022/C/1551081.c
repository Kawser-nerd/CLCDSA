#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}

void warshall_floyd(int (*cost)[300], int n){
    int i,j,k;
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            for(k=1;k<n;k++){
                //printf("[%d][%d][%d]%d %d+%d",j,i,k,cost[j][k], cost[j][i], cost[i][k]);
                cost[j][k]=min(cost[j][k], cost[j][i]+cost[i][k]);
                //printf("cost=%d\n",cost[j][k]);
            }
        }
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int i,j;
    int INF = 100000000;
    int cost[300][300];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cost[i][j]=INF;
        }
    }
    for(i=0;i<N;i++){
        cost[i][i]=0;
    }

    int u,v,l;
    for(i=0;i<M;i++){
        scanf("%d %d %d", &u,&v,&l);
        cost[u-1][v-1]=l;
        cost[v-1][u-1]=l;
    }

    warshall_floyd(cost, N);

    int ans=INF;
    for(i=1;i<N-1;i++){
        for(j=i+1;j<N;j++){
            if(cost[0][i]<INF){
                if(cost[0][j]<INF){
                    //printf("ans=%d [%d][%d]%d+%d+%d\n",ans,i,j,cost[0][i],cost[i][j],cost[0][j]);
                    ans=min(ans,cost[0][i]+cost[i][j]+cost[0][j]);
                }
            }
        }
    }
    if(ans!=INF){
        printf("%d\n", ans);
    }else{
        printf("-1\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:44:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &u,&v,&l);
         ^