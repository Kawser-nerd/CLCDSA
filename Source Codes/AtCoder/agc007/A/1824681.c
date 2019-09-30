#include <stdio.h>
int main() {
  int h,w,x=0,i,j;
  char a[8][9];
  scanf("%d %d",&h,&w);
  for (i=0;i<h;i++) {
    scanf("%s",a[i]);
  }
  for (i=0;i<h;i++) {
    for (j=0;j<w;j++) {
      if (a[i][j]=='#') {
        x++;
      }
    }
  }
  if (x==h+w-1) {
    printf("Possible\n");
  } else {
    printf("Impossible\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a[i]);
     ^