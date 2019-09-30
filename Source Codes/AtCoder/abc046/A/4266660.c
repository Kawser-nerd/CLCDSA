#include <stdio.h>

int main()
{   int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a==b&&b==c){
        printf("1");
    }
    else if(a==b||a==c||b==c){
        printf("2");
    }else printf("3");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^