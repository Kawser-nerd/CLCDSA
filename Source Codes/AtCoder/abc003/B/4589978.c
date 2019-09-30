#include<stdio.h>
#include<string.h>

int main(void)
{
  char str1[11]={'\0'};
  char str2[11]={'\0'};
  int i;

  scanf("%s",str1);
  scanf("%s",str2);

  for(i=0;i<11;i++)
    {
      if(str1[i]=='@')
	{
	if(str2[i]=='a'||str2[i]=='t'||str2[i]=='c'||str2[i]=='o'||
	   str2[i]=='d'||str2[i]=='e'||str2[i]=='r')
	  {
	    str1[i]=str2[i];
	  }
	}
      if(str2[i]=='@')
	{
	if(str1[i]=='a'||str1[i]=='t'||str1[i]=='c'||str1[i]=='o'||str1[i]=='d'||str1[i]=='e'||str1[i]=='r')
	  {
	    str1[i]=str2[i];
	  }
	}
    }
  if(strcmp(str1,str2)==0) {
      printf("You can win\n");
  }else{
    printf("You will lose\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str1);
   ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str2);
   ^