#include<stdio.h>
int main(){
    int n, a, b, c;
    scanf("%d %d %d",&n, &a, &b);
    c = b;
    if(n*a < c)c=n*a;
    printf("%d\n", c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&n, &a, &b);
     ^