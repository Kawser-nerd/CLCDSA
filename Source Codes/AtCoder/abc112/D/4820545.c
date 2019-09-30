#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=m/n;i>=1;i--)
    {
        if(m%i==0){printf("%d\n",i);break;}
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^