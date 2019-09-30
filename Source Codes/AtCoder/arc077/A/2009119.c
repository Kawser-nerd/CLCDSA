#include<stdio.h>
int a[200000];
int main(void)
{
    int i, n, l, r, x = 1, f = 0;
    l = r = 100000;
    scanf("%d",&n);
    if(n%2==0)f=1;
    scanf("%d",&a[100000]);
    while(x<n)
    {
        if(f){scanf("%d",&a[--l]);x++;}
        if(x>=n)break;
        scanf("%d",&a[++r]);x++;
        f = 1;
    }
    for (i=l; i<=r; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[100000]);
     ^
./Main.c:12:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         if(f){scanf("%d",&a[--l]);x++;}
               ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[++r]);x++;
         ^