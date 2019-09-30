#include<stdio.h>
#include<math.h>

int main(){
  int n,i;
  long long int a,sum[200000]={},min=200000000000000;
  scanf("%d",&n);
  scanf("%lld",&a);
  sum[0]=a;
  for(i=1;i<n;i++){
    scanf("%lld",&a);
    sum[i]=sum[i-1]+a;
  }
  for(i=0;i<n-1;i++){
    if(min>llabs(sum[n-1]-2*sum[i]))
      min=llabs(sum[n-1]-2*sum[i]);
  }
  printf("%lld\n",min);
} ./Main.c: In function ‘main’:
./Main.c:15:12: warning: implicit declaration of function ‘llabs’ [-Wimplicit-function-declaration]
     if(min>llabs(sum[n-1]-2*sum[i]))
            ^
./Main.c:15:12: warning: incompatible implicit declaration of built-in function ‘llabs’
./Main.c:15:12: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&a);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a);
     ^