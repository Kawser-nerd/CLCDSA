#include <stdio.h>
#include <stdlib.h>

int s=0;
int ans=0;
int visit[12]={};
int N,M;
typedef struct{
    int r[12];
}person;
person p[12];

void dfs(int v){
    if(v!=-1)visit[v]=1;
    int i,j;
    for(i=v+1;i<N;i++){
        if(v==-1)dfs(i);
        else if(!visit[i]){
            for(j=0;j<N;j++){
                if(visit[j]==1 && p[i].r[j]!=1)break;
                if(j==N-1)dfs(i);
            }
        }
    }
    if(v==-1)return;
    int tmp=0;
    for(i=0;i<N;i++){
     //   printf("%d",visit[i]);
        if(visit[i]==1)tmp++;
    }
    //printf("\n tmp=%d\n",tmp);
    if(ans<tmp)ans=tmp;
    visit[v]=0;
}

int main()
{
    scanf("%d %d",&N,&M);
    int i,j;
    int x,y;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            p[i].r[j]=0;
        }
    }
    for(i=0;i<M;i++){
        scanf("%d %d",&x,&y);
        p[x-1].r[y-1]=1;
        p[y-1].r[x-1]=1;
    }
    dfs(-1);
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:47:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&x,&y);
         ^