#include <stdio.h>
#include <string.h>
int main(){
  char a[11], b[11], c[11];

  scanf("%s%s%s", a, b, c);

  if(a[strlen(a) - 1] == b[0] && b[strlen(b) - 1] == c[0]){
    printf("YES");
  }else{
    printf("NO");
  }

  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s%s", a, b, c);
   ^