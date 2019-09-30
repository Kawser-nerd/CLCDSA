#include <stdio.h>

int main(){
    int D, cnt;
    scanf("%d", &D);
    cnt = 25 - D;
    printf("Christmas");
    for(int i = 0; i < cnt; i++) printf(" Eve");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &D);
     ^