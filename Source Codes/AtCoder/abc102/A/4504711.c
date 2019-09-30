#include <stdio.h>

int main(){
    int n,ans;
    scanf("%d",&n);
    if(n%2==0){
        ans=n;
    }else{
        ans=2*n;
    }   
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^