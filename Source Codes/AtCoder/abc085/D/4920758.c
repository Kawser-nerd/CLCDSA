#include <stdio.h>
#include <stdlib.h>
int fw(const void *a, const void *b)
{
    return *(long int *)a - *(long int *)b;
}
int bw(const void *a, const void *b)
{
    return *(long int *)b - *(long int *)a;
}
int main()
{
    int n, a[100010] = {}, b[100010] = {};
    int h;
    int hit = 0, count = 0;
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }
    qsort(a, n, sizeof(int), bw);
    qsort(b, n, sizeof(int), bw);
    for (int i = 0; b[i] > a[0] && hit < h; i++)
    {
        hit += b[i];
        count++;
    }
    while (hit < h)
    {
        hit += a[0];
        count++;
    }
    printf("%d", count);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &h);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a[i], &b[i]);
         ^