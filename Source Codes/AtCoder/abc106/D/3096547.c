#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>


//?????????????????
/*

500*500????????
???????????
????????????????????
????????
*/
int main(void){
    int N,M,Q,counter = 0;
    int i,j;
    scanf("%d %d %d",&N,&M,&Q);
    int L[M],R[M],p[Q],q[Q];
    int grid[N+1][N+1];
    for(i=0;i<=N;i++){
        for(j=0;j<=N;j++){
            grid[i][j] = 0;
        }
    }
    for(i=0;i<M;i++){
        scanf("%d %d",&L[i],&R[i]);
        grid[L[i]][R[i]]++;
    }
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            grid[i][j] += grid[i][j-1];
        }
    }
    for(i=0;i<Q;i++){
        scanf("%d %d",&p[i],&q[i]);
    }
    for(i=0;i<Q;i++){
        for(j=p[i];j<=q[i];j++){
            counter += grid[j][q[i]]-grid[j][p[i]-1];
        }
        printf("%d\n",counter);
        counter = 0;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&N,&M,&Q);
     ^
./Main.c:27:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&L[i],&R[i]);
         ^
./Main.c:36:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&p[i],&q[i]);
         ^