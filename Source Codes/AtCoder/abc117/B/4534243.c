#include <stdio.h>

int main() {
  int N, i, max = 0, others = 0;
  int line[11];
  scanf("%d", &N);
  for(i = 0; i < N; i++) {
    scanf("%d", &line[i]);
    if(max < line[i]) {
      max = line[i];
    }
    others += line[i];
  }
  others -= max;
  if(max < others) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &line[i]);
     ^