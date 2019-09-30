#include <stdio.h>

int digit_sum(int x){
  int s=0;
  while(x>0){
      s+=x%10;
      x=x/10;
  }
  return s;
}

int main(void){
  int i,n,m,min=100,s=0;
  scanf("%d",&n);
  m=n/2;
  for(i=1;i<=m;i++){
    s=digit_sum(i)+digit_sum(n-i);
    if(s<min){
      min=s;
    }
    s=0;
  }
  printf("%d\n",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^