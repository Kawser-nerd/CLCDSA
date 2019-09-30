#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int base[10], len;

int baseconv (int d, int b) {

  int invdigits[20], digits[20];
  int i, len, ans;

  if (b == 10) return d;
  i = 0;
  while (d) {
    invdigits[i] = d%b;
    d /= b;
    i++;
  }
  len = i;
  for (i=0; i<len; i++)
    digits[i] = invdigits[len-i-1];
  ans = 0;
  for (i=0; i<len; i++) {
    ans *= 10;
    ans += digits[i];
  }
  return ans;
}

int process (int d) {
  
  int i, ans, dig;

  ans = 0;
  for (i=0; d; i++) {
    dig = d%10;
    dig *= dig;
    ans += dig;
    d /= 10;
  }
  return ans;
}

int checkforbase (int x, int basei) {

  int k,  cont;
  
  k = -1;
  cont = 0;
  while (k != x && x != 1 && cont < 10) {
    //printf("%d -> ",x);
    k = x;
    x = process(baseconv(x,basei));
    //printf("%d\n",x);
    cont++;
  }
  if (x!=1) return 0;
  return 1;
}

int main () {
  
  int testcase, tc, and;
  int i, j, k;
  char str1[15], str2[4];
  int nbase;
  
  scanf("%d",&testcase);
  getchar();
  for (tc=1;tc<=testcase;tc++) {
    for (i=0;i<10;i++)
      base[i] = 0;
    scanf("%[^\n]",str1);
    getchar();
    len = strlen(str1);
    k = j = 0;
    for (i=0; i<len; i++) {
      if (str1[i] == ' ') {
	k = 0;
	base[j] = atoi(str2);
	j++;
      }
      else if (str1[i]>='0' && str1[i]<='9') {
	str2[k] = str1[i];
	str2[++k] = '\0';
      }
    }
    base[j] = atoi(str2);
    nbase = j+1;
    and = 0;
    for (i=2;i<=100000 && !and; i++) {
      and = 1;
      for (j=0;j<nbase;j++)
	and *= checkforbase(i,base[j]);
    }
    printf("Case #%d: ",tc);
    printf("%d\n",i-1);
  }
  return 0;
}
