#include <stdio.h>

int main(void) {
  int N,i,j,a[21],buka[20][21],bukan[21],box[21],b,c,max,min;
  scanf("%d",&N);
  for (i = 1;i < N;i++) {
    scanf("%d",&a[i]);
  }
  for (i = 0;i < N;i++) {
    bukan[i] = 0;
    b = 0;
    box[i] = 1;
    for (j = 1;j < N;j++) {
      if(a[j] == i + 1) {
        buka[i][b] = j;
        bukan[i]++;
        b++;
      }
    }
  }
  for (i = N - 1;i > -1;i--) {
    if(bukan[i] == 0) continue;
    c = buka[i][0];
    min = box[c];
    max = box[c];
    if(bukan[i] > 1){
      for (j = 1;j < bukan[i];j++) {
        c = buka[i][j];
        if(box[c] > max) {
          max = box[c];
        } else if (box[c] < min) {
          min = box[c];
        }
      }
    }
    box[i] = min + max + 1;
  }

  printf("%d\n",box[0]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^