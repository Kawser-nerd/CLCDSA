#include <stdio.h>
#include <stdbool.h>
#define MAX 1000000

bool dbl(int *a, int len) {
  int i;
  for(i = 0; i < len-1; ++i) {
	if(a[i] == a[len-1]) { return true; }
  }
  return false;
}

int main(void)
{
  int s, len = 0, a[MAX];
  scanf("%d", &s);
  a[len] = s; ++len;
  while(true) {
    if(a[len-1]%2 == 0) { a[len] = a[len-1]/2; ++len; }
    else { a[len] = 3*a[len-1] + 1; ++len; }
    if(dbl(a, len)) { break; }
    if(len >= 1000000) { break; }
  }
  //int i;
  //for(i = 0; i < len; ++i) {
  //  printf(" %d", a[i]);
  //}
  //printf("\n");
  printf("%d\n", len);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &s);
   ^