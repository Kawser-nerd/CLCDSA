#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
  char str[201];
  scanf("%s", str);
  
  int l = strlen(str);
  
  for(int i = 1; i < l/2; i++){
   char a[100] = {}; char b[100] = {};
    strncpy(a, str + 0, l/2 - i);
    strncpy(b, str + (l/2 - i ), l/2 - i);
    if(strcmp(a,b) == 0) {
      printf("%d\n", l - 2*i);
      break;
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str);
   ^