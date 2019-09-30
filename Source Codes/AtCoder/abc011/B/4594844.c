#include<stdio.h>
#include<string.h>

int main(void)
{
  char str[13];
  scanf("%s",str);
  int i;

  if(str[0]>='a'){
    str[0]=str[0]+'A'-'a';
  }

  for(i=1;i<strlen(str);i++){
     if(str[i]<='Z'){
    str[i]=str[i]+'a'-'A';
     }
  }

  printf("%s\n",str);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^