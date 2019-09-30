#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
        int N;
        int x;
        int y;
        int ans = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                scanf("%d %d", &x,&y);
                ans += y - x + 1 ;
        }
        printf("%d\n", ans);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &N);
         ^
./Main.c:12:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d %d", &x,&y);
                 ^