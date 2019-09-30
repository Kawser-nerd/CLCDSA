#include <stdio.h>

char S[100000];

void Do(int N){
  int i;
  int s[32];
  long long c;
  scanf("%s", S);
  c = 1;
  for(i = 0;i <= 'z' - 'a';i++) s[i] = 0;
  for(i = 0;i < N;i++) s[S[i]-'a']++;
  for(i = 0;i <= 'z' - 'a';i++) c = c * (s[i] + 1) % ((long long) (1e9 + 7));
  printf("%lld\n", (c - 1) % ((long long) (1e9 + 7)));  
}

int main(void){
  int N;
  scanf("%d", &N);
  Do(N);
  return 0;
} ./Main.c: In function ‘Do’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^
./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^