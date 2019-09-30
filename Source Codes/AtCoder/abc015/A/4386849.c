#include <stdio.h>
int main(void){
  char a[51],b[51];
  int i=0;
  int j=0;
  scanf("%s",a);
  scanf("%s",b);
  while(a[i]!='\0'){
    i++;
  }
  while(b[j]!='\0'){
    j++;
  }
  if(i>j) printf("%s\n",a);
  if(i<j) printf("%s\n",b);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",b);
   ^