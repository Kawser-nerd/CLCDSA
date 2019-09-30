#include <stdio.h>

int N,M,R,r[8],cost[201][201];

int dfs(int now){
    int i,ret,rt,tmpcost,flag;
    flag = 0;
    ret = 1000000000;
    for(i=0;i<R;i++){
        if(r[i]>0){
            rt=r[i];
            r[i]=0;
            tmpcost = cost[now][rt] + dfs(rt);
            r[i]=rt;
            if(tmpcost<ret)ret=tmpcost;
            flag=1;
        }
    }
    return (flag?ret:0);
}

int main(){
    int a,b,c;
    int i,j,k;

    scanf("%d %d %d",&N,&M,&R);
    for(i=0;i<R;i++){
        scanf("%d",&r[i]);
    }

    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            cost[i][j]=100000000;
        }
        cost[0][i]=cost[i][0]=cost[i][i]=0;
    }

    for(i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&c);
        cost[a][b] = cost[b][a] = c;
    }

    /* ????????? */
    for(k=1;k<=N;k++){
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                if(cost[i][j] > cost[i][k] + cost[k][j]){
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    printf("%d\n",dfs(0));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&N,&M,&R);
     ^
./Main.c:28:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&r[i]);
         ^
./Main.c:39:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&a,&b,&c);
         ^