#include <stdlib.h>
#include <stdio.h>

int main()
{   int w,a,b;
    scanf("%d%d%d",&w,&a,&b);
    if(b>a+w){
        printf("%d",b-(a+w));
    }else if(a<=b&&b<=a+w){
        printf("0");
    }else if(a>b+w){
        printf("%d",a-(b+w));
    }else printf("0");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&w,&a,&b);
     ^