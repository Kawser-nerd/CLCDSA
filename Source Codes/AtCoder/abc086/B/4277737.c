#include<stdio.h>
#include<math.h>

int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  b+=a*(10+(b/10>0)*90+(b/100)*900);
  puts(sqrt(b)-(int)sqrt(b)?"No":"Yes");
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^