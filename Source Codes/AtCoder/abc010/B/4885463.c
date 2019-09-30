#include <stdio.h>
#define max_len 15
void initArray(int a[], int len);
int main(void)
{
    int n;
    scanf("%d", &n);
    int flowers[max_len];
    initArray(flowers, max_len);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &flowers[i]);
    }
    int remove_potals[10] = {0,1,0,1,2,3,0,1,0,1};
    int remove_sum = 0;
    for(int i = 0; i < n; i++)
    {
        remove_sum += remove_potals[flowers[i] - 1];
    }
    printf("%d\n",remove_sum);
    return 0;
}

void initArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &flowers[i]);
         ^