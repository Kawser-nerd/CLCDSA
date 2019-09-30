#include <stdio.h>
int main(void){
    int n,k,t[3],i;
    scanf("%d%d",&n,&k);
    scanf("%d%d",&t[0],&t[1]);
    for(i=0;i<n-2;i++){
        scanf("%d",&t[2]);
        if(t[0]+t[1]+t[2]<k){
            printf("%d\n",i+3);
            return 0;
        }
        t[0]=t[1];
        t[1]=t[2];
    }
    printf("-1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&t[0],&t[1]);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t[2]);
         ^