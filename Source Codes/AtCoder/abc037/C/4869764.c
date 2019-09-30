#include <stdio.h>
#define max_len 100010
void initArray(long a[], int len);
int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    long numArray[max_len];
    initArray(numArray, max_len);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &numArray[i]);
    }
    long cumulative_sum[max_len];
    initArray(cumulative_sum, max_len);

    int iter = 1;
    while (iter <= n)
    {
        cumulative_sum[iter] = cumulative_sum[iter - 1] + numArray[iter - 1];
        iter++;
    }
    long partial_sum = 0, total_sum = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        partial_sum = cumulative_sum[k + i] - cumulative_sum[i];
        total_sum += partial_sum;
    }
    printf("%ld\n", total_sum);
    return 0;
}

void initArray(long a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &k);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", &numArray[i]);
         ^