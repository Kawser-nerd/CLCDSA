#include <stdio.h>
int main(void){
    int k,s,v=0,x=0;
    scanf("%d%d",&k,&s);
    while(s>=0){
        if(x>k) break;
        v+=(s<=2*k)?s+1-(s>=k?s-k:0)*2:0;
        s--;
        x++;
    }
    printf("%d\n",v);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&k,&s);
     ^