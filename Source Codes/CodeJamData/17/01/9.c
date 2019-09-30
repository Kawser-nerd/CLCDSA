#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a,b[100],k;
	char s[1001];
	for(int i=0; i<n; i++)
	{
		scanf("%s %d",s, &a);
		
		b[i]=0;
		for(int j=0; s[j]!='\0'; j++)
		{
			if(s[j]=='-')
			{
				b[i]++;
				for(k=0; k<a; k++)
				{
					if(s[j+k]=='\0')
					{
						b[i]=-1;
						break;
					}
					if(s[j+k]=='+')
						s[j+k]='-';
					else
						s[j+k]='+';
				}
				if(b[i]==-1)
					break;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		if(b[i]==-1)
			printf("Case #%d: %s\n",i+1,"IMPOSSIBLE");
		else
			printf("Case #%d: %d\n",i+1,b[i]);
	}

}