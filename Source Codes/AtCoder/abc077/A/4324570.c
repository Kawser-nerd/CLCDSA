#include <stdio.h>
int main(void){
char a[4],b[4];
  scanf("%s",&a);
    scanf("%s",&b);
  if(a[0]==b[2]&&a[2]==b[0]&&a[1]==b[1]){printf("YES");}
else{printf("NO");}
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
   scanf("%s",&a);
         ^
./Main.c:5:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
     scanf("%s",&b);
           ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&a);
   ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&b);
     ^