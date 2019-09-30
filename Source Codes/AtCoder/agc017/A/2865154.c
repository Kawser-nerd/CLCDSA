#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    int n,p,even=0,odd=0;
    long long ans=1,tmp1=1,tmp2=0;
    scanf("%d%d",&n,&p);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(a[i]%2==0){
            even++;
        } else {
            odd++;
        }
    }
    if (p==0){
        for (int i=0; i<even; i++){
            ans*=2;
        }
        for (int i=0; i<=odd/2; i++){
            for (int j=0; j<i*2; j++){
                tmp1=tmp1*(odd-j)/(j+1);
            }
            tmp2+=tmp1;
            tmp1=1;
        }
        ans=ans*tmp2;
    } else {
        for (int i=0; i<even; i++){
            ans*=2;
        }
        for (int i=0; i<odd/2; i++){
            for(int j=0; j<i*2+1; j++){
                tmp1=tmp1*(odd-j)/(j+1);
            }
            tmp2+=tmp1;
            tmp1=1;
        }
        ans=ans*tmp2;
    }
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&p);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^