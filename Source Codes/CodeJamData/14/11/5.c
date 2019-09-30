#include <stdio.h>
#include <string.h>

int main() {
    long long int i, j, k, l, m, n, o, p, q, r, s, t;
    
    long long int vet[160], vet2[160];
    char str[45];
    
    
    scanf("%lld", &t);
    for (r =1 ; r<=t;r++) {
        scanf(" %lld %lld ", &n, &s);
        for(i = 0; i < n; i++) {
            scanf(" %s ", str);
            vet[i] = 0;
            for (j = 0; j < s; j++) {
                if (str[j] == '1') {
                    vet[i]++;
                }
                vet[i] = vet[i] * 2;
            }
        }
        for(i = 0; i < n; i++) {
            scanf(" %s ", str);
            vet2[i] = 0;
            for (j = 0; j < s; j++) {
                if (str[j] == '1') {
                    vet2[i]++;
                }
                vet2[i] = vet2[i] * 2;
            }
        }
        
        m = 45;
        for (i = 0; i < n; i++) {
            l = vet[0]^vet2[i];
            for (j = 1; j<n;j++) {
                o = 0;
                for (k = 0; k <n;k++) {
                    if((vet[j]^vet2[k]) == l) {
                        o = 1;
                        break;
                    }
                }
                if (!o) {
                    break;
                }
            }
            if (j == n) {
                p = 0;
                while(l >0) {
                    p = p + (l%2);
                    l = l/2;
                }
                if (p < m) {
                    m = p;
                }
            }
        }
        if (m == 45) {
            printf("Case #%lld: NOT POSSIBLE\n", r);
        } else {
            printf("Case #%lld: %lld\n", r, m);
        }
        
    }
    return 0;
}
