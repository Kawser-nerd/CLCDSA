#include <stdio.h>

void solve(int cas){
    int low,sum,xor,N,c;
    low = 1<<30;
    sum = 0;
    xor = 0;
    scanf("%d",&N);
    while (N--){
        scanf("%d",&c);
        if (low>c) low = c;
        sum +=c;
        xor ^=c;
    }
    if (xor) printf("Case #%d: NO\n",cas);
    else printf("Case #%d: %d\n", cas, sum-low);
}

int main(){
    int t,cas;
    scanf("%d",&t);
    for (cas=1;cas<=t;cas++)
        solve(cas);
    return 0;
}

