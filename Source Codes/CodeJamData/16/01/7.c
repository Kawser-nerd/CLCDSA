#include <stdio.h>
#include<string.h>

int solve(int x){
    char mask[10];
    int mask_cnt, n;
    memset(mask,0,sizeof(mask));
    mask_cnt = 0;
    for (n=1;n<10000000;n++){
        int t, c;
        c = n * x;
        while (c>0){
            t = c % 10;
            if (mask[t]==0){
                mask[t]=1;
                mask_cnt++;
            }
            c/=10;
        }
        if (mask_cnt==10) break;
    }
    return n*x;
}

int main(){
    int N, x, cas;
    scanf("%d", &N);
    for (cas=1; cas<=N;cas++){
        scanf("%d", &x);
        printf("Case #%d: ", cas);
        if (x==0) printf("INSOMNIA\n");
        else printf("%d\n", solve(x));
    }
    return 0;
}
