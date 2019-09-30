#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int N, A, B, i;
  int t = 0;

  scanf("%d%d%d", &N, &A, &B);

  char s[N][8];
  int d[N];

  for(i = 0; i < N; i++){
    scanf("%s %d", s[i], &d[i]);
    if(d[i] < A){
      d[i] = A;
    }else if(d[i] > B){
      d[i] = B;
    }
    if(strcmp("East", s[i]) == 0){
      t += d[i];
    }else{
      t -= d[i];
    }
  }

  if(t > 0){
    printf("East %d\n", t);
  }else if(t < 0){
    printf("West %d\n", abs(t));
  }else{
    printf("0\n");
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &N, &A, &B);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %d", s[i], &d[i]);
     ^