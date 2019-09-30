#include <stdio.h>

int T[5][5];
int flag=0;
int N,K;

void dfs(int a,int b,int c){
    if(flag==0){
        c=c^T[a][b];
    if(a==N-1){
        if(c==0){flag=1;}
    }
    else{
        for(int j=0;j<K;j++){
            dfs(a+1,j,c);
        }
    }
    }
}

int main(void){
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++)for(int j=0;j<K;j++){
        scanf("%d",&T[i][j]);
    }
    for(int i=0;i<K;i++)dfs(0,i,0);
    if(flag==1)printf("Found\n");
    else printf("Nothing\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&K);
     ^
./Main.c:24:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&T[i][j]);
         ^