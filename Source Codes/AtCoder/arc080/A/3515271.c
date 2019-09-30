#include <stdio.h>

int main(){
  int n,i,a[100001],odd=0,four=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
      if(a[i]%2==1){
          odd++;
      }else
          if(a[i]%4==0){
              four++;
          }
  }
  if(odd==0||(odd-1<=four&&n%2==1)||(odd<=four&&n%2==0))
  printf("Yes");
  else printf("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a[i]);
       ^