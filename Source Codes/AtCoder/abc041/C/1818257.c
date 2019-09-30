#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long int a;
    int id;
} Data;

int cmp(const void *p, const void *q)
{
    return ((Data *)q)->a - ((Data *)p)->a;
}

int main(void)
{
    int i, j, n;
    Data hei[100000];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &(hei + i)->a);
        (hei + i)->id = i + 1;
    }

    qsort(hei, n, sizeof(Data), cmp);

    for (size_t i = 0; i < n; i++)
    {
        printf("%d\n", (hei + i)->id);
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &(hei + i)->a);
         ^