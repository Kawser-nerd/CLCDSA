#include <stdio.h>
#include <math.h>

int main(){
  int i,n,p,flag=0;

  scanf("%d %d",&n,&p);
  int a[n];
  for(i=0;i<n;i++){
    scanf(" %d",&a[i]);
    if(a[i]%2!=0&&flag==0){
      flag=1;
    }
  }
  long long x;
  x=(long long)pow(2,n);
  if(flag==0){
    if(p==0){
      printf("%lld",x);
      return 0;
    }else{
      printf("0");
      return 0;
    }
  }else{
    printf("%lld",x/2);
    return 0;
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&p);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf(" %d",&a[i]);
     ^