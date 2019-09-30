#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

int main(void) {
  int a, b, c, k;

  if(scanf("%d %d %d %d %d", &a, &b, &c, &k) == 1);

    for(int i = 0; i < k; i++) {
      if(b <= a && c <= a) {
        a *= 2;
      } else if(a <= b && c <= b) {
        b *= 2;
      } else {
        c *= 2;
      }
    }



  printf("%d", a + b + c);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:12: warning: format ‘%d’ expects a matching ‘int *’ argument [-Wformat=]
   if(scanf("%d %d %d %d %d", &a, &b, &c, &k) == 1);
            ^