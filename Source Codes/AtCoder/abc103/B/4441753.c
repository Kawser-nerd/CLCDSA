#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char s[1000];
  char t[1000];
  char kari;

  if(scanf("%s %s", s, t) == 1);

  for(int i = 0; i < strlen(s); i++) {
    if(strcmp(s, t) == 0) {
      break;
    } else if(i == strlen(s) - 1) {
      printf("No");
      return 0;
    }
    kari = s[0];
    for(int i = 0; i < strlen(s) - 1; i++) {
      s[i] = s[i+1];
    }
    s[strlen(s) - 1] = kari;
  }

  printf("Yes");

  return 0;
}