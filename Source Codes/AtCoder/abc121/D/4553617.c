#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define VEC(kata, num) (kata*)malloc(num * sizeof(kata))
#define DB puts("ok")
#define SENTINEL 1000000007
typedef long long lli;

lli f(lli a, lli b) {
    if(a==0) {
        if(b%2==0) {
            if(((b+1)/2)%2==0) {
                return b ^ 0;
            } else {
                return b ^ 1;
            }
        } else {
            if(((b+1)/2)%2==0) {
                return 0;
            } else {
                return 1;
            }
        }
    } else {
        return f(0, a-1) ^ f(0, b);
    }
}

int main()
{
    lli a, b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",f(a,b));

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&a,&b);
     ^