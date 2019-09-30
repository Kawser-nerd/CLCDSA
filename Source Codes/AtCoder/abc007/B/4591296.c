#include<stdio.h>
#include<string.h>

int main(void)
{
  char str[11]={'\0'};
  scanf("%s",str);
  if(strlen(str)==1&&str[0]=='a')
    {
      printf("-1\n");
    }else{
    printf("a\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^