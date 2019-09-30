#include <stdio.h>
int main(){
  long long int n;
  scanf("%lld",&n);
  int a[200],i;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int count=0;
  while(1){
    for(i=0;i<n;i++){
      if(a[i]%2==0) a[i]/=2;
      else {printf("%d",count);return 0;}
    }
    count++;
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^