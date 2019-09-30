#include <stdio.h>
int main(void){
    int n,m,l,r,s,ans=0;
    scanf("%d%d",&n,&m);
    int tmp[m+1];
    for (int i=0; i<=m; i++){
        tmp[i]=0;
    }
    for (int i=0; i<n; i++){
        scanf("%d%d%d",&l,&r,&s);
        for (int i=1; i<l; i++){
            tmp[i]+=s;
        }
        for (int i=r+1; i<=m; i++){
            tmp[i]+=s;
        }
    }
    for (int i=1; i<=m; i++){
        if (ans<tmp[i]){
            ans=tmp[i];
        }
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&l,&r,&s);
         ^