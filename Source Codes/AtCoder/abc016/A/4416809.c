#include <stdio.h>
int main(void){
    // Your code here!
    int n,m;
    scanf("%d%d",&n,&m);
    if(n%m==0)
        printf("YES\n");
    else
        printf("NO\n");
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^