#include <stdio.h>
#include <stdint.h>

#define MAX_N (100)
#define PI (3.14159265358979)

#define POW1(x) (x)
#define POW2(x) ((x) * (x))
#define POW3(x) ((x) * (x) * (x))

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

double calc(uint32_t N,
            uint32_t X[MAX_N], uint32_t R[MAX_N], uint32_t H[MAX_N],
            uint32_t A, uint32_t B)
{
    double ans = 0.;
    uint32_t n;

    for (n = 0; n < N; n++) {
        double buf1, buf2, buf3;
        int32_t a = (int32_t)A - (int32_t)X[n];
        int32_t b = (int32_t)B - (int32_t)X[n];
        int32_t startX = (uint32_t)MAX(0, a);
        int32_t endX   = (uint32_t)MIN((int32_t)H[n], b);

        if (endX < 0) continue;
        if (startX >= endX) continue;

        // printf("H[n] = %5u\n", H[n]);
        // printf("a = %5d, b = %5d\n", a, b);
        // printf("startX = %5u, endX = %5u\n", startX, endX);

        buf1 = (double)(POW3(endX) - POW3(startX)) / (double)(3 * POW2(H[n]));
        buf2 = (double)(POW2(endX) - POW2(startX)) / (double)H[n];
        buf3 = (double)(POW1(endX) - POW1(startX));
        ans += (double)POW2(R[n]) * (buf1 - buf2 + buf3);
    }

    ans *= PI;

    return ans;
}

int main(void)
{
    uint32_t N, Q;
    uint32_t X[MAX_N], R[MAX_N], H[MAX_N];
    uint32_t n, q;

    /* input ensui param */
    scanf("%u %u", &N, &Q);

    /* input ensui data */
    for (n = 0; n < N; n++) {
        scanf("%u %u %u", &X[n], &R[n], &H[n]);
    }

    /* calc */
    for (q = 0; q < Q; q++) {
        uint32_t A, B;
        double ans; 

        /* input query & calc */
        scanf("%u %u", &A, &B);
        ans = calc(N, X, R, H, A, B);

        /* print answer */
        printf("%lf\n", ans);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:53:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%u %u", &N, &Q);
     ^
./Main.c:57:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%u %u %u", &X[n], &R[n], &H[n]);
         ^
./Main.c:66:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%u %u", &A, &B);
         ^