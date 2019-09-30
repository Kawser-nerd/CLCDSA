#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int k=n/9;
    int r=n%9;
    int i;
    if(n==9||n==18||n==27||n==36||n==45)k--;
    for(i=0;i<=k;i++){
        if(r==0)printf("9");
        else printf("%d",r);
    }
    printf("\n");
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^