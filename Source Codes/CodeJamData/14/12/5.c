#include <stdio.h>

int vet[1005][1005];

int rec(int index, int pai) {
    int b = 1;
    int i, j, k, t;
    if (vet[index][0] >= 3) {
        j = 0;
        k = 0;
        for (i = 1; i <= vet[index][0]; i++) {
            if (vet[index][i] != pai) {
                t = rec(vet[index][i], index);
                if (t > j) {
                    k = j;
                    j = t;
                } else if (t > k) {
                    k = t;
                }
            }
        }
        return 1 + k + j;
    }
    return 1;
}

int main() {
    int i, j, k, l, m, n, o, p, q, r, s, t, aux1, aux2, aux3;
    
    
    scanf("%d", &t);
    for (o = 1; o <= t; o++) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            vet[i][0] = 0;
        }
        for (i = 0; i < n-1; i++) {
            scanf("%d %d", &k, &l);
            vet[k][0]++;
            vet[l][0]++;
            vet[k][vet[k][0]] = l;
            vet[l][vet[l][0]] = k;
        }
        /*for (i = 1; i <= n; i++) {
            printf("%d ", vet[i][0]);
            for (j = 1; j <= vet[i][0]; j++) {
                printf("%d ", vet[i][j]);
            }
            printf("\n");
        }*/
        s = 0;
        for (i = 1; i <= n;i++) {
            if(vet[i][0] >= 2) {
                aux1 = 0;
                aux2 = 0;
                for (j = 1; j <= vet[i][0]; j++) {
                    aux3 = rec(vet[i][j], i);
                    if(aux3 > aux1) {
                        aux2 = aux1;
                        aux1 = aux3;
                    } else if (aux3 > aux2) {
                        aux2 = aux3;
                    }
                }
                if ((1+aux2+aux1) > s) {
                    s = 1+aux2+aux1;
                }
            } else {
                if(1 > s) {
                    s = 1;
                }
            }
        }
        printf("Case #%d: %d\n", o, n-s);
    }
    
    
    return 0;
}