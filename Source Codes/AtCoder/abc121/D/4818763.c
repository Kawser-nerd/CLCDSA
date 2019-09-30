#include <stdio.h>

unsigned long long solve(unsigned long long a){
    if(a%2 != 0) { 
        return ((a+1)/2)%2;
    }
    else { return (a+1)^solve(a+1); }
}

int main(void)
{
    unsigned long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", solve(a-1)^solve(b));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld", &a, &b);
     ^