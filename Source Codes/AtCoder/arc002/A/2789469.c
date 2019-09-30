#include <stdio.h>
int main(void)
{
    int y;

    scanf("%d", &y);

    if(y % 4 == 0){
    if(y % 400 == 0){
        printf("YES\n");
    }else if(y % 100 == 0){
        printf("NO\n");
    }else{
        printf("YES\n");
    }
    }
    else if(y % 400 == 0){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &y);
     ^