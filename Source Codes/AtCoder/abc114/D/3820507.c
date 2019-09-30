#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX (a>b?a:b)

long long int fact(int n)
{
    if(n==1)
        return 1;
    else
        return n * fact(n-1);
}

long long int combination(int n, int r)
{
    if(n>r)
        return fact(n) / (fact(r)*fact(n-r));
    else if(n==r)
        return 1;
    else
        return 0;
}

int main()
{
    int i, j, n, count[101]={0};
    int yakusu2=0, yakusu4=0, yakusu14=0, yakusu24=0, yakusu74=0;

    scanf("%d",&n);
    for(i=2; i<=n; i++) {
        int temp = i;
        for(j=2; j<=i; j++) {
            while(temp%j==0) {
                temp /= j;
                count[j]++;
            }
        }
    }

    for(i=2; i<=n; i++) {
        if(count[i]>=74)yakusu74++;
        if(count[i]>=24)yakusu24++;
        if(count[i]>=14)yakusu14++;
        if(count[i]>= 4)yakusu4++;
        if(count[i]>= 2)yakusu2++;
        //if(count[i]>0)printf("count[%d] = %d\n",i,count[i]);
    }  

    long long int ans=0;

    ans += yakusu74;
    ans += (yakusu2-1)*(yakusu24);
    ans += (yakusu4-1)*(yakusu14);
    ans += (yakusu2-2)*combination(yakusu4, 2);

    //printf("nCr = %lld\n",(yakusu2-2)*combination(yakusu4, 2));

    printf("%lld",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^