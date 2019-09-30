#include <stdio.h>
#include <string.h>

int main(){
    int cas, T;
    int i,N,h;
    char c[2600];
    scanf("%d", &T);
    for (cas=1;cas<=T;cas++){
        scanf("%d", &N);
        memset(c,0,sizeof(c));
        for (i=N*(2*N-1);i>0;i--){
            scanf("%d", &h);
            c[h] ^= 1;
        }
        printf("Case #%d:", cas);
        for (i=1;i<=2500;i++)
            if (c[i]) printf(" %d", i);
        printf("\n");
    }
    return 0;
}
