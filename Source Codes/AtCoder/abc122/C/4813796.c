#include <stdio.h>
int main(void) {
   int N;
   int Q;
   scanf("%d%d", &N, &Q);
   char S[100001];
   int accumulate[100001] = {0};
   scanf("%s", S);
   int cnt = 0;
   for (int i = 0; i < N; i++) {
      if (S[i] == 'A' && S[i+1] == 'C') {
         cnt++;
      }
      accumulate[i+1] = cnt;
   }

   for (int i = 0; i < Q; i++) {
      int l1;
      int l2;
      scanf("%d%d", &l1, &l2);
      printf("%d\n",accumulate[l2 - 1] - accumulate[l1 - 1]);
   }
} ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d", &N, &Q);
    ^
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s", S);
    ^
./Main.c:20:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d", &l1, &l2);
       ^