#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void * a, const void * b)
{
	return ((int)*(char*)a)-(int)*(char*)b;
}

char s[30];

int main()
{
	int i,n,itc=1,j,m;
	char sw;
  	scanf("%d",&i);
	while (scanf("%s",s)==1)
	{
		n=strlen(s);
		for (i=n-1;i>0;--i)
		{
			if (s[i-1]<s[i]) break;
		}
		if (i==0)
		{
			s[n]='0';
			s[n+1]=0;
			qsort(s,n+1,sizeof(char),cmp);
			i=0;
			while (s[i]=='0') ++i;
			s[0]=s[i];
			s[i]='0';
		} else
		{
			m=i;
			for (j=i+1;j<n;++j) if (s[j]>s[i-1] && s[j]<s[m]) m=j;
			sw=s[i-1];
			s[i-1]=s[m];
			s[m]=sw;
			qsort(s+i,n-i,sizeof(char),cmp);
		}
		printf("Case #%d: %s\n",itc++,s);
	}
  	return 0;
}
