# include <stdio.h>

int main(){
  int a,b,x;
  scanf("%d %d %d",&a,&b,&x);
  if(x>a+b||x<a) puts("NO");
  else if(x-a<=b) puts("YES");
  else puts("NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&x);
   ^