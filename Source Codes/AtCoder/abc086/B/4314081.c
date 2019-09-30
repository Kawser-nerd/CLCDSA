#include<stdio.h>
#include<math.h>

int main(){
  char buf[2][256];
  scanf("%s %s",buf[0],buf[1]);
  
  char a[256];
  
  sprintf(a,"%s%s\0",buf[0],buf[1]);
  
  double aa;
  aa = (double)(sqrt(atoi(a)))-(int)(sqrt(atoi(a)));
  if(aa == 0)
    puts("Yes");
  else
    puts("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:13: warning: embedded ‘\0’ in format [-Wformat-contains-nul]
   sprintf(a,"%s%s\0",buf[0],buf[1]);
             ^
./Main.c:13:22: warning: implicit declaration of function ‘atoi’ [-Wimplicit-function-declaration]
   aa = (double)(sqrt(atoi(a)))-(int)(sqrt(atoi(a)));
                      ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",buf[0],buf[1]);
   ^