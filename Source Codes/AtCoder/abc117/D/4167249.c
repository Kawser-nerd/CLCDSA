#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    long long K;
    long long A[100000];
    long long i;
    long long j;
    long long sum;
    long long a_sum;
    long long ans;
    long long max;
    long long bin[64];
    int index;

    scanf("%d %lld", &N, &K);
    a_sum = 0;
    for(i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        a_sum += A[i];
    }

    ans = 0;
    index = 0;
    for(i = 1; i <= K; i*=2) {
        sum = 0;
        for(j = 0; j < N; j++) {
            sum += (A[j] ^ i) - A[j];
        }
        bin[index] = sum;
        index += 1;
    }

    ans = 0;
    max = 0;
    for(i = index-1; i >= 0; i--) {
        if(bin[i] > 0 && (max+pow(2,i)) <= K) {
            ans += bin[i];
            max += pow(2, i);
        }
    }

    printf("%lld\n", ans + a_sum);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %lld", &N, &K);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &A[i]);
         ^