#include <stdio.h>

int main(void) {
  int N,x,i,j,temp,a[100],ans = 0;
  
  scanf("%d%d",&N,&x);
  for(i = 0;i < N;i++){
    scanf("%d",&a[i]);
  }
  
  for(i = 0;i < N - 1;i++) {
    for(j = 0;j <N - 1;j++) {
      if (a[j + 1] < a[j]) {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }

  for(i = 0;(x - a[i] >= 0) && (i < N -1);i++) {
    ans++;
    x = x - a[i];
  }
  if(x == a[N - 1]) ans++;
  printf("%d",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&x);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^