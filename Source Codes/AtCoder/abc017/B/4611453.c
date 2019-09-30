#include<stdio.h>
#include<string.h>

int main(void)
{
  char str[51]={'\0'};
  int len;
  int i;

  scanf("%s",str);
  len=strlen(str);

  for(i=0;i<len;i++)
    {
      if(str[i]!='c'&&str[i]!='h'&&str[i]!='o'&&str[i]!='k'&&str[i]!='u'){
	printf("NO\n");
	break;
      }else if((str[i]=='c'&&str[i+1]!='h')||(str[i-1]!='c'&&str[i]=='h')){
	printf("NO\n");
	break;
      }else if(i==len-1){
	printf("YES\n");
      }
    }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^