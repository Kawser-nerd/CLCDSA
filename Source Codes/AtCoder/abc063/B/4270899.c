#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[27];
	scanf("%s",s);
	int len=strlen(s);
	fprintf(stderr,"%s\n",s);
	int i,j,c;
	for(i=0;i<=len-1;i++)
		{
		c=s[i];
		fprintf(stderr,"%c",c);
		}
	
	fprintf(stderr,"\n");
	
	int check=1;
	for(i=0;i<=len-1;i++)
		{
		for(j=i+1;j<=len-1;j++)
			{
			if(s[i]==s[j]){check=0; printf("no"); break;}
			}
		if(check==0){break;}
		}
	if(check==1){printf("yes");}


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^