#include <stdio.h>
#define max_len 100010
void initArray(int a[], int len);
long partial_Sum(int a[], int first, int last);
int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    int nums[max_len];
    initArray(nums, max_len);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    int begin = 0, end = n - k + 1;
    long sum = 0;
    while (begin < end)
    {
        sum += partial_Sum(nums, begin, begin + k);
        begin++;
    }
    printf("%ld\n", sum);
    return 0;
}

void initArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
}

long partial_Sum(int a[], int begin, int end)
{
    long p_sum = 0;
    int iter = begin;
    while (iter < end)
    {
        p_sum += a[iter];
        iter++;
    }
    return p_sum;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &k);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &nums[i]);
         ^