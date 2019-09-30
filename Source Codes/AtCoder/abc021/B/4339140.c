#include <stdio.h>
void initArray(int a[], int len);
int check(int a[], int len);
int main(void)
{
    int n;
    scanf("%d", &n);
    int town[n];
    initArray(town, n);
    int a, b;
    scanf("%d%d", &a, &b);
    int k;
    scanf("%d", &k);
    town[a - 1]++;
    town[b - 1]++;
    for (int i = 0; i < k; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        town[tmp - 1]++;
    }
    puts(check(town, n) ? "YES" : "NO");
}

void initArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
}

int check(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (a[i] > 1)
        {
            return 0;
        }
    }
    return 1;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &k);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&tmp);
         ^