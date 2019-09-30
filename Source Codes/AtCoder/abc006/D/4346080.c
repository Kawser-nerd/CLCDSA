#include <stdio.h>
#include <string.h>
#define N_max 30002
#define Infinity 100000
long C[N_max];
long DP[N_max];
// ????????????
int calc_LIS (int N, long C[]) {
    DP[0] = -Infinity;
    // ??????
    for (size_t i = 1; i <= N; i++) {DP[i] = Infinity;}

    int length = 0; // ?????
    int left, right, mid;
    // ??????
    for (int i = 1; i <= N; i++) {
        if (C[i] > DP[length]) {
            DP[length+1] = C[i];
            length ++;  // ????????
        } else {    // ????
            left = 0; right = length; mid = (left+right)/2;
            while (left < right-1) {
                if (C[i] < DP[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
                mid = (left+right)/2;
            }
            DP[right] = C[i];
        }
    }

    return length;
}

int main(int argc, char const *argv[]) {
    // ??
    int N;  // ??????
    scanf("%d", &N );
    // ??
    for (size_t i = 1; i <= N; i++) {
        scanf("%ld", &C[i] );
    }
    // ????????????
    calc_LIS(N, C);
    int ans;
    ans = N-calc_LIS(N, C);
    // ??
    printf("%d\n", ans );
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N );
     ^
./Main.c:43:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", &C[i] );
         ^