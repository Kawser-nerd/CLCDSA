#include <stdio.h>

int main(){
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=105,c=0;i<=n;i+=2,c=0){
        for(int k=1;k<=i;k+=2){
            if(i%k==0)c++;
        }   
        if(c==8) ++ans;
    }   
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     int n;scanf("%d",&n);
           ^