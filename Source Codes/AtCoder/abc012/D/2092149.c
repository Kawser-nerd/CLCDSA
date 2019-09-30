#include <stdio.h>
#include <stdlib.h>
#define INF 1e9
int N,M;
int d[300][300];
int Min(int a,int b){
    return a<b?a:b;
}
void wf(int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                d[j][k]=Min(d[j][i]+d[i][k],d[j][k]);
            }
        }
    }
}

int main(){
    scanf("%d %d",&N,&M);
    int i,j,k;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==j){
                d[i][j]=0;
            }else{
                d[i][j]=INF;
            }
        }
    }
    for(i=0;i<M;i++){
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);
        d[a-1][b-1]=t;
        d[b-1][a-1]=t;
    }
    wf(N);
    /*
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d ",d[i][j]);
        }
        puts("");
    }
    */
    int n_max;
    int n_max_min=INF;
    for(i=0;i<N;i++){
        n_max=0;
        for(j=0;j<N;j++){
            if(n_max_min<d[i][j])break;
            if(n_max<d[i][j])n_max=d[i][j];
            if(j==N-1)n_max_min=n_max;
        }
    }
    printf("%d\n",n_max_min);
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:34:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d",&a,&b,&t);
         ^