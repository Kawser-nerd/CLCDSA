/* AtCoder Grand Contest 018. Task , by Abreto<m@abreto.net>. */
#include <stdio.h>

int gcd(int a, int b)
{
    return (0==b)?a:gcd(b,a%b);
}

int main(void)
{
    int N = 0, K = 0;
    int maxA = 0, Ai = 0;
    int gcdA = 0;
    scanf("%d %d", &N, &K);
    scanf("%d", &Ai);
    maxA = Ai; gcdA = Ai;
    while(--N)
    {
        scanf("%d", &Ai);
        if(Ai > maxA) maxA = Ai;
        gcdA = gcd(gcdA, Ai);
    }
    if(K > maxA || K % gcdA)
        puts("IMPOSSIBLE");
    else
        puts("POSSIBLE");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &K);
     ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &Ai);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &Ai);
         ^