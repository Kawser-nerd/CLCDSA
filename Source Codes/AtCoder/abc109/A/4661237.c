#include<stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%s\n", (a * b) % 2 == 1 ? "Yes":"No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a, &b);
     ^