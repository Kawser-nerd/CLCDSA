#include <stdio.h>
#define MAX(A, B) (((A) < (B)) ? (B) : (A))
#define MIN(A, B) (((A) < (B)) ? (A) : (B))

int main() {
  int N;
  scanf("%d", &N);
  char s[N];
  int a[4] = {0};
  scanf("%s", &s);
  for (int i=0; i<N; i++)
    a[s[i] - '1']++;
  
  int min=a[0];
  int max=a[0];
  for (int i=1; i<4; i++) {
    max = MAX(max, a[i]);
    min = MIN(min, a[i]);
  }
  
  printf("%d %d\n", max, min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[(sizetype)(N)]’ [-Wformat=]
   scanf("%s", &s);
         ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &s);
   ^