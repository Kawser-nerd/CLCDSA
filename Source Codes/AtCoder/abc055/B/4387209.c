#include<stdio.h>
#include<math.h>

int main(void)
{
    long int a = 1000000007, ans=1;
    int n, i;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
      ans = (ans * i) % a;
    }
    printf("%lld", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:12: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘long int’ [-Wformat=]
     printf("%lld", ans);
            ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^