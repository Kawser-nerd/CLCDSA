#include <stdio.h>
#include <inttypes.h>
#include <string.h>
char S[20];
int main()
{
  int nt; scanf("%i", &nt);
  for(int t = 1; t <= nt; t++) {
    scanf("%s", S);
    int n = strlen(S);
    int last = n;
    for(int i = n-2; i >= 0; i--)
      if(S[i] > S[i+1]) {
        S[i] = S[i]-1;
        last = i+1;
      }
    for(int i = last; i < n; i++)
      S[i] = '9';

    char* res = S;
    while(*res=='0') res++;
    printf("Case #%i: %s\n", t, res);
  }
  return 0;
}
