#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 1000000007
int factor(int n,int i){
    int ans=0,temp=i;
    //printf("i=%d",i);
    while(n/i!=0){
        //printf(" n/i=%d",n/i);
        ans+=n/i;
        i*=temp;
    }
    //printf(" ans=%d\n",ans);
    return ans;
}
int main(void){
    int n;
    scanf("%d",&n);
    int i,j,flag;
    long long int ans=1;
    for(i=2;i<=n;i++){
        flag=1;
        for(j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=0;
                break;}
            }
            //??????
            if(flag==1){
                ans=(ans*(factor(n,i)+1))%M;
            }
        }
    printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^