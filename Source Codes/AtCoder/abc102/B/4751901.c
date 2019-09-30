#include <stdio.h>

int main(void){
    int n, tmp;
    int max = 1;
    int min = 1e9;
    scanf("%d", &n);
    for (int i= 0; i < n; i++){
        scanf("%d", &tmp);
        max = (max < tmp) ? tmp : max;
        min = (min > tmp) ? tmp : min;
    }
    printf("%d\n", max - min);
    return 0; 
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &tmp);
         ^