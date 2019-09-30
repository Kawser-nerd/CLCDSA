#include <stdio.h>

long long l[100];

void layer(int n) {
    int i;
    l[0] = 1;
    for (i=1;i<=n;i++) l[i] = l[i-1]*2 + 3;
}

long long burger(int n, long long c) {
    if (n == 0) return 1;
    else {
        if (c == 1) return 0;
        else if (c == l[n]) return 2*burger(n-1,l[n-1])+1;
        else if (c == (l[n]+1)/2) return burger(n-1,l[n-1])+1;
        else if (c < (l[n]+1)/2) return burger(n-1,c-1);
        else return burger(n-1,l[n-1])+1+burger(n-1,c-2-l[n-1]);
    }
}

int main(void) {
    int N;
    long long X;
    scanf("%d%lld", &N, &X);
    
    layer(N);
    printf("%lld\n", burger(N, X));

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%lld", &N, &X);
     ^