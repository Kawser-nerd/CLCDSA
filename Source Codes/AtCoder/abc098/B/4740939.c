#include <stdio.h>
void initArray(int a[], int len);
int main(void)
{
    int n;
    scanf("%d\n", &n);
    char s[n];
    int alf[26];
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &s[i]);
    }

    int mid = 1, max = 0;
    while (mid < n)
    {
        initArray(alf, 26);
        int num = 0;
        for (int i = 0; i < mid; i++)
        {
            int tmp = s[i] - 'a';
            alf[tmp] = 1;
        }
        for (int j = mid; j < n; j++)
        {
            int tmp = s[j] - 'a';
            if (alf[tmp] == 1)
            {
                alf[tmp]++;
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (alf[k] == 2)
            {
                num++;
            }
        }
        if (num > max)
        {
            max = num;
        }
        mid++;
        // for(int i = 0; i< 26;i++)
        // {
        //     printf("%d ",alf[i]);
        // }
        // puts("");
    }

    printf("%d\n", max);
    return 0;
}

void initArray(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] = 0;
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%c", &s[i]);
         ^