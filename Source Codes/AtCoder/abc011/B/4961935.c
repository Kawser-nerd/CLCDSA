#include <stdio.h>

int main() {
  int i, difference = 'a' - 'A';
  char name[13];
  scanf("%s", name);
  if('a' <= name[0] && name[0] <= 'z') {
    name[0] -= difference;
  }

  for(i = 1; i < strlen(name); i++) {
    if('A' <= name[i] && name[i] <= 'Z') {
      name[i] += difference;
    }
  }

  printf("%s\n", name);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:18: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
   for(i = 1; i < strlen(name); i++) {
                  ^
./Main.c:11:18: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:11:18: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", name);
   ^