#include <stdio.h>
int main(void)
{
    int k;
    scanf("%d",&k);
    long int a[100002]={};
    for(int p=0;p<k;p++)scanf("%ld ",&a[p]);
    
    long long int min=2;
    long long int max=2+a[k-1]-1;
    if(a[k-1]!=2)
    {
        printf("-1");
        return 0;
    }
    for(int q=k-2;q>=0;q--)
    {
        long int b=min/a[q];
        long int c=max/a[q];
        if(b==c && min%a[q]!=0)
        {
            printf("-1");
            return 0;
        }
        else if(b!=c)
        {
            if(min%a[q]==0)min=b;
            else min=b+1;
            max=c;
        }
        else
        {
            min=b;
            max=c;
        }
        min=min*a[q];
        max=(max+1)*a[q]-1;
    }
    printf("%lld %lld",min,max);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&k);
     ^
./Main.c:7:25: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int p=0;p<k;p++)scanf("%ld ",&a[p]);
                         ^