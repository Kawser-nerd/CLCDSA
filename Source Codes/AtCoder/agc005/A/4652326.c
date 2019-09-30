#include <stdio.h>
#include <string.h>

int main(void) {
  char X[200010];
  int i, len, s, t, u;
  scanf("%s", &X);
  len = strlen(X);
  
  s = 0; u = 0;
  for (i=0;i<len;i++) {
    if (X[i] == 'S') s++;
    else if (s>0) s--;
    else u++;
  }
  u += s;
  printf("%d\n", u);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[200010]’ [-Wformat=]
   scanf("%s", &X);
         ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &X);
   ^