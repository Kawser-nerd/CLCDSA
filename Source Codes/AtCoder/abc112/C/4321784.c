#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int i, int j){
        if (i > j){
                return i;
        }else{
                return j;
        }
}
int main(void){
        int N;
        scanf("%d", &N);
        int H;
        int x[N];
        int y[N];
        int h[N];
        int tmp;
        for (int i = 0; i < N; i++) {
                scanf("%d %d %d", &x[i], &y[i], &h[i]);
        }
        for (int i = 0; i < N; i++) {
                if (h[i] != 0) tmp = i;
        }

        for (int i = 0; i < 101; i++) {
                for (int j = 0; j < 101; j++) {
                                H = abs(i - x[tmp]) + abs(j - y[tmp]) + h[tmp];
                        for (int k = 0; k < N; k++) {
                                if (h[k] != max(0,H-abs(i-x[k])-abs(j-y[k]))) break;
                                if (k == N - 1){
                                        printf("%d %d %d\n",i,j,H);
                                }

                        }
                }
        }


} ./Main.c: In function ‘main’:
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &N);
         ^
./Main.c:21:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d %d %d", &x[i], &y[i], &h[i]);
                 ^