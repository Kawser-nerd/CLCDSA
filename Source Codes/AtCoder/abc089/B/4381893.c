#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int n,i;
  char s;
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%c",&s);
    if(s=='Y') {
      printf("Four");
      return 0;
    }
  }
  printf("Three");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c",&s);
     ^