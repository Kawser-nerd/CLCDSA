#include<stdio.h>
#include<string.h>
int main()
{
	char s[30];
	scanf("%s",s);
	int i,j;
	for(i=0;i<strlen(s)-1;i++)
	  for(j=i+1;j<strlen(s);j++)
	    if(s[i]==s[j])
	    {
	    	printf("no\n");
	    	return 0;
	    }
    printf("yes\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^