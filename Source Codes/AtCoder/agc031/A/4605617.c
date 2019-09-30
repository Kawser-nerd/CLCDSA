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

int main()
{
    int n, i;
    char s[100000];
    int count[26] = {0};
    scanf("%d",&n);
    scanf("%s",s);
    for(i=0; i<n; i++) {
        char a[] = "a";
        int temp = strncmp(s+i, a, 1);
        count[temp]++;
    }
    lli ans = 1;
    for(i=0; i<26; i++) {
        ans = (lli)ans * (count[i]+1) % MOD;
    }
    ans = (ans==0?MOD-1:ans-1);
    printf("%lld",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^