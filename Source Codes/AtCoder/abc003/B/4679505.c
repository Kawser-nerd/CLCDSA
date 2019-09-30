#define LENGTH 11
#include <stdio.h>

int check(char);

int main() {
  int i, flag = 0;
  char str_1[LENGTH], str_2[LENGTH];
  scanf("%s", str_1);
  scanf("%s", str_2);
  for(i = 0; i < LENGTH; i++) {
    if(str_1[i] == '\0' && str_2[i] == '\0') {
      break;
    }
    if(str_1[i] == str_2[i]) {
      continue;
    } else if(str_1[i] == '@') {
      flag = check(str_2[i]);
    } else if(str_2[i] == '@') {
      flag = check(str_1[i]);
    } else {
      flag = 1;
    }
    if(flag != 0) {
      break;
    }
  }
  if(flag == 0) {
    printf("You can win\n");
  } else {
    printf("You will lose\n");
  }
  return 0;
}

int check(char ch) {
  switch(ch) {
    case 'a':
    case 't':
    case 'c':
    case 'o':
    case 'd':
    case 'e':
    case 'r':
      return 0;
    default:
      return 1;
    }
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str_1);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", str_2);
   ^