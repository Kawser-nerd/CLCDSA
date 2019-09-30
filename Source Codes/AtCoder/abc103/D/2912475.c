#include <stdio.h>
#include <stdlib.h>

//???????????
typedef struct pair{int x,y;}point;

int pcmp(const void*a,const void*b){
    if((*(point*)a).y<(*(point*)b).y)return -1;
    return 1;
}


point kukan[100010];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        kukan[i].x=x;
        kukan[i].y=y;
    }
    
    qsort(kukan,m,sizeof(point),pcmp);
    
    int pre=-1;
    int ans=0;
    
    for(int i = 0;i < m;i++){
        if(pre<kukan[i].x){
            ans++;
            pre=kukan[i].y-1;
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&x,&y);
         ^