#include <stdio.h>

int main() {
  int seconds_input, hours, minutes, seconds;
  scanf("%d", &seconds_input);
  hours = seconds_input / 3600;
  minutes = (seconds_input % 3600) / 60;
  seconds = seconds_input % 60;
  printf("%02d:%02d:%02d\n", hours, minutes, seconds);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &seconds_input);
   ^