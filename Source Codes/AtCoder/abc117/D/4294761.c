#include <stdio.h>
int max(int a,int b){return a>b?a:b;}
int main(void){
    int n,i,j,c[40]={},kb[40];
    long k,a,s,ans=0;
    scanf("%d%ld",&n,&k);k++;
    for(i=0;i<n;i++){
        scanf("%ld",&a);
        for(j=0;j<40;j++){
            c[j]+=a%2;a>>=1;
        }
    }
    for(i=0;i<40;i++){
        kb[i]=k%2;k>>=1;
    }
    for(i=0;i<40;i++){
        if(kb[i]){
            s=0;
            for(j=39;j>i;j--)s+=(1l<<j)*(kb[j]?(n-c[j]):c[j]);
            s+=(1l<<i)*c[j];
            for(j=0;j<i;j++)s+=(1l<<j)*max(c[j],n-c[j]);
            ans=ans>s?ans:s;
        }
    }
    printf("%ld",ans);
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%ld",&n,&k);k++;
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld",&a);
         ^