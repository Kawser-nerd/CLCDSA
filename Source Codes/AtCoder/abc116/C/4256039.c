#include <stdio.h>
int getnotzero(int a[], int length);
int getzero(int a[], int start);
int main(void)
{
    int n;
    scanf("%d",&n);
    int garden[n+1];
    for(int i = 0; i < n + 1; i++)
    {
        garden[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&garden[i]);
    }

    int count = 0;
    int start = getnotzero(garden, n);
    int end = getzero(garden, start);
    while(start != n)
    {
        while(start < end)
        {
            garden[start]--;
            start++;
        }
        count++;
        start = getnotzero(garden, n);
        end = getzero(garden, start);
    }

    printf("%d\n",count);
    return 0;
}

int getnotzero(int a[], int length)
{
    int i = 0;
    while(i <= length)
    {
        if(a[i] != 0)
        {
            return i;
        }
        i++;
    }
    return length;
}
int getzero(int a[], int start)
{
    int i = start;
    while(1)
    {
        if(a[i] == 0)
        {
            return i;
        }
        i++;
    }
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&garden[i]);
         ^