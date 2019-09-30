#include <stdio.h>
#include <string.h>

int main(void)
{
	int i,j;
	char s[11];
	char end[1];
	end[0]='\0';
	scanf("%s",s);
	strcat(s,end);
	for(i=0;i<=9;i++)
		{if(s[i]=='B'&& i != 0)
			{j=i;
			i-=2;
			fprintf(stderr,"i!=0?%s?",s);
			for(j;j<=9;j++)
				{
			 	 s[j-1]=s[j+1];
				 s[j]='\0';
			 	 s[j+1]='\0';
				}
			fprintf(stderr,"%s\n",s);
			}				 
		if(s[i]=='B' && i == 0)
			{j=0,i--;
			fprintf(stderr,"i==0?%s?",s);
			for(j;j<=8;j++)
				{s[j]=s[j+1];
				 s[j+1]='\0';
				}
			fprintf(stderr,"%s\n",s);
			}
		}
	printf("%s\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^