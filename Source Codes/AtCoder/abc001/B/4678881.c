#include <stdio.h>

int main() {
  int meter, VV;
  scanf("%d", &meter);
  if(meter < 100) {
    VV = 0;
  } else if(100 <= meter && meter <= 5000) {
    VV = meter / 100;
  } else if(6000 <= meter && meter <= 30000) {
    VV = meter /1000 + 50;
  } else if(35000 <= meter && meter <= 70000) {
    VV = (meter - 30000) / 5000 + 80;
  } else if(70000 < meter) {
    VV = 89;
  }
  printf("%02d\n", VV);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &meter);
   ^