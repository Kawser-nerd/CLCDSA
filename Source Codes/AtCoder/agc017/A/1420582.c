#include <stdio.h>
#define MAX 100
int main(){
  int i,n,p,a[MAX],mod,frag=0;
  long long int sum=1;
  scanf("%d %d",&n ,&p);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
    for(i=0;i<n;i++){
      mod=a[i]%2;
      //printf("%d",mod);
      sum*=2;
    if(mod!=0){
      frag=1;
    }
  }
  //printf("%d\n",frag);
  if(frag==0 & p==1){
    printf("0\n");
  }
  if(frag==0 & p==0){
    printf("%lld\n",sum);
  }
  if(frag==1){
    //printf("%ld\n",sum);
    printf("%lld\n",sum/2);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n ,&p);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^