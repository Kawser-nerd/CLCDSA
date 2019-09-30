#include <stdio.h>
#include <string.h>
int main() {
  int input;
  scanf("%d",&input);
  int a = input / 100;
  int c = input % 10;
  int b = (input - (100*a + c))/10;
  int box[4];
  box[0] = a;
  box[1] = b;
  box[2] = c;
  int i;
  for (i = 0; i < 3; ++i) {
    if (box[i] == 1) {
      box[i] = 9;
    } else if (box[i] == 9) {
      box[i] = 1;
    }
  }
  int output = 100*box[0] + 10*box[1] + box[2];
  printf("%d\n",output);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&input);
   ^