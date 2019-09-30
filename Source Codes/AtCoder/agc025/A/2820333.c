#include <stdio.h>
int calc(int a,int b){
    int sum=0;
    while(a>10){
        sum =sum + a%10;
        a = a/10;
    }
    sum = sum + a;
    while(b>10){
        sum = sum + b%10;
        b = b/10;
    }
    sum = sum +b;
    return sum;
}
int main()
{
    int ans=1000000,N,sum[100000],i,a[100000],b[100000];
    scanf("%d",&N);
    if(N%2==0){
        for(i=0;i<N/2;i++){
         a[i]=N-i;
         b[i]=i;
         sum[i]=calc(a[i],b[i]);
         if(ans>sum[i]){
             ans=sum[i];
         }}
        }else{
            for(i=0;i<(N+1)/2;i++){
         a[i]=N-i;
         b[i]=i;
         sum[i]=calc(a[i],b[i]);
         if(ans>sum[i]){
             ans=sum[i];
        }}}
        printf("%d",ans);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^