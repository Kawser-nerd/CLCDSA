#include <stdio.h>

int main()
{   int l,m,n;
    scanf("%d%d%d",&l,&m,&n);
    if(l==m)printf("%d\n",n);
    else if(m==n)printf("%d\n",l);
    else printf("%d\n",m);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l,&m,&n);
     ^