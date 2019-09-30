#include<stdio.h>
#include<string.h>

int main()
{
	int x,temp,k,j,i,m;
	char s[100];
	char t[100];
	while(scanf("%s%s",s,t)!=EOF)
	{
		x=strlen(s);
		
			for(i=0;i<x;i++)
			{
				temp=s[x-1];
				for(j=x-1;j>=0;j--)
				{
					s[j]=s[j-1];
					if(j==0)
					{
						s[j]=temp;
					}
					
				}
				if(strcmp(s,t)==0)
				{
					printf("Yes\n");
					break;
				}
			}
			//printf("%s\n",s);
			if(i>=x)
			{
				printf("No\n");	
			}
		
	}
	return 0;
	
}