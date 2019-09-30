#include <stdio.h>

int main(int argc, char const *argv[]) {
    // ??
    long long N;
    // ??
    scanf("%lld", &N);
    // ???????
    int depth = 0;
    for ( ; ; depth++) {
      if ( (1LL<<depth) <= N+1 && 2*(1LL<<depth)-1 >= N+1 ) {
         break;
      }
   }
    // ??????
    long long x = 1;
    int cnt = 0;
    while (1) {
        if (depth%2) {
            x = x*2; cnt ++;
            if (x >= N+1) { break; }
            x = x*2+1; cnt ++;
            if (x >= N+1) { break; }
        } else {
            x = x*2+1; cnt ++;
            if (x >= N+1) { break; }
            x = x*2; cnt ++;
            if (x >= N+1) { break; }
        }
    }
    // ??
    // printf("cnt %d\n", cnt);
    if (cnt&1) {
        printf("Aoki\n");
    } else {
        printf("Takahashi\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &N);
     ^