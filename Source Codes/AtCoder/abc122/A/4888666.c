#include <stdio.h>
#include <string.h>

int main(void){
  char salt[10];
  char A = 'A', C = 'C', G = 'G', T = 'T';
  salt[0] = getchar();
  if(salt[0] == 'A'){
    printf("T");
  } else if(salt[0] == 'C'){
    printf("G");
  } else if(salt[0] == 'G'){
    printf("C");
  } else {
    printf("A");
  }
  return 0;
}