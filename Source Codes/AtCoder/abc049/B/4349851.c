#include <stdio.h>
int main(void)
{
    int h, w, i, j;
    char a[101][101];

    scanf("%d %d", &h, &w);
    
    for(i=0;i<h;i++){
        scanf("%s", a[i]);
    }

    for(i=0;i<h;i++){
        printf("%s", a[i]);
        printf("\n");
        printf("%s", a[i]);
        printf("\n");
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h, &w);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", a[i]);
         ^