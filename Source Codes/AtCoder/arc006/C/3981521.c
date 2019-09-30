#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

int main()
{
    int a[50],b[50];
    int n,low;
    int num = 1;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    b[0] = a[0];
    for(int i = 1;i < n;i++)
        {
            low = -1;
            for(int j = 0;j < num;j++)
                if(a[i] <= b[j])
            {
                if(low == -1)
                    low = j;
                else if(b[j] < b[low])
                    low = j;
            }
            if(low == -1)
                b[num++] = a[i];
            else
                b[low] = a[i];
        }
        printf("%d\n",num);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^