#include <stdio.h>
int main(void){
    int i,n,k,p=1;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        p=(p*2<p+k?p*2:p+k);
    }
    printf("%d\n",p);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^