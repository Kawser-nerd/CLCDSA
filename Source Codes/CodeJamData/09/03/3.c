#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s = "#welcome to code jam";
int len = 19;

const int MOD = 10000;

int n;
int pd[20];
char *line;

int main() {
  int nt, i,j;

  scanf(" %d", &n);
  for(nt=1 ; nt<=n ; nt++) {
    scanf(" %a[^\r\n]", &line);

    memset(pd, 0, sizeof(pd));
    pd[0] = 1;

    for(i=0 ; line[i]!='\0' ; i++)
      for(j=len ; j>0 ; j--)
	if(line[i] == s[j])
	  pd[j] = (pd[j]+pd[j-1]) % MOD;

    printf("Case #%d: %04d\n", nt, pd[len]);

    free(line);
  }

  return 0;
}
