#include <stdio.h>

int main(void)
{
    int N, M, X, Y, a[100000] = {0}, b[100000] = {0}, i, j, count = 0,
        position = 0;

    scanf("%d %d %d %d ", &N, &M, &X, &Y);
    for(i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }
    for(i=0; i<M; i++) {
        scanf("%d", &b[i]);
    }
    int times = a[0];
    i = 0, j = 0; 
    while(1) {
        if(position%2) {
            if(!b[j])  break;
            if(times <= b[j]) {
                times = b[j] + Y ;
                position++;
                count++;
            }
            j++;
        }else {
            if(!a[i])  break;
            if(times <= a[i]) {
                times = a[i] + X;
                position++;
            }
            i++;
        }
    }
    printf("%d\n", count);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d ", &N, &M, &X, &Y);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &b[i]);
         ^