#include<stdio.h>

int main(){

    int n,k,x,y;
    scanf("%d\n%d\n%d\n%d",&n, &k, &x, &y);

    int i,ans=0;
    for(i=0;i<n;i++){
        if(i<k)ans = ans + x;
        else ans = ans + y;
    }
    printf("%d\n",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n%d\n%d\n%d",&n, &k, &x, &y);
     ^