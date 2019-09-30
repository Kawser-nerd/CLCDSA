#include<stdio.h>

int main(void){
  long int n,t,i,ans;
  scanf("%ld %ld",&n,&t);
  long int a[n+1];
  for(i=0;i<n;i++){
    scanf("%ld",&a[i]);
  }
  ans=t;
  for(i=0;i+1<n;i++){
    if(((a[i]+t)<a[i+1])){
      ans+=t;
    }else{
      ans+=a[i+1]-a[i];
    }
  }
  printf("%ld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld",&n,&t);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a[i]);
     ^