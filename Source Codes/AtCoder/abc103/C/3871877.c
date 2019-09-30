#include <stdio.h>

int main(){
  int n,a,sum=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
	scanf("%d",&a);
    sum+=a-1;
  }
  printf("%d",sum);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^