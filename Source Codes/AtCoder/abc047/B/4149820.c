#include <stdio.h>

int main(void){
  int w, h, n;
  scanf("%d %d %d", &w, &h, &n);
  int m[n][3];
  for(int i = 0; i < n; i++){
    scanf("%d %d %d", &m[i][0], &m[i][1], &m[i][2]);
  }
  int mw = 0;
  int mh = 0;
  for(int i = 0; i < n; i++){
    switch(m[i][2]){
    case 1:
      if(m[i][0] > mw) mw = m[i][0];
      break;
    case 2:
      if(m[i][0] < w) w = m[i][0];
      break;
    case 3:
      if(m[i][1] > mh) mh = m[i][1];
      break;
    default:
      if(m[i][1] < h ) h = m[i][1];
      break;
    }
  }
  w -= mw;
  h -= mh;
  if(w < 0) w = 0;
  if(h < 0) h = 0;
  printf("%d\n", w * h);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &w, &h, &n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &m[i][0], &m[i][1], &m[i][2]);
     ^