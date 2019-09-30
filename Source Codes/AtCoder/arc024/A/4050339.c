#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int L, R, i, j;
  int ans = 0;

  scanf("%d%d", &L, &R);

  int l[L], r[R];

  for(i = 0; i < L; i++){
    scanf("%d", &l[i]);
  }
  for(i = 0; i < R; i++){
    scanf("%d", &r[i]);
  }

  for(i = 0; i < L; i++){
    for(j = 0; j < R; j++){
      if(l[i] == r[j]){
	ans++;
	r[j] = 0;
	break;
      }
    }
  }

  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &L, &R);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &l[i]);
     ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &r[i]);
     ^