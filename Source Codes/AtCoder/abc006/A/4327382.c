#include <stdio.h>
int main(void){
    int N = 0;
    scanf("%d", &N);
    if(N % 3 == 0){
        printf("YES\n");
    }else {
        printf("NO\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^