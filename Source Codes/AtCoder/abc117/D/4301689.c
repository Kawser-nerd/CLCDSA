#include <stdio.h>
int main(void){
    int n,i,j;
    long k,a,ans=0,s,kb[40],c[40]={};
    scanf("%d%ld",&n,&k);
    for(i=0;i<n;i++){
        scanf("%ld",&a);
        for(j=0;j<40;c[j++]+=a%2,a>>=1);
    }
    k++;for(i=0;i<40;kb[i++]=k%2,k>>=1);
    for(i=0;i<40;i++)if(kb[i]){
        s=c[i]<<i;
        for(j=39;j>i;j--)s+=(kb[j]?n-c[j]:c[j])<<j;
        for(j=0;j<i;j++)s+=(c[j]>n/2?c[j]:n-c[j])<<j;
        ans=ans>s?ans:s;
    }
    printf("%ld",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%ld",&n,&k);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&a);
         ^