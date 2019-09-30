#include <stdio.h>
#include <stdlib.h>

int main() {
  char *a = malloc(sizeof(char) * 5);
  char *b = malloc(sizeof(char) * 5);
  char *c = malloc(sizeof(char) * 5);
  char *x = malloc(sizeof(char) * 7);
  int na, nb, nc, nx;
  
  fgets(a, 4, stdin);
  fgets(b, 4, stdin);
  fgets(c, 5, stdin);
  fgets(x, 6, stdin);

  na = atoi(a);
  nb = atoi(b);
  nc = atoi(c);
  nx = atoi(x);
  
  int n = 0;
  
  for(int i = 0; i <= na; i++) {
    for(int j = 0; j <= nb; j++ ) {
      for(int k = 0; k <= nc; k++) {
	if((500*i) + (100*j) + (50*k) == nx)
	  n++;
      }
    }
  }

  printf("%d\n", n);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(a, 4, stdin);
   ^
./Main.c:12:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(b, 4, stdin);
   ^
./Main.c:13:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(c, 5, stdin);
   ^
./Main.c:14:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(x, 6, stdin);
   ^