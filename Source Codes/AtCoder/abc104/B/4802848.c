#include <stdio.h>
#include <string.h>

#define MAX 10

int main()
{
  char s[MAX + 1];
  int i, c_number, c_count = 0;
  
  memset(s, '\0', sizeof(s));

  scanf("%s", s);

  if (s[0] != 'A') {
    printf("WA\n");
    return 0;
  }

  for (i = 2; i <= strlen(s) - 2; i++) {
    if (s[i] == 'C') {
      c_number = i;
      c_count++;
    }
  }

  if (c_count != 1) {
    printf("WA\n");
    return 0;
  }

  for (i = 1; i < strlen(s); i++) {
    if (i == c_number) continue;
    if (s[i] < 'a' || 'z' < s[i]) {
      printf("WA\n");
      return 0;
    }
  }

  printf("AC\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^