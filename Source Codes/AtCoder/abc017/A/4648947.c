#include <stdio.h>
int main(void){
    int s,e,v=0,i;
    for(i=0;i<3;i++){
        scanf("%d%d",&s,&e);
        v+=s*e/10;
    }
    printf("%d\n",v);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&s,&e);
         ^