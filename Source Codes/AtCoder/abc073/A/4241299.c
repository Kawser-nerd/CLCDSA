#include <stdio.h>

int main(void)
{
        char n[2];
        scanf("%s",n);
        int i=0,x=0;
        for(i;i <= 1;i++)
                {
                if(n[i] == '9')
                {x=1;}
                }
        if(x == 1)
                {printf("Yes\n");}
        else
                {printf("No\n");}
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",n);
         ^