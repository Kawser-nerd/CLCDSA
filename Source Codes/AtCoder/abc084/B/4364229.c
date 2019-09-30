#include <stdio.h>
#include <math.h>
int main(void){
  int a,b;
  scanf("%d %d",&a,&b);
  char s[12];
  scanf("%s",s);
  if(s[a]!='-'){printf("No");return 0;}
  for(int i=0;i<a+b;i++){
    if(i!=a&&s[i]=='-') {printf("No");return 0;}
  }
  printf("Yes");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^