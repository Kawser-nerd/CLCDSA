#include <stdio.h>

int main(void)
{
  int N;
  char S[110];
  
  scanf("%d %s", &N, S);
  
  if(N % 2 == 0) {
    printf("-1\n");
    return 0;
  }
  int cnt = 0;
  int mid = (N - 1) / 2;
  int l = mid - 1, r = mid + 1;
  while(0 <= l && r < N) {
    cnt++;
    if((cnt % 3 == 0 && !(S[l] == 'b' && S[r] == 'b'))
       || (cnt % 3 == 1 && !(S[l] == 'a' && S[r] == 'c'))
       || (cnt % 3 == 2 && !(S[l] == 'c' && S[r] == 'a'))) {
      printf("-1\n");
      return 0;
    }
    l--;
    r++;
  }
  printf("%d\n", cnt);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %s", &N, S);
   ^