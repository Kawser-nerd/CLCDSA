#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  char s[12];
  int len, count = 0;

  if(scanf("%s", s) == 1);

  len = strlen(s);

  if(s[0] == 'A' && islower(s[1]) && islower(s[len-1])) {
    for(int i = 2; i < len; i++) {
      if(i == len - 1) {
        if(isupper(s[i])) {
          printf("WA");
          return 0;
        }
      } else if(s[i] == 'C') {
        if(count == 1) {
          printf("WA");
          return 0;
        }
        count++;
      } else if(isupper(s[i])) {
        printf("WA");
        return 0;
      }
    }
  } else {
    printf("WA");
    return 0;
  }

  if(count == 0) {
    printf("WA");
    return 0;
  }

  printf("AC");

  return 0;
}