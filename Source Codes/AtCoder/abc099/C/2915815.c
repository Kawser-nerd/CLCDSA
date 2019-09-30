#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    int N;
    //??
    scanf("%d", &N );
    //??
    int ans = N;
    for (size_t i = 0; i <= N; i++) {
        int count = 0;
        int t = i;
        while ( t > 0) {
            count += t %6;
            t = t/6;
        }
        t = N-i;
        while ( t > 0) {
            count += t%9;
            t = t/9;
        }
        if ( ans > count) {
            ans = count;
        }
    }
    //??
    printf("%d\n", ans );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N );
     ^