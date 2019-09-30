#include <stdio.h>

typedef long long LL; 

int main(){
    int T, t;
    int K,C,S;
    LL r,bs;
    int i,j,k,g;
    scanf("%d", &T);
    for (t=1;t<=T;t++){
        scanf("%d%d%d", &K, &C, &S);
        printf("Case #%d:", t);
        if (C*S<K) printf(" IMPOSSIBLE\n");
        else{
            g = (K-1)/C + 1;
            j = 0;
            for (i=0;i<g;i++){
                r = 0;
                for (k=0;k<C&&j<K;k++,j++){
                    r=r*K+j;
                }
                printf(" %lld", r+1);
            }
            printf("\n");
        }
    }
    return 0;
}

