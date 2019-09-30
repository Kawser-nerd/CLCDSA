#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int t,i,j;
    char n[100], d[256];
    scanf("%d", &t);
    for(i = 1; i <= t; i++) {
        scanf("%s", n);
        int len = strlen(n);
        for(j = 0; j<256;j++) {
            d[j] = -1;
        }
        d[n[0]] = 1;
        j=1;
        int tt = 2;
        while(n[j++]==n[0])
            NULL;
        d[n[j-1]] = 0;
        for(; j < len; j++) {
            if(d[n[j]] == -1) {
                d[n[j]] = tt++;
            }
        }
        long long int res = 0, base = 1;
        for(j = len-1; j >= 0; j--) {
            res+=d[n[j]]*base;
            base*=tt;
        }
        printf("Case #%d: %I64d\n", i,res);
    }
    return 0;
}
