#include <stdio.h>

int main(void){
    int x, y;
    scanf("%d %d", &x, &y);
    int f = x + y / 2;
    printf("%d\n", f);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &x, &y);
     ^