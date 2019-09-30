#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n<=59)printf("Bad\n");
    else if(60<=n && n<=89)printf("Good\n");
    else if(90<=n&&n<=99)printf("Great\n");
    else printf("Perfect\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^