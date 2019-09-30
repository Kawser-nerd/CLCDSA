#include <stdio.h>
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    int flag=0;
    int a[200001]={};
    int kari1,kari2;
    for(int i=0;i<M;i++){
        scanf("%d %d",&kari1,&kari2);
        if(kari1==1)a[kari2]++;
        if(a[kari2]==2)flag=1;
        if(kari2==N)a[kari1]++;
        if(a[kari1]==2)flag=1;
    }
    if(flag==1)printf("POSSIBLE");
    else printf("IMPOSSIBLE");
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&kari1,&kari2);
         ^