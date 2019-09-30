#include <stdio.h>
int main(void){
    int n,T,c,t,cmin=1001,i;
    scanf("%d%d",&n,&T);
    for(i=0;i<n;i++){
        scanf("%d%d",&c,&t);
        if(t<=T && c<cmin) cmin=c;
    }
    if(cmin==1001) printf("TLE\n");
    else printf("%d\n",cmin);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&T);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&c,&t);
         ^