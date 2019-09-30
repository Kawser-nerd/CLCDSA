#include <stdio.h>

int main(void){
    int N;
    int sum = 0;
    scanf("%d", &N);
    int n = N;
    for (int i= 1.0e9; i > 0; i /= 10){
        sum += n / i;
        n = n % i;
    }
    printf("%s\n", (N % sum == 0) ? "Yes" : "No");
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^