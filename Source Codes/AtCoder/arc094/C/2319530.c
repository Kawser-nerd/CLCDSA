#include <stdio.h>


int main(void){
    int N;
    scanf("%d",&N);
    long long int a[N],b[N];
    long long int ans=0;
    long long int min=1000000007;
    int zero=1;
    for(int i=0;i<N;i++){scanf("%lld %lld",&a[i],&b[i]);if(a[i]!=b[i])zero=0;ans+=b[i];if(a[i]>b[i]&&b[i]<min)min=b[i];}
    if(zero==1)printf("0");
    else printf("%lld",ans-min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:11:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(int i=0;i<N;i++){scanf("%lld %lld",&a[i],&b[i]);if(a[i]!=b[i])zero=0;ans+=b[i];if(a[i]>b[i]&&b[i]<min)min=b[i];}
                          ^