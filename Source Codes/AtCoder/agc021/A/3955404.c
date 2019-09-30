#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  char N[32];
  int len, i;
  int k = 0;

  scanf("%s", N);

  len = strlen(N);

  for(i = 0; i < len; i++){
    if(N[i] == '9'){
      k++;
    }
  }

  if(k == len){
    printf("%d\n", 9 * len);
  }else if(k == len - 1 && N[0] != '9'){
    printf("%d\n", (9 * (len - 1)) + (N[0] - '1' + 1));
  }else{
    printf("%d\n", (9 * (len - 1)) + (N[0] - '1'));
  }
	  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", N);
   ^