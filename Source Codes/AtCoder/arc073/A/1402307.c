#include<stdio.h>

int main(void) {
    int n,t;
    scanf("%d%d",&n,&t);
    int i;
    int x[n];
    int time = 0;
    for (i=0; i<n; i++) {
        scanf("%d",&x[i]);
    }
    for (i=0; i<n-1; i++) {
        if (x[i+1] - x[i] < t) {
            time += x[i+1] - x[i];
        } else {
            time += t;
        }
    }
    time += t;
    printf("%d\n", time);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&t);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&x[i]);
         ^