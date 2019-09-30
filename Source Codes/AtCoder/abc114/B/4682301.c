#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char S[10];
  scanf("%s",S);
  int len = strlen(S);
  int l=S[0]-'0',m=S[1]-'0',n=S[2]-'0';
  int min=abs((100*l+10*m+n)-753);
  for (int i = 1; i < len-2; i++) {
    int a=S[i]-'0',b=S[i+1]-'0',c=S[i+2]-'0';
    int dif=abs((100*a+10*b+c)-753);
    if (min > dif) min = dif;
  }
  printf("%d\n",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^