#include <stdio.h>

typedef long long LL;

LL mypow(int a, int n){
    LL r,base;
    r = 1, base=a;
    while (n>0){
        if (n&1) r *= base;
        n >>= 1;
        base = base*base;
    }
    return r+1;
}

int main(){
    int c, v, t,T, N, J, L,i;
    char s[200];
    LL out[11];
    scanf("%d", &T);
    for (c=1; c<=T;c++){
        scanf("%d%d", &N, &J);
        L = N/2-2;
        printf("Case #%d:\n", c);
        for (i=2;i<=10;i++)
            out[i]=mypow(i, L+2);
        for (v=0;v<J;v++){
            t = v;
            s[L+2]='\0';
            s[L+1]=s[0]='1';
            for (i=1;i<=L;i++){
                s[i]='0'+(t&1);
                t/=2;
            }
        printf("%s%s",s,s);
        for (i=2;i<=10;i++) printf(" %lld", out[i]);
        printf("\n");
        }
    }
}

