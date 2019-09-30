#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  char s[512];
  int k, i, j;
  int len = 0;
  int ans = 0;

  scanf("%s", s);
  scanf("%d", &k);

  while(s[len]){
    len++;
  }

  if(k > len){
    printf("0\n");
  }else{
    char t[len - k + 1][k];
    for(i = 0; i < len - k + 1; i++){
      for(j = 0; j < k; j++){
	t[i][j] = s[i + j];
      }
    }
    for(i = 0; i < len - k + 1; i++){
      int m = 0;
      int l;
      for(j = 0; j < i; j++){
	int n = 0;
	for(l = 0; l < k; l++){
	  if(t[i][l] != t[j][l]){
	    break;
	  }else{
	    n++;
	  }
	}
	if(n != k){
	  m++;
	}
      }
      if(m == i){
	ans++;
      }
    }
    printf("%d\n", ans);
  }
    
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &k);
   ^