#include <stdio.h>
#define max(a,b) a>b?a:b
int main(void){
    int d[7],j[7],i,sum=0;
    for(i=0;i<7;i++){
        scanf("%d",&d[i]);
    }
    for(i=0;i<7;i++){
        scanf("%d",&j[i]);
    }
    for(i=0;i<7;i++){
        sum+=max(d[i],j[i]);
    }
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&d[i]);
         ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&j[i]);
         ^