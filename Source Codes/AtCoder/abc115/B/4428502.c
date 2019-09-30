#include <stdio.h>
int main(void){
    int N = 0;
    int sum = 0;
    int max = 100;
    int x = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        scanf("%d", &x);
        sum += x;
        if(x > max){
            max = x;
        }
    }
    
    printf("%d", sum - max / 2);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &x);
         ^