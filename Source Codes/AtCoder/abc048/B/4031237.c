#include <stdio.h>
int main(void){
    long a,b,x;
    scanf("%ld%ld%ld",&a,&b,&x);
    
    long c = a/x, d = b/x;
    long ans = d-c;
    
    if(!(a%x))
    {
        ans++;
    }
    
    printf("%ld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld%ld",&a,&b,&x);
     ^