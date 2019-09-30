#include <stdio.h>

int main(){
    int j,T,N,K,p;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    for(j=1;j<=T;j++){
        scanf("%d %d",&N,&K);
        p = 1 << (N);
        printf("Case #%d: ",j);
        if(K%p==p-1)printf("ON\n");
        else printf("OFF\n");
    }
    return 0;
}
