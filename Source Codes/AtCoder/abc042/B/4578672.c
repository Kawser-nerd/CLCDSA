#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qsort_compare(const void *a, const void *b)
{
  return strcmp(a, b);
}

int main()
{
  int N, L;
  char s[100][101] = {{0}};

  scanf("%d%d", &N, &L);

  for(int cnt = 0; cnt < N; cnt++){
    scanf("%s", s[cnt]);
  }

  qsort(s, N, sizeof(s[0]), qsort_compare);

  for(int cnt = 0; cnt < N; cnt++){
    printf("%s", s[cnt]);
  }  

  printf("\n");
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &L);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[cnt]);
     ^