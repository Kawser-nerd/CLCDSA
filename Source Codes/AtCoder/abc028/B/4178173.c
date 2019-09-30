#include<stdio.h>

int main(){
  int len = 0, c[6] = {0}, i;
  char s[100];
  
  scanf("%s", s);
  
  while(s[len]){
    if(s[len] == 'A'){
      c[0]++;
    }
    if(s[len] == 'B'){
      c[1]++;
    }
    if(s[len] == 'C'){
      c[2]++;
    }
    if(s[len] == 'D'){
      c[3]++;
    }
    if(s[len] == 'E'){
      c[4]++;
    }
    if(s[len] == 'F'){
      c[5]++;
    }
    len++;
  }
  printf("%d", c[0]);
  for (i = 1; i < 6; i++){
    printf(" %d", c[i]);
  }
  printf("\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^