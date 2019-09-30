#include <stdio.h>
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    int hako[N+1];
    hako[1]=1;
    int ans=0;
    for(int i=2;i<N+1;i++)hako[i]=0;
    int hakokazu[N+1];
    for(int i=1;i<N+1;i++)hakokazu[i]=1;
    int a,b;
    for(int i=0;i<M;i++){
        scanf("%d %d",&a,&b);
        if(hako[a]==1&&hakokazu[a]==1){hako[a]=0;hakokazu[a]=0;hakokazu[b]++;hako[b]=1;}
        else if(hako[a]==1&&hakokazu[a]!=1){hako[a]=1;hako[b]=1;hakokazu[a]--;hakokazu[b]++;}
        else if(hako[a]==0){hakokazu[a]--;hakokazu[b]++;}
        
    }
    for(int i=0;i<N;i++)ans+=hako[i+1];
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&a,&b);
         ^