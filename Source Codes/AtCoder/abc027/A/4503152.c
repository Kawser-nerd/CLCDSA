#include <stdio.h>
int main(void){
    // Your code here!
    int n,m,l;
    scanf("%d%d%d",&n,&m,&l);
    if(n==m) printf("%d\n",l);
    else if(n==l) printf("%d\n",m);
    else printf("%d\n",n);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&m,&l);
     ^