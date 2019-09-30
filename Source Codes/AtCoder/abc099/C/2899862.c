#include<stdio.h>

dp[200000];

int main()
{
    int a[12]={1,6,9,36,81,216,729,1296,6561,7776,46656,59049},n,x,y;

    scanf("%d",&n);

    for(y=0;y<12;y++){
        for(x=0;x+a[y]<=100000;x++){
            if(dp[x+a[y]]==0||dp[x+a[y]]>dp[x]+1){
                dp[x+a[y]]=dp[x]+1;
            }
        }
    }

    printf("%d\n",dp[n]);




    return 0;
} ./Main.c:3:1: warning: data definition has no type or storage class
 dp[200000];
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘dp’ [-Wimplicit-int]
./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^