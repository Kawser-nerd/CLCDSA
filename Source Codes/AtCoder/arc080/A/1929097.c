#include<stdio.h>
#define MAX1 100000
#define MAX2 1000000000
int main(void)
{
    int n,i,a[MAX1],sum4=0,sum2=0,sum1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]%4==0)
            sum4++;
        else if(a[i]%2==0)
            sum2++;
        else if(a[i]%2)
            sum1++;}
    if(sum2==0&&sum4+1>=sum1)
        printf("Yes");
    else if(sum4>=sum1)
        printf("Yes");
    else printf("No");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^