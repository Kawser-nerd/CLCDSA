#include<stdio.h>
#include<string.h>
int main(void){
  int i,p=0;
  char s[100001];
  scanf("%s",s);
  for(i=0;s[i]!='\0';i++)if(s[i]=='p')p++;
  printf("%d",strlen(s)/2-p);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘size_t {aka long unsigned int}’ [-Wformat=]
   printf("%d",strlen(s)/2-p);
          ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^