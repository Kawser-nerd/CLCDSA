#include<stdio.h>
int main(void){
    int n,m,i,sum,tm=0,stm;
    int t[100001],p,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&t[i]);
        tm+=t[i];
    }
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&p,&x);
        stm=tm-(t[p-1]-x);
        printf("%d\n",stm);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t[i]);
         ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&m);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d",&p,&x);
         ^