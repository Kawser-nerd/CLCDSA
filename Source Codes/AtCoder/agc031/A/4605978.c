#include <stdio.h>
#include <stdint.h>


int main(void) {
  int N;
  scanf("%d", &N);

  int S_NUM[26];
  for(int i = 0; i < 26; i++) {
    S_NUM[i] = 0;
  }

  char S[100000];
  scanf("%s", S);
  for(int i = 0; i < N; i++) {
    S_NUM[S[i] - 'a']++;
  }

  uint64_t SUM = 1;
  for(int i = 0; i < 26; i++) {
    SUM = SUM * (S_NUM[i] + 1) % (1000000000+7);
  }
  SUM--;
  printf("%ld\n", SUM);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^