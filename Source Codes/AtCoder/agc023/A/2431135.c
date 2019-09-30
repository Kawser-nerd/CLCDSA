#include <stdio.h>
#include <stdlib.h>
long long int int_sort(const void * a, const void * b)
{
    if(*(long long int*)a<*(long long int*)b)
    {
        return -1;
    }
    else if(*(long long int*)a==*(long long int*)b)
    {
        return 0;
    }
    return 1;
}

int main(void)
{
    long int n;
    long long int a[200005]={};
    scanf("%ld",&n);
    for(long int p=0;p<n;p++)scanf("%lld ",&a[p]);
    long int ans=0;
    long long int sum[200005]={};
    if(n==1&&a[0]==0)
    {
        printf("1");
        return 0;
    }
    else if(n==1&&a[0]!=0)
    {
        printf("0");
        return 0;
    }
    sum[0]=a[0];
    for(long int q=0;q<n-1;q++)sum[q+1]=sum[q]+a[q+1];
    sum[n]=9999999999;
    qsort(sum,n,sizeof(sum[0]),int_sort);
    long int check=0;
    long int num=1;
    while(check<n)
    {
        while(sum[check]==sum[check+1] && check<n)
        {
            check++;
            num++;
        }
        //printf("%ld %ld##\n",sum[check],num);
        if(sum[check]==0)ans+=num;
        check++;
        ans+=num*(num-1)/2;
        num=1;
    }
    printf("%ld",ans);
} ./Main.c: In function ‘main’:
./Main.c:37:32: warning: passing argument 4 of ‘qsort’ from incompatible pointer type [-Wincompatible-pointer-types]
     qsort(sum,n,sizeof(sum[0]),int_sort);
                                ^
In file included from ./Main.c:2:0:
/usr/include/stdlib.h:765:13: note: expected ‘__compar_fn_t {aka int (*)(const void *, const void *)}’ but argument is of type ‘long long int (*)(const void *, const void *)’
 extern void qsort (void *__base, size_t __nmemb, size_t __size,
             ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&n);
     ^
./Main.c:21:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(long int p=0;p<n;p++)scanf("%lld ",&a[p]);
                              ^