#include <stdio.h>
#include <string.h>
#include <malloc.h>
void main()
{
	int cases;
	char *str = (char *)malloc(sizeof(char)*1001);
	char *str2 = (char *)malloc(sizeof(char)*2002);
	char *p1,*p2;
	scanf("%d",&cases);
	int n = 0;
	int i;
	while(n<cases)
	{
		n++;
		printf("Case #%d: ",n);
		scanf("%s",str);
		p1=&str2[1001];
		p2=p1;
		for(i=0;i<strlen(str);i++)
		{
			if(i==0)
			{
				*p2=str[i];
				p2++;
			}
			else
			{
				if(str[i]<*p1)
				{
					*p2=str[i];
					p2++;
				}
				else
				{
					p1--;
					*p1 = str[i];
				}
			}
		}
		*p2='\0';
		printf("%s\n",p1);
	}
}
