#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int n, i;
  int ans = 0;

  scanf("%d", &n);

  int a[n];

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  for(i = 0; i < n; i++){
    while(a[i] > 0){
      if((a[i] % 2 == 1) && (a[i] % 3 != 2)){
	break;
      }else{
	a[i]--;
	ans++;
      }
    }
  }

  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^