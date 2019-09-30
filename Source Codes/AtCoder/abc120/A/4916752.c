#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MOD 1000000007
#define MAX(a,b) (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b) (a<b?a:b)
#define MIN3(a,b,c) MIN(a, MIN(b,c))
typedef long long lli;
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main()
{
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",MIN(b/a ,c));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^