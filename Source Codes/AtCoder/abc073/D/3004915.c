#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int n,m,r,ans=1e9,tmp,count;
int d[10],a[20000],b[20000],c[20000],cost[300][300];
bool visited[10];

int dfs(int a,int b){
    visited[b]=true;
    count++;
    tmp+=cost[d[a]][d[b]];
    if (count>=r-1){
        if(tmp<ans){
            ans=tmp;
        }
    } else {
        for (int i=0; i<r; i++){
            if (visited[i]==false){
                dfs(b,i);
                visited[i]=false;
            }
        }
    }
    count--;
    tmp-=cost[d[a]][d[b]];
    return 0 ;
}

int main(void){
    scanf("%d%d%d",&n,&m,&r);
    for (int i=0; i<r; i++){
        scanf("%d",&d[i]);
        d[i]--;
    }
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            cost[i][j]=1e9;
        }
    }
    for (int i=0; i<m; i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        cost[a[i]-1][b[i]-1]=c[i];
        cost[b[i]-1][a[i]-1]=c[i];
    }
    for (int k=0; k<=n; k++){
        for (int i=0; i<=n; i++){
            for (int j=0; j<=n; j++){
                if (cost[i][j]>cost[i][k]+cost[k][j]){
                    cost[i][j]=cost[i][k]+cost[k][j];
                }
            }
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<r; j++){
            if (i!=j){
                visited[i]=true;
                dfs(i,j);
                visited[j]=false;
                visited[i]=false;
            }
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&m,&r);
     ^
./Main.c:36:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&d[i]);
         ^
./Main.c:45:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&a[i],&b[i],&c[i]);
         ^