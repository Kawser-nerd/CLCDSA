#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int i;
    scanf("%d %d",&n,&m);
    int nn;
    for(nn=m/n; m%nn!=0; nn--);
    printf("%d",nn);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&m);
     ^