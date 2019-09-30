#include <stdio.h>

int n,tmp,ans=10000 ;

int main(void){
    
    int i;
    int j;
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        int sum=0;
        j=n-i;
         tmp=i;
        while(tmp){
            sum+=tmp%6;
            tmp/=6;
        }
        tmp=j;
        while(tmp){
            sum+=tmp%9;
            tmp/=9;
        }
        if(ans>sum)
            ans=sum;
            
    }
    printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^