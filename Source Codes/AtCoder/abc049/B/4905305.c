#include <stdio.h>
#include <string.h>
int main(void)
{
    int h,w;
    scanf("%d%d", &h,&w);
    for(int i=0; i<h; i++)
    {
        char c[w+1];
        scanf("%s", c);
        for(int j=0; j<w; j++) printf("%c", c[j]);
        printf("\n");
        for(int j=0; j<w; j++) printf("%c", c[j]);
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &h,&w);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", c);
         ^