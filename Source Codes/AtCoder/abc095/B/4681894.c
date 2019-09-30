#include <stdio.h>
int main(void){
    int n,x,m,i,min=1001;
    scanf("%d%d",&n,&x);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        x-=m;
        if(m<min) min=m;
    }
    printf("%d\n",n+x/min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&x);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&m);
         ^