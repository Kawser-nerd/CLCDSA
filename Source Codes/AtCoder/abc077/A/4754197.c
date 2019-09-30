#include <stdio.h>

int main(){
  char a[3],b[3];
  int i, flag = 1;
  scanf("%s %s",a,b);
  
  for(i=0;i<3;i++){
  	if(a[i] != b[2-i]) flag = 0;
  }
  if(flag == 0) printf("NO\n");
  else printf("YES\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",a,b);
   ^