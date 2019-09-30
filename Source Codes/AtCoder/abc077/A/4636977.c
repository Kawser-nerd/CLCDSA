#include<stdio.h>

int main(){
  char c1[3],c2[3];
  scanf("%s", c1);
  scanf("%s", c2);
  
  if(c1[0]==c2[2] && c1[1]==c2[1] && c1[2]==c2[0]) printf("YES");
else printf("NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", c1);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", c2);
   ^