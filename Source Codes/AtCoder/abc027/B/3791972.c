#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int N, i;
  int sum = 0;
  int ave, sa = 0;
  int ans = 0;

  scanf("%d", &N);

  int a[N];

  for(i = 0; i < N; i++){
    scanf("%d", &a[i]);
    sum += a[i];
  }

  if(sum % N != 0){
    printf("-1\n");
  }else{
    ave = sum / N;
    for(i = 0; i < N; i++){
      sa += a[i] - ave;
      if(sa != 0){
	ans++;
      }
    }
    printf("%d\n", ans);
  }
 
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^