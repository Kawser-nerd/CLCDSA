#include <stdio.h>
int main(void) {
  int h,w,i;
  char a[111];
  scanf("%d%d",&h,&w);
  for(i=0;i<=w+1;i++) {
    printf("#");
  }
  printf("\n");
  for(i=0;i<h;i++) {
    scanf("%s",a);
    printf("#%s#\n",a);
  }
  for(i=0;i<=w+1;i++) {
    printf("#");
  }
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",a);
     ^