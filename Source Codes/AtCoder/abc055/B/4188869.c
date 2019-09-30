#include <stdio.h>
int main(void){
    long int n,i,ans=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        ans*=i;
        if(1000000007<=ans) ans=ans%1000000007;
    }
    printf("%ld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long int *’ [-Wformat=]
     scanf("%d",&n);
           ^
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^