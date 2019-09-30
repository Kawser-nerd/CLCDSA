#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int l[n];
  int sum = 0;
  for(int i = 0; i < n; ++i){
    scanf("%d",&l[i]);
    sum += l[i];
  }
  int flag = 0;
  for(int i = 0; i < n; ++i){
    if(sum <= 2*l[i]) flag = 1;
  }
  if(flag == 0) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&l[i]);
     ^