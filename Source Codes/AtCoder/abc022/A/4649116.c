#include <stdio.h>
int main(void){
    int n,s,t,w,a,i,c=0;
    scanf("%d%d%d%d",&n,&s,&t,&w);
    if(w>=s && w<=t) c++;
    for(i=1;i<n;i++){
        scanf("%d",&a);
        if(w+a>=s && w+a<=t) c++;
        w+=a;
    }
    printf("%d\n",c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&n,&s,&t,&w);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a);
         ^