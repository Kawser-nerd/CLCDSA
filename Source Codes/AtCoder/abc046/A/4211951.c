#include <stdio.h>

int main(void)
{
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == b || b == c || c == a)
                {
                        if(a == b && b == c){printf("%d",1);}
                        else{printf("%d",2);}
                }
        else{printf("%d",3);}
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&a,&b,&c);
         ^