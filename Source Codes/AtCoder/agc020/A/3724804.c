#include <stdio.h>
int main()
{   int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if((a-b-1)%2==0){
    printf("Borys");
    return 0;}
    printf("Alice");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^