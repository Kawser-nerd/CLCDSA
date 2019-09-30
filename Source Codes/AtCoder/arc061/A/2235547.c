#include <stdio.h>
#include <string.h>
#include <math.h>

long calc(char *exp) {
    long tmp=0, ret=0;
    for (int i=0; i<strlen(exp); i++) {
        if (exp[i] != '+')
            tmp *= 10, tmp += exp[i]-'0';
        else 
            ret += tmp, tmp=0;
    }
    return ret+tmp;
}

int main() {
    char s[11] = {};
    scanf("%s", s);
    int len = strlen(s);
    long ans = 0;
    for (int i=0; i<powl(2, len-1); i++) {
        char dst[24]={};
        int k=0;
        for (int t=0 ; t<len; t++, k++) {
            if (i & (1 << (t-1)))
                dst[k++] = '+';
            dst[k] = s[t];
        }
        dst[k] = '\0';
        ans += calc(dst);
    }
    printf("%ld\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^