#include <stdio.h>


int main(void){
    int n, i, count;
    count = 0;
    scanf("%d", &n);
    int a[n];
    for(i = 0 ; i < n ; i++){
        scanf("%d", &a[i]);
        while(a[i] % 2 == 0){
            a[i] /= 2;
            count++;
        }
    }
    printf("%d", count);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^