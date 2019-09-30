#include <stdio.h>
#include <string.h>

typedef long long lli;

#define CHARMAX 256
char a[200001];
int freq[CHARMAX];

int main() {
    int i, n = 0;
    for(i=0; i<CHARMAX; ++i) {
        freq[i] = 0;
    }
    scanf("%s", a);
    for(n=0; a[n] != '\0'; ++n) {
        freq[(int)(a[n])]++;
    }
    lli res = (lli)(n-1) * n / 2ll + 1;
    for(i=0; i<CHARMAX; ++i) {
        int f = freq[i];
        if(f > 0) {
            res -= (lli)(f-1) * f / 2ll;
        }
    }
    printf("%lld\n", res);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", a);
     ^