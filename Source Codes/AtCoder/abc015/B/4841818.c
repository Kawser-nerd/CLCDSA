#include <stdio.h>

int main() {
  int number_of_softwares, counter = 0, softwares_i, temp_bug, sum_bug = 0, ave_bug;
  scanf("%d", &number_of_softwares);
  for(softwares_i = 0; softwares_i < number_of_softwares; softwares_i++) {
    scanf("%d", &temp_bug);
    if(temp_bug == 0) {
      continue;
    }
    counter++;
    sum_bug += temp_bug;
  }
  ave_bug = (sum_bug % counter == 0)? sum_bug / counter : sum_bug / counter + 1;
  printf("%d\n", ave_bug);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &number_of_softwares);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &temp_bug);
     ^