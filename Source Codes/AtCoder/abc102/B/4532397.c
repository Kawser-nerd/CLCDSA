#include <stdio.h>

int main(){
  int N;scanf("%d",&N);
  int a[N];
  int max=0,min=1e10;
  for(int i=0;i<N;i++){
    scanf("%d",&a[i]);
    if(max<a[i]) max=a[i];
    if(min>a[i]) min=a[i];
  }
  printf("%d",max-min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:17: warning: overflow in implicit constant conversion [-Woverflow]
   int max=0,min=1e10;
                 ^
./Main.c:4:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   int N;scanf("%d",&N);
         ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^