#include <stdio.h>
int main()
{   int h1,w1,h2,w2;
    scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
    if(h1==h2||h1==w2||w1==h2||w1==w2)
    printf("YES");
    else printf("NO");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
     ^