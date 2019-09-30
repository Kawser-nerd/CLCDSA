#define LENGTH 31
#include <stdio.h>

int main() {
  char phrase[LENGTH], ans[LENGTH];
  int i, count = 0;
  scanf("%s", phrase);
  for(i = 0; i < LENGTH; i++) {
    if((phrase[i] != 'a') && (phrase[i] != 'i') && (phrase[i] != 'u') && (phrase[i] != 'e') && (phrase[i] != 'o')) {
      ans[count] = phrase[i];
      count++;
    }
  }
  printf("%s\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", phrase);
   ^