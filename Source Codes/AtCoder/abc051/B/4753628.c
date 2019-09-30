#include <stdio.h>

int main()
{
  int k,s;
  scanf("%d %d", &k, &s);
  int sum=0;
  for(int i=0;i<=k;i++){
    for(int j=0;j<=k ;j++){
      if(0 <= s-i-j && s-i-j <= k)
        sum++;
    }
  }
  printf("%d", sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &k, &s);
   ^