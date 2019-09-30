#include<stdio.h>
#include<string.h>
char a[101];
int b;

int main(void)
{
  int i,len;
  scanf("%s",a);
  scanf("%d",&b);
  len=strlen(a);
  for(i=0;i<len;i++)
  {
    if(i+1==b)
    {
      printf("%c\n",a[i]);
      break;
    }
    else if('1'!=a[i])
    {
      printf("%c\n",a[i]);
      break;
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^