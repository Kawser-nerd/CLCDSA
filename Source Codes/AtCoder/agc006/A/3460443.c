#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  int N;
  int i, j;
  int n;
  int k = 0;

  scanf("%d", &N);

  char s[N], t[N];

  scanf("%s %s", s, t);

  for(i = 0; i < N; i++){
    n = 0;
    if(s[i] == t[0]){
      for(j = i; j < N; j++){
	if(s[j] == t[j - i]){
	  n++;
	}
      }
    }
    if(n == N - i){
      printf("%d\n", 2 * N - (N  - i));
      break;
    }
    k++;
  }

  if(k == N){
    printf("%d\n", 2 * N);
  }
    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s", s, t);
   ^