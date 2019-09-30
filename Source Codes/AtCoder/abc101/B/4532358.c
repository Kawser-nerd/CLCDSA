#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int s=0;
  int m=n;
  while(m>0){
    s+=m%10;
    m=(m-m%10)/10;
  }
  if(n%s==0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^